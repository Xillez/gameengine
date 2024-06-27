#!/bin/bash

# Script to update name and version in vcpkg.json based on environment variables
# Check if jq is installed
if ! command -v jq &> /dev/null; then
    echo "jq could not be found. Please install jq to use this script."
    exit 1
fi

VCPKG_JSON="vcpkg.json"

declare -l lc_pn=$PROJECT_NAME

# Update the vcpkg.json file
jq --arg name "$lc_pn" --arg version "$VERSION" \
    '.name = $name | ."version-string" = $version' \
    "$VCPKG_JSON" > temp.json && mv temp.json "$VCPKG_JSON"

echo "Updated vcpkg.json with name: $lc_pn and version: $VERSION"