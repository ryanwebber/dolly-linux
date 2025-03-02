# Wuso Linux

[![Build Image](https://github.com/ryanwebber/wuso-linux/actions/workflows/docker-image.yml/badge.svg)](https://github.com/ryanwebber/wuso-linux/actions/workflows/docker-image.yml)

A toy x86_64 linux userspace made from scratch, as a learning exercise.

## Plan

 - [x] Build a kernel
 - [x] Build an init binary
 - [x] Construct the initramfs
 - [x] Package and build a bootable disk image
 - [x] Build a libc and libc runtime
 - [x] Statically link binaries with our own libc
 - [ ] "Complete" libc and core utils
 - [ ] Try and port some simple software
 - [ ] Build an x-server implementation
 - [ ] Port build scripts to Nix?
 - [ ] Build a bootloader?
 - [ ] Dynamic linking support?

## Building

With the dependencies installed, the image can be run with just `make`. Dependencies are
listed in the Dockerfile.

Buiding with docker (or podman) is also supported.

```sh
podman build -t wuso-linux .
podman cp wuso-linux:/distbuild/x86_64-wuso-linux.iso .
```

Note: Build has only been tested on arm64 macOS, so cross-compilation is the default behavior.

## Developing

With the [Dev Containers](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers) extension installed in VSCode, the project will automatically be mounted
in a development container with all the necessary dependencies installed. From here, you can
attach a terminal to the container (or use the built-in terminal) to run `make` and build the
image, and changes to the source will be reflected on the host filesystem.
