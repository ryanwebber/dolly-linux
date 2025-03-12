# Dolly Linux

[![Build Image](https://github.com/ryanwebber/dolly-linux/actions/workflows/docker-image.yml/badge.svg)](https://github.com/ryanwebber/dolly-linux/actions/workflows/docker-image.yml)

A toy x86_64 linux userspace made from scratch, as a learning exercise.

## Plan

 - [x] Build a kernel
 - [x] Implement an init binary
 - [x] Construct the initramfs
 - [x] Package and build a bootable disk image
 - [x] Implement a bare minimum libc and libc runtime
 - [x] Statically link binaries with our own libc
 - [ ] Implement BSS zero-ing in crt0
 - [ ] Implement a basic terminal emulator
 - [ ] Try and port some simple software
 - [ ] Mount a persistent filesystem
 - [ ] Implement an installer in the live image?
 - [ ] Implement an x-server implementation?
 - [ ] Implement dynamic linking support?
 - [ ] Implement a bootloader?

## Building

With the dependencies installed, the image can be build with the default cmake target.

```sh
mkdir build && cd build
cmake ..
make
```

Buiding with docker (or podman) is also supported.

```sh
podman build -t dolly-linux .
podman cp dolly-linux:/distbuild/build/x86_64-dolly-linux.iso .
```

Note: Build has only been tested on arm64 macOS, so cross-compilation is the default behavior.

## Developing

With the [Dev Containers](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers)
extension installed in VSCode, the project will automatically be mounted in a development container with
all the necessary dependencies installed. From here, you can attach a terminal to the container (or use
the built-in terminal) to run `cmake` and build the image, and changes to the source will be reflected
on the host filesystem.
