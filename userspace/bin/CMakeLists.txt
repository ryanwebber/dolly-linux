cmake_minimum_required(VERSION 3.16)
project(bin LANGUAGES C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -nostdinc")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static -nostartfiles -nostdlib -nodefaultlibs -z noexecstack")

# Define subdirectories (each one will have its own CMakeLists.txt)
set(SUBDIRS init sh)

# Include subdirectories (each subdirectory is expected to define its own install rules)
foreach(SUBDIR ${SUBDIRS})
    add_subdirectory(${SUBDIR})
endforeach()

# Main target to build all bin components
add_custom_target(bin ALL DEPENDS ${SUBDIRS})
