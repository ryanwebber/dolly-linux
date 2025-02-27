# Common build directories and variables
BUILD_DIR := .build
BIN_DIR := .out

CC := gcc
COMMON_CFLAGS := -Wall
COMMON_LDFLAGS :=

# List of subdirectories (modules) to build
SUBDIRS := true

# Default target: build all subdirectories
all: $(SUBDIRS)

# For each subdirectory, invoke its Makefile, passing the build directories and flags
$(SUBDIRS):
	$(MAKE) -C $@ BUILD_DIR=$(abspath $(BUILD_DIR)/$@) BIN_DIR=$(abspath $(BIN_DIR)) \
	        CC=$(CC) CFLAGS="$(COMMON_CFLAGS)" LDFLAGS="$(COMMON_LDFLAGS)"

# Clean all subdirectories
clean:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean BUILD_DIR=$(abspath $(BUILD_DIR)/$$dir); \
	done
	rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all clean $(SUBDIRS)
