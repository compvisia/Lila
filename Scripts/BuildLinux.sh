#!/bin/bash
echo "    __    ______    ___       ____  __  ________    ____ ";
echo "   / /   /  _/ /   /   |     / __ )/ / / /  _/ /   / __ \\";
echo "  / /    / // /   / /| |    / __  / / / // // /   / / / /";
echo " / /____/ // /___/ ___ |   / /_/ / /_/ // // /___/ /_/ / ";
echo "/_____/___/_____/_/  |_|  /_____/\\____/___/_____/_____/ ";
echo "                                                         ";

set -Ee

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

MODE=${1:-run}
if [[ "$MODE" != "run" && "$MODE" != "sanitize" && "$MODE" != "build" ]]; then
    echo "Unrecognized mode '$MODE'. Valid options: run, sanitize, build (default)."
    exit 1
fi

BUILD_DIR=BuildLinux

if [ "$MODE" == "sanitize" ]; then
    cmake -S . -B $BUILD_DIR -DCMAKE_BUILD_TYPE=Debug -DSANITIZE=ON
else
    cmake -S . -B $BUILD_DIR
fi

echo "========================"
echo "Lila setup finished!"

cd $BUILD_DIR

cmake --build .

echo "========================"
echo "Lila build finished!"

if [ "$MODE" == "run" ]; then

    ./Build/Launcher

    echo ========================
    echo Lila succesfully ran!
elif [ "$MODE" == "sanitize" ]; then
    timeout 10 xvfb-run --auto-servernum ../Build/Launcher
fi

cd ../

echo "Done!"
