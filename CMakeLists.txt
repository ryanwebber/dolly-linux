cmake_minimum_required(VERSION 3.16)

# Define architecture and toolchain
set(TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/toolchain.cmake" CACHE FILEPATH "Toolchain file for cross-compilation")

# Define option to skip building the userspace
option(BUILD_USER_SPACE "Build the userspace" ON)

# Load the toolchain file if provided
if(TOOLCHAIN_FILE)
    include(${TOOLCHAIN_FILE})
endif()

project(dolly-linux LANGUAGES C ASM)

message(STATUS "Using gcc toolchain: ${CMAKE_C_COMPILER}")

# Set build directories
set(BUILD_DIR ${CMAKE_BINARY_DIR}/build)
set(ISO_TARGET ${BUILD_DIR}/${ARCH}-dolly-linux.iso)
set(BOOT_FILES ${BUILD_DIR}/iso-root)
set(INITRAMFS ${BUILD_DIR}/initramfs.cpio)  
set(USERSPACE_INSTALL_DIR ${BUILD_DIR}/initramfs)
set(USERSPACE_DIR ${CMAKE_BINARY_DIR}/userspace)

# All userspace targets that install to the initramfs
set(USERSPACE_INSTALL_TARGETS
    crt0
    echo
    false
    init
    libc
    sh
    true
)

set(CMAKE_INSTALL_PREFIX ${USERSPACE_INSTALL_DIR})
Set(FETCHCONTENT_QUIET FALSE)

# Required host files
set(SYSLINUX_ELF_LOADER "/usr/lib/syslinux/modules/bios/ldlinux.c32")
set(SYSLINUX_BOOT_LOADER "/usr/lib/ISOLINUX/isolinux.bin")

if(NOT EXISTS ${SYSLINUX_ELF_LOADER})
    message(FATAL_ERROR "Syslinux ELF loader not found at ${SYSLINUX_ELF_LOADER}")
endif()

if(NOT EXISTS ${SYSLINUX_BOOT_LOADER})
    message(FATAL_ERROR "Syslinux boot loader not found at ${SYSLINUX_BOOT_LOADER}")
endif()

# External commands
find_program(GENISOIMAGE_EXECUTABLE genisoimage)
find_program(CPIO_EXECUTABLE cpio)
find_program(MAKE_EXECUTABLE make)

# Create necessary directories
file(MAKE_DIRECTORY ${BUILD_DIR} ${USERSPACE_DIR})

# Userspace build as a CMake project
add_subdirectory(userspace)

# Kernel build as a CMake project
add_subdirectory(kernel)

# Build initramfs: Install userspace binaries into temporary directory before archiving
add_custom_command(OUTPUT ${INITRAMFS}
    DEPENDS userspace ${USERSPACE_INSTALL_TARGETS}
    COMMAND ${CMAKE_COMMAND} -E make_directory ${USERSPACE_INSTALL_DIR}
    COMMAND ${CMAKE_COMMAND} --build ${USERSPACE_DIR} --target install
    COMMAND cd ${USERSPACE_INSTALL_DIR} && find . | ${CPIO_EXECUTABLE} -H newc -o > ${INITRAMFS}
    COMMENT "Building initramfs and archiving userspace"
)

add_custom_target(initramfs DEPENDS ${INITRAMFS})

# ISO build
add_custom_command(OUTPUT ${ISO_TARGET}
    DEPENDS kernel ${INITRAMFS}
    COMMAND ${CMAKE_COMMAND} -E make_directory ${BOOT_FILES}/boot/syslinux
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/config/syslinux.cfg ${BOOT_FILES}/boot/syslinux
    COMMAND ${CMAKE_COMMAND} -E copy ${SYSLINUX_ELF_LOADER} ${BOOT_FILES}/boot/syslinux
    COMMAND ${CMAKE_COMMAND} -E copy ${SYSLINUX_BOOT_LOADER} ${BOOT_FILES}/boot/syslinux
    COMMAND ${CMAKE_COMMAND} -E copy ${KERNEL_BUILD_IMAGE} ${BOOT_FILES}/boot/kernel
    COMMAND ${CMAKE_COMMAND} -E copy ${INITRAMFS} ${BOOT_FILES}/boot/initramfs
    COMMAND ${GENISOIMAGE_EXECUTABLE} -o ${ISO_TARGET} -b boot/syslinux/isolinux.bin -c boot/syslinux/boot.cat -J -r -no-emul-boot -boot-load-size 4 -boot-info-table ${BOOT_FILES}
    COMMENT "Building bootable ISO to ${ISO_TARGET}"
)

add_custom_target(iso ALL DEPENDS ${ISO_TARGET})
