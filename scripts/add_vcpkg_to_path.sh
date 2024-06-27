#!/bin/bash

# Path to your vcpkg installation
VCPKG_DIR=$(pwd)/vcpkg

# Function to add a directory to PATH if it's not already there
add_to_path() {
    if [[ ":$PATH:" != *":$1:"* ]]; then
        export PATH="$1:$PATH"
    fi
}

# Add vcpkg to PATH
add_to_path "${VCPKG_DIR}"