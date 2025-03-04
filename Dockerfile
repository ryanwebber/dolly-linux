# Use the Debian stable image as the base
FROM debian:stable

ARG BUILD_DIR=/distbuild
ARG SOURCE_DIR=/home/dolly

# Update and install basic dependencies
RUN apt-get update && \
    apt-get install -y \
    gcc \
    coreutils \
    bc \
    bison \
    flex \
    make \
    cmake \
    gawk \
    file \
    xz-utils \
    bash \
    wget \
    cpio \
    ruby \
    libncurses-dev \
    libelf-dev \
    libssl-dev

# Grab the cross-compiler toolchain
RUN apt-get install -y \
    gcc-x86-64-linux-gnu \
    binutils-x86-64-linux-gnu \
    # TODO: Remove this once linking against prebuilt libc is no longer needed
    libc6-dev-amd64-cross

# Grab tools to create the bootable image
RUN apt-get install -y \
    syslinux-common \
    isolinux \
    genisoimage

# Ensure the shell is bash
RUN rm /bin/sh && ln -s /bin/bash /bin/sh

RUN mkdir -p $SOURCE_DIR
RUN mkdir -p $SOURCE_DIR/userspace

# Copy the necessary files to build the kernel
COPY CMakeLists.txt $SOURCE_DIR/CMakeLists.txt
COPY toolchain.cmake $SOURCE_DIR/toolchain.cmake
COPY userspace/CMakeLists.txt $SOURCE_DIR/userspace/CMakeLists.txt
COPY scripts $SOURCE_DIR/scripts
COPY kernel $SOURCE_DIR/kernel

# Run the host-check script to verify the environment
RUN $SOURCE_DIR/scripts/check-host.sh

RUN mkdir -p $BUILD_DIR
WORKDIR $BUILD_DIR

# Build the kernel. We do this explicitly to leverage
# the docker cache since the kernel build is slow.
RUN cmake $SOURCE_DIR -DBUILD_USER_SPACE=NO
RUN make kernel

# Copy the necessary files to build the userspace
COPY config $SOURCE_DIR/config
COPY userspace/bin $SOURCE_DIR/userspace/bin
COPY userspace/crt0 $SOURCE_DIR/userspace/crt0
COPY userspace/libc $SOURCE_DIR/userspace/libc

# Build the distro
RUN cmake $SOURCE_DIR -DBUILD_USER_SPACE=YES
RUN make

# Keep the container running
CMD ["/bin/bash"]
