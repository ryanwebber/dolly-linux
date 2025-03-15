cmake_minimum_required(VERSION 3.16)
project(ports LANGUAGES)

# Define subdirectories (each one will have its own CMakeLists.txt)
set(SUBDIRS
    lua
    )

# Include subdirectories (each subdirectory is expected to define its own install rules)
foreach(SUBDIR ${SUBDIRS})
    # Check the PORTS list variable to see if it includes the current subdirectory or 'all'
    if(${SUBDIR} IN_LIST PORTS OR PORTS STREQUAL "all")
        message(STATUS "Including port: ${SUBDIR}")
        add_subdirectory(${SUBDIR})
    endif()
endforeach()

# Main target to build all userspace components
add_custom_target(ports ALL DEPENDS ${SUBDIRS})
