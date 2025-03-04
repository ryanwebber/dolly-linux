cmake_minimum_required(VERSION 3.16)
project(crt0 LANGUAGES ASM)

set(TARGET_NAME ${PROJECT_NAME})

# Define paths and flags
set(BUILD_DIR "${CMAKE_BINARY_DIR}/build/${TARGET_NAME}" CACHE PATH "Build directory for ${TARGET_NAME}")

set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -msyntax=intel -mnaked-reg")

# Ensure build directory exists
file(MAKE_DIRECTORY ${BUILD_DIR})

# Source files
set(SRC_FILE "${CMAKE_CURRENT_SOURCE_DIR}/crt0.asm")

# Define the object file target
add_library(${TARGET_NAME} OBJECT ${SRC_FILE})

install(
    FILES $<TARGET_OBJECTS:${TARGET_NAME}>
    DESTINATION "usr/lib"
    RENAME crt0.o
)
