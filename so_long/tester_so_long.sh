#!/bin/bash

# Check if project folder is provided as the first argument
if [ -z "$1" ]; then
    echo "Error: Project folder not provided."
    exit 1
fi

# Set the path to the project folder
PROJECT_FOLDER="$1"

# Check if ./so_long executable exists in the project folder
if [ ! -f "$PROJECT_FOLDER/so_long" ]; then
    echo "Error: $PROJECT_FOLDER/so_long executable not found. Please run 'make' in the project folder."
    exit 1
fi

# Set the path to the game executable
GAME_EXECUTABLE="$PROJECT_FOLDER/so_long"

# Set the path to the folder containing invalid maps
INVALID_MAPS_FOLDER="$PROJECT_FOLDER/maps/invalid/"

# Set the path to the folder containing valid maps
VALID_MAPS_FOLDER="$PROJECT_FOLDER/maps/valid/"

# Initialize variables for color codes
COLOR_RED='\033[0;31m'
COLOR_GREEN='\033[0;32m'
COLOR_RESET='\033[0m'

# Initialize a variable to keep track of maps with issues
maps_with_issues=""

# Function to run tests on maps in a folder
function run_tests_on_maps {
    local folder=$1
    for map_file in "$folder"*.ber; do
        echo -e "Testing $map_file:"
        
        # Display the content of the map file twice side by side
        echo
        paste -d"\t" "$map_file"
        echo

        # Run the game executable with Valgrind
        output=$(valgrind --leak-check=full --show-leak-kinds=all "$GAME_EXECUTABLE" "$map_file" 2>&1)

        # Extract lines containing "Error" and the following line from stderr for this specific map
        error_lines=$(echo "$output" | awk '/Error/{print $0;getline;print}')

        # Check if there are any error lines and print them
        if [ -n "$error_lines" ]; then
            echo "$error_lines"
        fi

        # Check if Valgrind output contains any errors
        if [[ $output == *"ERROR SUMMARY: 0 errors from 0 contexts"* && $output != *"Segmentation fault"* ]]; then
            echo -e "${COLOR_GREEN}No memory leaks or errors.${COLOR_RESET}"
        else
            echo -e "${COLOR_RED}Issues detected:${COLOR_RESET}"
            echo "$output"
            maps_with_issues+="$(basename "$map_file")"$'\n'
        fi

        echo -e "==================================="
    done
}

# Determine which maps to test based on the argument or user input
if [ "$1" == "invalid" ]; then
    run_tests_on_maps "$INVALID_MAPS_FOLDER"
elif [ "$1" == "valid" ]; then
    run_tests_on_maps "$VALID_MAPS_FOLDER"
elif [ "$1" == "all" ]; then
    run_tests_on_maps "$INVALID_MAPS_FOLDER"
    run_tests_on_maps "$VALID_MAPS_FOLDER"
else
    read -p "Do you want to test 'valid', 'invalid', or 'all' maps? " choice
    case "$choice" in
        "valid")
            run_tests_on_maps "$VALID_MAPS_FOLDER"
            ;;
        "invalid")
            run_tests_on_maps "$INVALID_MAPS_FOLDER"
            ;;
        "all")
            run_tests_on_maps "$INVALID_MAPS_FOLDER"
            run_tests_on_maps "$VALID_MAPS_FOLDER"
            ;;
        *)
            echo "Invalid choice. Exiting."
            exit 1
            ;;
    esac
fi

echo -e "Testing complete."

# Report maps with issues
if [ -n "$maps_with_issues" ]; then
    echo -e "${COLOR_RED}Maps with issues: $maps_with_issues${COLOR_RESET}"
else
    echo -e "${COLOR_GREEN}No issues found in any maps.${COLOR_RESET}"
fi
