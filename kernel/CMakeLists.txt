cmake_minimum_required(VERSION 3.16)
project(kernel LANGUAGES NONE)

# Ensure that when extracting files from a downloaded archive,
# we use the extraction time as the timestamp for those files,
# not the timestamp embedded in the archive.
if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
    cmake_policy(SET CMP0135 NEW)
endif()

include(FetchContent)

set(KERNEL_VERSION linux-6.13.5)
set(KERNEL_ARCH ${ARCH})
set(KERNEL_CROSS_COMPILE ${TOOLCHAIN})
set(KERNEL_URL "https://cdn.kernel.org/pub/linux/kernel/v6.x/${KERNEL_VERSION}.tar.xz")
set(KERNEL_CHECKSUM "283ecb0784f3fbc16dd822fb1d9642e230ec7515ed33f120e551b839f355e6e2")
set(KERNEL_BUILD_JOBS 4)

set(KERNEL_BUILD_IMAGE "${CMAKE_BINARY_DIR}/${KERNEL_VERSION}.bin")
set(KERNEL_BUILD_IMAGE ${KERNEL_BUILD_IMAGE} PARENT_SCOPE)

FetchContent_Declare(
    kernel_source
    URL ${KERNEL_URL}
    URL_HASH SHA256=${KERNEL_CHECKSUM}
)

FetchContent_MakeAvailable(kernel_source)

set(KERNEL_SOURCE_DIR ${kernel_source_SOURCE_DIR})
set(KERNEL_IMAGE ${KERNEL_SOURCE_DIR}/arch/${KERNEL_ARCH}/boot/bzImage)

set(LINUX_CONFIG_OPTIONS "")

add_custom_command(
    OUTPUT ${KERNEL_BUILD_IMAGE}
    COMMAND ${MAKE_EXECUTABLE} -C ${KERNEL_SOURCE_DIR} ARCH=${KERNEL_ARCH} CROSS_COMPILE=${KERNEL_CROSS_COMPILE} ${LINUX_CONFIG_OPTIONS} defconfig
    COMMAND ${MAKE_EXECUTABLE} -C ${KERNEL_SOURCE_DIR} ARCH=${KERNEL_ARCH} CROSS_COMPILE=${KERNEL_CROSS_COMPILE} -j${KERNEL_BUILD_JOBS} ${LINUX_CONFIG_OPTIONS}
    COMMAND ${CMAKE_COMMAND} -E copy ${KERNEL_IMAGE} ${KERNEL_BUILD_IMAGE}
    COMMENT "Building ${KERNEL_BUILD_IMAGE}"
    DEPENDS ${KERNEL_SOURCE_DIR}/Makefile
)

add_custom_target(
    kernel
    DEPENDS ${KERNEL_BUILD_IMAGE}
)
