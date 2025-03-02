MODULE := wlibc
SRC_DIR := src
INCLUDE_DIR := include

TOOLCHAIN ?=
CC := $(TOOLCHAIN)gcc
AS := $(TOOLCHAIN)as
AR := $(TOOLCHAIN)ar
LD := $(TOOLCHAIN)ld

PREFIX ?=
INSTALL_INCLUDE_DIR ?= $(PREFIX)/usr/include

BUILD_DIR ?= build

# Append module-specific flags to the common flags from the parent
CFLAGS += -I$(INCLUDE_DIR) -I$(SRC_DIR) -nostdinc  -Wall -Wextra -Werror -Os -fno-ident -fno-asynchronous-unwind-tables -fno-stack-protector -fomit-frame-pointer
ASMFLAGS += -msyntax=intel -mnaked-reg

# Source files and object files
SRCS_C := $(wildcard $(SRC_DIR)/*.c)
SRCS_ASM := $(wildcard $(SRC_DIR)/*.asm)
OBJS_C := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS_C))
OBJS_ASM := $(patsubst $(SRC_DIR)/%.asm, $(BUILD_DIR)/%.o, $(SRCS_ASM))

# Combine object files from both C and ASM
OBJS := $(OBJS_C) $(OBJS_ASM)

# Target static library
TARGET := $(BUILD_DIR)/$(MODULE).a

# Default target: build the module binary
all: $(TARGET)

install:
	# Install headers
	install -d $(INSTALL_INCLUDE_DIR)
	install -m 644 $(INCLUDE_DIR)/*.h $(INSTALL_INCLUDE_DIR)

# Build the static library from object files
$(TARGET): $(OBJS) | $(BUILD_DIR)
	$(AR) rcs $@ $^

# Compile C source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile ASM source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.asm | $(BUILD_DIR)
	$(AS) $(ASMFLAGS) -c $< -o $@

# Create build directory if necessary
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean build files for this module
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean install
