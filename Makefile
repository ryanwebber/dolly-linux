
ARCH := x86_64
TOOLCHAIN := $(ARCH)-linux-gnu-
BUILD_DIR ?= build

CC := $(TOOLCHAIN)gcc

KERNEL_VERSION ?= linux-6.13.5
KERNEL_ARCH ?= $(ARCH)
KERNEL_CROSS_COMPILE := $(TOOLCHAIN)
KERNEL_IMAGE := $(BUILD_DIR)/$(KERNEL_VERSION)/arch/$(KERNEL_ARCH)/boot/bzImage
KERNEL_URL := https://cdn.kernel.org/pub/linux/kernel/v6.x/$(KERNEL_VERSION).tar.xz

# Currently hitting deadlocks compiling the kernel using parallel builds on ARM macOS with docker
KERNEL_BUILD_JOBS := 1 # $(shell nproc)

ISO_TARGET := $(BUILD_DIR)/$(ARCH)-linux-wuso.iso

BOOT_FILES := $(BUILD_DIR)/iso-root
INITRAMFS := $(BUILD_DIR)/initramfs.cpio

# Default target: build all subdirectories
all: $(ISO_TARGET)

dirs:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(BUILD_DIR)/userspace

iso: $(ISO_TARGET)

initramfs: $(INITRAMFS)

kernel: $(KERNEL_IMAGE)

userspace:
	$(MAKE) -C userspace TOOLCHAIN=$(TOOLCHAIN) BUILD_DIR=$(abspath $(BUILD_DIR))/userspace

$(ISO_TARGET): $(KERNEL_IMAGE) $(INITRAMFS)
	@mkdir -p $(BOOT_FILES)/boot
	@mkdir -p $(BOOT_FILES)/boot/syslinux
	@cp config/syslinux.cfg $(BOOT_FILES)/boot/syslinux
	@cp /usr/lib/syslinux/modules/bios/ldlinux.c32 $(BOOT_FILES)/boot/syslinux
	@cp /usr/lib/ISOLINUX/isolinux.bin $(BOOT_FILES)/boot/syslinux
	@cp $(KERNEL_IMAGE) $(BOOT_FILES)/boot/kernel
	@cp $(INITRAMFS) $(BOOT_FILES)/boot/initramfs
	@mkdir -p $(BUILD_DIR)/iso-root/rootfs
	@echo "Building ISO..."
	genisoimage -o $(ISO_TARGET) -b boot/syslinux/isolinux.bin -c boot/syslinux/boot.cat -J -r -no-emul-boot -boot-load-size 4 -boot-info-table $(BOOT_FILES)
	@echo "Bootable ISO built to $(ISO_TARGET)"

$(INITRAMFS): userspace
	@mkdir -p $(BUILD_DIR)/initramfs
	$(MAKE) -C userspace install CC=$(CC) BUILD_DIR=$(abspath $(BUILD_DIR))/userspace PREFIX=$(abspath $(BUILD_DIR)/initramfs)
	cd $(BUILD_DIR)/initramfs && find . | cpio -H newc -o > $(abspath $(INITRAMFS))

$(KERNEL_IMAGE): $(BUILD_DIR)/$(KERNEL_VERSION)/Makefile
	@mkdir -p $(BUILD_DIR)/$(KERNEL_VERSION)/build
	$(MAKE) -C $(BUILD_DIR)/$(KERNEL_VERSION) ARCH=$(KERNEL_ARCH) CROSS_COMPILE=$(KERNEL_CROSS_COMPILE) defconfig
	$(MAKE) -C $(BUILD_DIR)/$(KERNEL_VERSION) ARCH=$(KERNEL_ARCH) CROSS_COMPILE=$(KERNEL_CROSS_COMPILE) -j$(KERNEL_BUILD_JOBS)
	@echo "Kernel image built to $(KERNEL_IMAGE)"

$(BUILD_DIR)/$(KERNEL_VERSION)/Makefile: $(BUILD_DIR)/$(KERNEL_VERSION).tar.xz
	tar -xmf $(BUILD_DIR)/$(KERNEL_VERSION).tar.xz -C $(BUILD_DIR)

$(BUILD_DIR)/$(KERNEL_VERSION).tar.xz:
	wget -O $(BUILD_DIR)/$(KERNEL_VERSION).tar.xz $(KERNEL_URL)

.PHONY: all iso kernel dirs initramfs userspace
