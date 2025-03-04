# Set the target architecture (you could also set this in the top-level file)
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR x86_64)

set(ARCH "${CMAKE_SYSTEM_PROCESSOR}")

# Define the cross-compilation tools based on the TOOLCHAIN variable
set(TOOLCHAIN "${ARCH}-linux-gnu-")
set(TOOLCHAIN_DIR "/usr/bin")

# Set the compilers
set(CMAKE_C_COMPILER "${TOOLCHAIN_DIR}/${TOOLCHAIN}gcc")
set(CMAKE_ASM_COMPILER "${TOOLCHAIN_DIR}/${TOOLCHAIN}as")
set(CMAKE_AR "${TOOLCHAIN_DIR}/${TOOLCHAIN}ar")
set(CMAKE_LINKER "${TOOLCHAIN_DIR}/${TOOLCHAIN}ld")
