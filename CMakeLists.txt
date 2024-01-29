cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

# Ref:
# https://gitlab.com/christophacham/cmake-kernel-module
# https://gitioc.upc.edu/open-source/xenomai-cmake/blob/master/cmake-modules/FindKernelHeaders.cmake
# https://stackoverflow.com/questions/50877135/cmake-specify-linux-kernel-module-output-build-directory

project(dmp-task LANGUAGES C CXX)

# List driver sources
set(SOURCES entrypoint.c)

# We use gnu++17
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_EXTENSIONS ON)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Use -DARCH=.. to build against something else than x86
# Check /usr/src/linux-headers-$(uname -r)/arch for available options
if(NOT DEFINED ARCH)
    set(ARCH x86)
endif()

# Use -DKERNELHEADERS_DIR=.. to specify headers path
# By default, we assume you want to build against running kernel
if(NOT DEFINED KERNELHEADERS_DIR)
    # Find the kernel release
    execute_process(
            COMMAND uname -r
            OUTPUT_VARIABLE KERNEL_RELEASE
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    # Find the headers
    find_path(
            KERNELHEADERS_DIR
            include/linux/user.h
            PATHS /usr/src/linux-headers-${KERNEL_RELEASE}
    )

    message(STATUS "Kernel release: ${KERNEL_RELEASE}")
endif()

message(STATUS "Kernel headers: ${KERNELHEADERS_DIR}")

# Generate Kbuild file for kernel Makefile to build
string(REPLACE ";" " " SOURCES_LINE "${SOURCES}")

file(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/Kbuild
        "obj-m := ${CMAKE_PROJECT_NAME}.o
${CMAKE_PROJECT_NAME}-srcs := ${SOURCES_LINE}
        ${CMAKE_PROJECT_NAME}-y := $(${CMAKE_PROJECT_NAME}-srcs:.c=.o)
ccflags-y := -std=gnu17 -Wall -Werror -Wno-declaration-after-statement"
)

# The actual kernel build will be made through make call
set(DRIVER_FILE "${CMAKE_PROJECT_NAME}.ko")
add_custom_command(
        OUTPUT ${DRIVER_FILE}
        COMMAND $(MAKE) -C ${KERNELHEADERS_DIR} modules
        M=${CMAKE_CURRENT_BINARY_DIR} src=${CMAKE_CURRENT_SOURCE_DIR}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        DEPENDS ${SOURCES} VERBATIM)

# Add it as a target
add_custom_target(dmp-task ALL DEPENDS ${DRIVER_FILE})

# Make a fake library from the same sources to enable LSP
add_library(dummy ${SOURCES})

target_compile_definitions(dummy PRIVATE -D__KERNEL__ -DMODULE)

# All header files
# Ref: https://github.com/microsoft/vscode-cpptools/issues/5588#issuecomment-662116156
target_include_directories(
        dummy
        PRIVATE
        ${KERNELHEADERS_DIR}/include
        ${KERNELHEADERS_DIR}/include/uapi
        ${KERNELHEADERS_DIR}/include/generated/uapi
        ${KERNELHEADERS_DIR}/arch/${ARCH}/include
        ${KERNELHEADERS_DIR}/arch/${ARCH}/include/generated
        ${KERNELHEADERS_DIR}/arch/${ARCH}/include/uapi
        ${KERNELHEADERS_DIR}/arch/${ARCH}/include/generated/uapi
)

# We exclude our fake and test targets from `make all`
set_target_properties(
        dummy
        PROPERTIES
        EXCLUDE_FROM_ALL 1
        EXCLUDE_FROM_DEFAULT_BUILD 1
)
