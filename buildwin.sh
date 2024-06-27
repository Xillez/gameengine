export VCPKG_INSTALLED_DIR=$(pwd)/build/vcpkg_installed

# Check for required environment variables
if [ -z "$PROJECT_SETUP_COMPLETE" ]; then
    source ./scripts/init.sh
    source ./scripts/init_vcpkg.sh
fi

BASEDIR=$(dirname "$0") # Get script location.

printf "Switching to build directory: \"$BASEDIR/build\"\n"
if [ ! -d "$BASEDIR/build" ]; then
    mkdir "$BASEDIR/build"
fi
cd "$BASEDIR\build"

printf "Running cmake:\n"
export TARGET_ARCH=x64
cmake .. -A $TARGET_ARCH -DCMAKE_TOOLCHAIN_FILE="C:/vcpkg/scripts/buildsystems/vcpkg.cmake"

CONFIGURATION="Debug"

printf "Building program:\n"
cmake --build . --config Debug

printf "Running application:\n"
cd ./bin/Debug
./SkyForgeEngine.exe

printf "Switching back to working directory\n"
cd "$BASEDIR"