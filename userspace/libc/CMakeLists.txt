cmake_minimum_required(VERSION 3.16)
project(wlibc LANGUAGES C ASM)

set(TARGET_NAME wlibc)

# Define include and source directories
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(BUILD_DIR "${CMAKE_BINARY_DIR}/build/${TARGET_NAME}" CACHE PATH "Build directory for ${TARGET_NAME}")

# Set common flags for C and ASM
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -nostdinc -Os -fno-ident -fno-asynchronous-unwind-tables -fno-stack-protector -fomit-frame-pointer")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -msyntax=intel -mnaked-reg")

# Collect source files (C and ASM)
file(GLOB SRCS_C "${SRC_DIR}/*.c")
file(GLOB SRCS_ASM "${SRC_DIR}/*.asm")
set(SRCS ${SRCS_C} ${SRCS_ASM})

# Create static library
add_library(${TARGET_NAME} STATIC ${SRCS})

# Add include directories
target_include_directories(${TARGET_NAME}
    PRIVATE
        ${SRC_DIR}
    PUBLIC
        ${INCLUDE_DIR}
)

# Set target properties
set_target_properties(${TARGET_NAME} PROPERTIES OUTPUT_NAME "wlibc")

# Install the library
install(
    TARGETS ${TARGET_NAME}
    DESTINATION "usr/lib"
)

# Install header files
install(
    DIRECTORY ${INCLUDE_DIR}/
    DESTINATION "usr/include"
)
