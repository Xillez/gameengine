# Main loop for argument parsing (EXAMPLE)
#while [[ "$#" -gt 0 ]]; do
#    case $1 in
#        -h|--help)
#            show_help
#            exit 0
#            ;;
#        -a|--optionA)
#            handle_option_a
#            ;;
#        -b|--optionB)
#            handle_option_b "$@"
#            shift_val=$?
#            # Shift by one less than the number of arguments consumed, since shift at the end of the loop will account for one
#            shift $((shift_val - 1))
#            ;;
#        *)
#            echo "Error: Invalid option $1" >&2
#            exit 1
#            ;;
#    esac
#    shift
#done

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

source ./scripts/project_vars.sh

BASEDIR=$(dirname "$0") # Get script location.

printf "Switching to build directory: \"$BASEDIR/build\"\n"
if [ ! -d "$BASEDIR/build" ]; then
    mkdir "$BASEDIR/build"
fi
cd "$BASEDIR/build"

printf "Running cmake...\n"
cmake ..

printf "Building program...\n"
make

if [ "$shouldRun" = true ]; then
    printf "Running application:\n"
    ./bin/SkyForgeEngine
fi

printf "Switching back to working directory\n"
cd "$BASEDIR"