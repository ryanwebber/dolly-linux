# Wuso Linux

A small x86_64 linux userspace from scratch, for educational purposes.

## Plan

 - [x] Build a kernel
 - [x] Build an init binary
 - [x] Construct the initramfs
 - [x] Package and build a bootable disk image
 - [ ] Built libc and libc runtime
 - [ ] Statically link binaries with our own libc
 - [ ] Iterate on libc, and core utilities
 - [ ] Build an x-server implementation
 - [ ] Port build scripts to Nix?
 - [ ] Build a bootloader?

## Building

With the dependencies installed, the image can be run with just `make`. Dependencies are
listed in the Dockerfile.

Buiding with docker (or podman) is also supported.

```sh
podman build -t wuso-linux .
podman cp wuso-instance:/home/wuso/build/x86_64-wuso-linux2.iso .
```

Note: Build has only been tested on arm64 macOS, so cross-compilation is the default behavior.