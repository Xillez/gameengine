export VCPKG_INSTALLED_DIR=$(pwd)/build/vcpkg_installed

shouldRun=false

# Main loop for argument parsing
while [[ "$#" -gt 0 ]]; do
    case $1 in
        -r|--run)
            shouldRun=true
            ;;
    esac
    shift
done

source ./scripts/init.sh

# Check for required environment variables
if [ -z "$PROJECT_SETUP_COMPLETE" ]; then
    source ./scripts/windows/init_vcpkg.sh
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



if [ "$shouldRun" = true ]; then
    printf "Running application:\n"
    cd ./bin/Debug
    ./SkyForgeEngine.exe
fi


printf "Switching back to working directory\n"
cd "$BASEDIR"