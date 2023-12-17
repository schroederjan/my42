#!/usr/bin/env bash

# Directory where the .ber files are located
map_dir="./resources/maps_error"

# Loop through each .ber file in the directory
for map_file in "$map_dir"/*.ber; do
    # Check if there are any .ber files
    if [ -e "$map_file" ]; then
		echo
        echo "Running so_long with map: $map_file"
        ./so_long "$map_file"
    else
		echo
        echo "No .ber files found in $map_dir."
        break
    fi
done

