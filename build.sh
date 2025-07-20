#!/bin/bash
set -e

# Usage:
# ./build.sh [OPTIONS]
#
# Options:
#   --run           Skips any pauses or prompts

# Non root check
if [ "$EUID" -eq 0 ]; then
    echo "This script should NOT be run as root or with sudo. Please run as a regular user."
    exit 1
fi

# Directory check
SRC_DIR=Lila/src

if [ ! -d "$SRC_DIR" ]; then
    echo "Make sure you are in the root folder of this repository!"
    exit 1
fi

# Check all arguments and set argument variables
run=0

for arg in "$@"; do
    case "$arg" in
        --run) run=1 ;;
    esac
done

# Building
BUILD_DIR=build

# Generate make script with Cmake
cmake -S . -B $BUILD_DIR

cd $BUILD_DIR

# Build using Makefile
make

if [[ $run -eq 1 ]]; then
    ./LilaEngine
fi

cd ../
