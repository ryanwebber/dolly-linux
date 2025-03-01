# Common build directories and variables
PREFIX ?=
BUILD_DIR ?= build

TOOLCHAIN ?=

COMMON_CFLAGS := -Wall
COMMON_LDFLAGS := -static

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
