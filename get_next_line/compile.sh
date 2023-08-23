#!/usr/bin/env bash

# set -ex

buffer_size=""
bonus=0

show_usage() {
  echo "Usage: $0 [OPTIONS]"
  echo "Compile and run a C program with optional configurations."
  echo ""
  echo "Options:"
  echo "  -b <number>   Set the buffer size. <number> should be a positive integer."
  echo "  --bonus       Use the bonus version of the program."
  echo "  -h, --help    Display this help message and exit."
  echo ""
}

while (( "$#" )); do
  case "$1" in
    -b)
      if [[ $2 =~ ^[0-9]+$ ]]; then
        buffer_size="-DBUFFER_SIZE=$2"
        shift 2
      else
        echo "Error: -b must be followed by a number."
        exit 1
      fi
      ;;
    --bonus)
      bonus=1
      shift
      ;;
    -h|--help)
      show_usage
      exit 0
      ;;
    *)
      echo "Error: Invalid option: $1"
      show_usage
      exit 1
      ;;
  esac
done


if (( $bonus )); then
  # If --bonus is present, run the bonus command.
  echo "#############"
  echo "## compiling: $buffer_size, BONUS=True"
  echo "#############"
  
  # Compile first
  cc -Wall -Werror -Wextra $buffer_size get_next_line_bonus.c get_next_line_utils_bonus.c
  
  # Capture the program's output
  program_output=$(./a.out)

  # Display the program's output
  echo "Program Output:"
  echo "$program_output"

  # Run valgrind
  valgrind --leak-check=full ./a.out > /dev/null
  
  echo "##########"
  echo "## DONE ##"
  echo "##########"
else
  # If --bonus is not present, run the regular command.
  echo "#############"
  echo "## compiling: $buffer_size, BONUS=False"
  echo "#############"
  
  # Compile first
  cc -Wall -Werror -Wextra $buffer_size get_next_line.c get_next_line_utils.c
  
  # Capture the program's output
  program_output=$(./a.out)

  # Display the program's output
  echo "Program Output:"
  echo "$program_output"

  # Run valgrind
  valgrind --leak-check=full ./a.out > /dev/null
  
  echo "##########"
  echo "## DONE ##"
  echo "##########"
fi
