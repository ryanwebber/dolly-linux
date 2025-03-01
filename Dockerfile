# Use the Debian stable image as the base
FROM debian:stable

ARG MAKE_DISTRO_SCRIPTS=

# Update and install the necessary packages
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

# Set up environment variables for the build
ENV WUSO_BUILD_ROOT=/home/wuso
ENV WUSO_BUILD_JOBS=8

# Copy the necessary directories into the container (for syncing similar to Vagrant's rsync)
COPY config /home/wuso/config
COPY scripts /home/wuso/scripts
COPY userspace /home/wuso/userspace
COPY Makefile /home/wuso/Makefile

# Run the host-check script to verify the environment
RUN /home/wuso/scripts/check-host.sh

# Run the distro build script to build the distro
# RUN /home/wuso/scripts/make-distro.sh $MAKE_DISTRO_SCRIPTS

# Keep the container running
CMD ["/bin/bash"]
