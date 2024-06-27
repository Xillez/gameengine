#!/bin/bash

# Check if the current environment is Windows
if [[ "$OSTYPE" == "msys" || "$OSTYPE" == "win32" ]]; then
    # DO SOMETHING FOR WINDOWS OR MSYS2
    echo ""
fi

vcpkg install

# Handle errors if vcpkg install fails
if [ $? -ne 0 ]; then
    echo "Error: vcpkg install failed!"
    echo "Check out the errors above and run the same command again to retry."
    export VCPKG_INSTALL_STATUS=false
else
    echo "vcpkg install succeeded!"
    export VCPKG_INSTALL_STATUS=true
fi