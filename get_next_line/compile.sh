#!/usr/bin/env bash

# set -ex

# [[ -z $1 ]] && echo "add a buffer_size. (eg. ./compile.sh 42)" && exit 1 ||
#     cc -Wall -Werror -Wextra -DBUFFER_SIZE=$1 get_next_line.c \
#     get_next_line_utils.c && ./a.out && valgrind --leak-check=full ./a.out

buffer_size=""
bonus=0

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
    *)
      echo "Error: Invalid option: $1"
      exit 1
      ;;
  esac
done

if (( $bonus )); then
  # If --bonus is present, run the bonus command.
  cc -Wall -Werror -Wextra $buffer_size get_next_line_bonus.c \
    get_next_line_utils_bonus.c && ./a.out && valgrind --leak-check=full ./a.out
else
  # If --bonus is not present, run the regular command.
  cc -Wall -Werror -Wextra $buffer_size get_next_line.c \
    get_next_line_utils.c && ./a.out && valgrind --leak-check=full ./a.out
fi
