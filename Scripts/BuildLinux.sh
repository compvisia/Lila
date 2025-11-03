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

BUILD_DIR=BuildLinux

cmake -S . -B $BUILD_DIR

echo "========================"
echo "Lila setup finished!"

cd $BUILD_DIR

cmake --build .

echo "========================"
echo "Lila build finished!"

./App/App

cd ../

echo ========================
echo Lila succesfully ran!
