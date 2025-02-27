# Use the Debian stable image as the base
FROM debian:stable

# Update and install the necessary packages
RUN apt-get update && \
    apt-get install -y \
    gcc \
    coreutils \
    bc \
    bison \
    flex \
    make \
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
    binutils-x86-64-linux-gnu

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

# Run the host-check script to verify the environment
RUN /home/wuso/scripts/check-host.sh

# Run the distro build script to build the distro
RUN /home/wuso/scripts/make-distro.sh

# Keep the container running
CMD ["/bin/bash"]
