#!/bin/bash

if [ -z "$1" ]; then
  echo "Please provide a target directory as an argument."
  exit 1
fi

target_directory="$1"
folder_path="$target_directory"
readme_file="${folder_path}/README.md"

# Function to generate the updated file list
generate_file_list() {
  echo "## File List"
  echo ""
  echo "| Index | File Name | Description |"
  echo "| --- | --- | --- |"

  # Initialize the counter
  counter=1

  # Iterate through all files in the folder and append them to the table
  for file in "$folder_path"/*; do
    if [ -f "$file" ] && [ "$(basename "$file")" != "README.md" ]; then
      echo "| $counter | $(basename "$file") | Description here |"
      ((counter++))  # Increment the counter
    fi
  done
}

# Read the existing README.md file
if [ -f "$readme_file" ]; then
  readme_content=$(<"$readme_file")
else
  readme_content=""
fi

# Define the list of sections and initialize the updated README with the Project Title
sections=("Description" "Prerequisites" "Installation" "Usage" "File List" "Contributing" "License" "Contact")
updated_readme="# Project Title"

# Process each section
for section in "${sections[@]}"; do
  # Check if the section exists in the current README content
  if [[ $readme_content =~ "## $section" ]]; then
    # If it exists, extract the content of the section
    content=$(sed -n "/## $section/,/## /p" <<<"$readme_content" | sed "\$d")
  else
    # If it doesn't exist, create the section with the default content
    case "$section" in
      "Description") content="## Description\n\nA short description of your project goes here." ;;
      "Prerequisites") content="## Prerequisites\n\nList any prerequisites here, including software, tools, and dependencies." ;;
      "Installation") content="## Installation\n\nStep-by-step installation instructions go here." ;;
      "Usage") content="## Usage\n\nProvide clear examples and instructions on how to use your project." ;;
      "File List") content="$(generate_file_list)" ;;
      "Contributing") content="## Contributing\n\nExplain how other developers can contribute to your project." ;;
      "License") content="## License\n\nSpecify your project's license and provide a link to the full license text." ;;
      "Contact") content="## Contact\n\nProvide your contact information or links to your social media profiles." ;;
    esac
  fi

  # Append the section content to the updated README
  updated_readme+="\n\n${content}"
done

# Write the updated content to README.md
echo -e "$updated_readme" > "$readme_file"

