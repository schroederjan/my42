#!/usr/bin/env bash

# if [[ -z $1 ]]; then
#     echo "add a buffer_size. (eg. ./compile.sh 42)"
# else
#     cc -Wall -Werror -Wextra -DBUFFER_SIZE=$1 get_next_line.c get_next_line_utils.c && ./a.out
# fi


[[ -z $1 ]] && echo "add a buffer_size. (eg. ./compile.sh 42)" && exit 1 ||
	cc -Wall -Werror -Wextra -DBUFFER_SIZE=$1 get_next_line.c get_next_line_utils.c && ./a.out


