# Common build directories and variables
PREFIX ?=
BUILD_DIR ?= build

TOOLCHAIN ?=

LIB_GCC_PATH := /usr/lib/gcc-cross/$(TOOLCHAIN:-=)/12/libgcc.a
LIBC_INCLUDE_PATH := $(abspath ../)/libc/include

COMMON_CFLAGS := -nostdinc -I $(LIBC_INCLUDE_PATH) -Wall -Os -fno-ident -fno-asynchronous-unwind-tables -fno-stack-protector -fomit-frame-pointer
COMMON_LDFLAGS := -static -nostartfiles -nostdlib -nodefaultlibs -z noexecstack $(USERLAND_BUILD_DIR)/libc/wlibc.a $(USERLAND_BUILD_DIR)/crt0/crt0.o # $(LIB_GCC_PATH)

# List of subdirectories (modules) to build
SUBDIRS := init true

# Default target: build all subdirectories
all: $(SUBDIRS)

# For each subdirectory, invoke its Makefile, passing the build directories and flags
$(SUBDIRS):
	$(MAKE) -C $@ BUILD_DIR=$(abspath $(BUILD_DIR)/$@) \
	        TOOLCHAIN=$(TOOLCHAIN) CFLAGS="$(COMMON_CFLAGS)" LDFLAGS="$(COMMON_LDFLAGS)"

install:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir install BUILD_DIR=$(abspath $(BUILD_DIR)/$$dir) PREFIX=$(abspath $(PREFIX)); \
	done

# Clean all subdirectories
clean:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean BUILD_DIR=$(abspath $(BUILD_DIR)/$$dir); \
	done
	rm -rf $(BUILD_DIR)

.PHONY: all install clean $(SUBDIRS)
