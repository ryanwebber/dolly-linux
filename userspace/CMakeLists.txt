cmake_minimum_required(VERSION 3.16)
project(userspace LANGUAGES C)

# Common build options
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

# Define subdirectories (each one will have its own CMakeLists.txt)
if(BUILD_USER_SPACE)
    set(SUBDIRS bin crt0 libc libm ports)
else()
    set(SUBDIRS "")
endif()

# Include subdirectories (each subdirectory is expected to define its own install rules)
foreach(SUBDIR ${SUBDIRS})
    add_subdirectory(${SUBDIR})
endforeach()

# Main target to build all userspace components
add_custom_target(userspace ALL DEPENDS ${SUBDIRS})
