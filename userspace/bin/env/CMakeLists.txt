cmake_minimum_required(VERSION 3.16)
project(env LANGUAGES C)

set(TARGET_NAME ${PROJECT_NAME})

# Define paths and flags
set(BUILD_DIR "${CMAKE_BINARY_DIR}/build/${TARGET_NAME}" CACHE PATH "Build directory for ${TARGET_NAME}")

# Ensure build directory exists
file(MAKE_DIRECTORY ${BUILD_DIR})

# Source files
set(SRC_FILE "${CMAKE_CURRENT_SOURCE_DIR}/main.c")

# Define the source file for the application
add_executable(${TARGET_NAME} ${SRC_FILE})

# Link the application with our libc
target_link_libraries(${TARGET_NAME}
    PRIVATE
        libc
        $<TARGET_OBJECTS:crt0>
)

install(
    TARGETS ${TARGET_NAME}
    DESTINATION "usr/bin"
)
