#!/usr/bin/env bash

[[ -z $1 ]] && echo "add a buffer_size. (eg. ./compile.sh 42)" && exit 1 ||
	cc -Wall -Werror -Wextra -DBUFFER_SIZE=$1 get_next_line.c \
	get_next_line_utils.c && ./a.out && valgrind --leak-check=full ./a.out
