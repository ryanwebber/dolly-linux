# Use the Debian stable image as the base
FROM debian:stable

# Update and install basic dependencies
RUN apt-get update && \
    apt-get install -y \
    gcc \
    coreutils \
    bc \
    bison \
    flex \
    make \
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

RUN mkdir -p /home/wuso
WORKDIR /home/wuso

# Copy the necessary files to build the kernel
COPY scripts /home/wuso/scripts
COPY Makefile /home/wuso/Makefile

# Run the host-check script to verify the environment
RUN /home/wuso/scripts/check-host.sh

# Build the kernel. We do this explicitly to leverage
# the docker cache since the kernel build is slow.
RUN make -C /home/wuso dirs kernel

# Copy the necessary files to build the distro
COPY config /home/wuso/config
COPY userspace /home/wuso/userspace

# Build the distro
RUN make -C /home/wuso BUILD_DIR=/distbuild

# Keep the container running
CMD ["/bin/bash"]
