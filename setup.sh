#!/bin/bash
set -e

# Usage:
# ./setup.sh [OPTIONS]
#
# Options:
#   --always-continue   Continues script without stopping
#   --first-time        Welcomes the user
#   --no-xorg           Skips installation of X11 Window System



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

# Repository submodules
git submodule update --init --recursive


# Check all arguments and set argument variables
always_continue=0
first_time=0
skip_xorg_install=0

for arg in "$@"; do
    case "$arg" in
        --always-continue) always_continue=1 ;;
        --first-time) first_time=1 ;;
        --no-xorg) skip_xorg_install=1 ;;
    esac
done


if [[ $first_time -eq 1 ]]; then
    echo "🎉 Welcome to Lila!"
    echo ""
    echo "This script will help you set up everything you need to get started."
    echo "- It initializes git submodules"
    echo "- It installs required packages (like xorg-dev)"
    echo ""
    echo "Please make sure you’ve read the README before proceeding."
    echo "If you encounter any issues, check the documentation or reach out to us on github."
    echo ""
    echo "Thank you for using Lila!"
    echo ""
    read -p "Press Enter to continue with setup..."
    echo ""
fi

# Install xorg-dev
if [[ $skip_xorg_install -eq 1 ]]; then
    echo "Skipping xorg installation as requested."
else
    echo "Checking all package"
    detect_distro_and_pkg() {
        if [ -f /etc/os-release ]; then
            . /etc/os-release
            distro=$ID
        else
            echo "Cannot detect distribution. Exiting."
            exit 1
        fi


        case "$distro" in
            ubuntu|debian|linuxmint)
                pkg="xorg-dev"
                ;;
            fedora)
                pkg="xorg-x11-server-devel"
                ;;
            centos|rhel)
                pkg="xorg-x11-server-devel"
                ;;
            arch)
                pkg="xorg-server-devel"
                ;;
            opensuse*|suse)
                pkg="xorg-x11-devel"
                ;;
            *)
                echo "Unsupported or unknown distribution: $distro"
                echo "Please install xorg-dev manually."
                exit 1
                ;;
        esac
    }

    is_installed() {
        local pkg=$1
        case "$distro" in
            ubuntu|debian|linuxmint)
                dpkg -s "$pkg" &> /dev/null
                ;;
            fedora|centos|rhel|opensuse*|suse)
                rpm -q "$pkg" &> /dev/null
                ;;
            arch)
                pacman -Q "$pkg" &> /dev/null
                ;;
            *)
                return 1
                ;;
        esac
    }

    install_xorg_dev() {
        echo "Checking if $pkg is already installed..."

        if is_installed "$pkg"; then
            echo "$pkg is already installed. Skipping installation."
            return
        fi

        echo "Package $pkg is not installed!"

        if [[ $always_continue -eq 0 ]]; then
            read -p "Would you like to install $pkg?"
        fi

        echo "Installing $pkg..."

        case "$distro" in
            ubuntu|debian|linuxmint)
                sudo apt update
                sudo apt install -y "$pkg"
                ;;
            fedora)
                sudo dnf install -y "$pkg"
                ;;
            centos|rhel)
                sudo yum install -y "$pkg"
                ;;
            arch)
                sudo pacman -Sy --noconfirm "$pkg"
                ;;
            opensuse*|suse)
                sudo zypper install -y "$pkg"
                ;;
        esac

        echo "Installation completed."
    }

    detect_distro_and_pkg
    install_xorg_dev
fi
