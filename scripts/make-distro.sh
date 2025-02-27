#!/usr/bin/env bash

# A script to build the wuso distro

# First ensure that the root build directory is set in WUSO_BUILD_ROOT
if [ -z "$WUSO_BUILD_ROOT" ]; then
    echo "ERROR: WUSO_BUILD_ROOT is not set"
    exit 1
fi

# Call the make-distro script
ruby $WUSO_BUILD_ROOT/scripts/make-distro/main.rb
