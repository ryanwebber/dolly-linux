MODULE := true
SRC_DIR := src
INCLUDE_DIR :=

TOOLCHAIN ?=
CC := $(TOOLCHAIN)gcc

PREFIX ?=
INSTALL_BIN_DIR ?= $(PREFIX)/usr/bin

BUILD_DIR ?= build

# Append module-specific flags to the common flags from the parent
CFLAGS +=
LDFLAGS +=

# Source files and object files
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

# Target executable
TARGET := $(BUILD_DIR)/$(MODULE)

# Default target: build the module binary
all: $(TARGET)

install:
	install -d $(INSTALL_BIN_DIR)
	install -D $(TARGET) $(INSTALL_BIN_DIR)/$(MODULE)

# Build the executable from object files
$(TARGET): $(OBJS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)

# Compile source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create build and bin directories if necessary
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean build files for this module
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
