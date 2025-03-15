include(ExternalProject)

if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
    cmake_policy(SET CMP0135 NEW)
endif()

set(EXTERNAL_PROJECT_NAME "lua")
set(EXTERNAL_PROJECT_URL "https://www.lua.org/ftp/lua-5.4.7.tar.gz")
set(EXTERNAL_PROJECT_HASH "9fbf5e28ef86c69858f6d3d34eccc32e911c1a28b4120ff3e84aaa70cfbf1e30")
set(EXTERNAL_PROJECT_INSTALL_DIR "${CMAKE_BINARY_DIR}/external_install")

set(EXTERNAL_PROJECT_PATCH_FILE "${CMAKE_CURRENT_SOURCE_DIR}/${EXTERNAL_PROJECT_NAME}-build.patch")

# Get the include directories from the libc target
get_target_property(LIBC_INCLUDE_DIRS libc INTERFACE_INCLUDE_DIRECTORIES)
foreach(dir ${LIBC_INCLUDE_DIRS})
    string(APPEND CC_EXTRA_ARGS "-I${dir} ")
endforeach()

# Get the static library path from the libc target
get_target_property(LIBC_STATIC_LIB_DIR libc ARCHIVE_OUTPUT_DIRECTORY)
string(APPEND LD_EXTRA_ARGS "-L${LIBC_STATIC_LIB_DIR} -lc")

ExternalProject_Add(${EXTERNAL_PROJECT_NAME}
    URL ${EXTERNAL_PROJECT_URL}
    URL_HASH SHA256=${EXTERNAL_PROJECT_HASH}
    BUILD_IN_SOURCE 1
    CONFIGURE_COMMAND ""
    BUILD_COMMAND make -C src dolly CC=${CMAKE_C_COMPILER} AR=${CMAKE_AR} MYCFLAGS=${CC_EXTRA_ARGS} MYLDFLAGS=${LD_EXTRA_ARGS}
    INSTALL_COMMAND make install PREFIX=${USERSPACE_INSTALL_DIR}
    INSTALL_DIR ${EXTERNAL_PROJECT_INSTALL_DIR}
    DEPENDS libc

    # Apply local patches after the project is downloaded if they exist
    PATCH_COMMAND patch -p0 -u -N < ${EXTERNAL_PROJECT_PATCH_FILE}
)
