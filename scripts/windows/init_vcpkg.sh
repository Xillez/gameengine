#!/bin/bash

./scripts/windows/keep_vcpkg_json_updated.sh

#source ./scripts/windows/add_vcpkg_to_path.sh

source ./scripts/windows/install_dependencies.sh
if [ $VCPKG_INSTALL_STATUS = false ]; then
    exit 1
fi

# Set the CMAKE_TOOLCHAIN_FILE environment variable
export CMAKE_TOOLCHAIN_FILE="C:/vcpkg/scripts/buildsystems/vcpkg.cmake"

# Indicate that the project has been set up.
# Used by buildwin.sh to check if this script has been run.
export PROJECT_SETUP_COMPLETE=true