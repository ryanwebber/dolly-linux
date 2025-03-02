TOOLCHAIN ?=
AS := $(TOOLCHAIN)as

PREFIX ?=
INSTALL_LIB_DIR ?= $(PREFIX)/usr/lib

BUILD_DIR ?= build

ASMFLAGS += -msyntax=intel -mnaked-reg

TARGET := $(BUILD_DIR)/crt0.o

# Default target: build the module binary
all: $(TARGET)

install:
	# Install crt.o
	install -d $(INSTALL_LIB_DIR)
	install -D $(TARGET) $(INSTALL_LIB_DIR)/crt0.o

# Compile ASM source files into object files
$(TARGET): crt0.asm | $(BUILD_DIR)
	$(AS) $(ASMFLAGS) -c $< -o $@

# Create build directory if necessary
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean build files for this module
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean install
