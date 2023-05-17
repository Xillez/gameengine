BASEDIR=$(dirname "$0") # Get script location.

printf "Switching to build directory: \"$BASEDIR/build\"\n"
cd "$BASEDIR\build"

printf "Running cmake...\n"
cmake ..

printf "Building program...\n"
make

#printf "Running application:\n"
#./bin/gameengine.exe

printf "Switching back to working directory\n"
cd "$BASEDIR"