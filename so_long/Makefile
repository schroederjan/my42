# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 12:24:25 by jschroed          #+#    #+#              #
#    Updated: 2023/12/10 14:46:17 by jschroed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
# =========

NAME		= so_long

LIBFT 		= ./libft/libft.a

CC 			= cc
# CFLAGS  	= -Wall -Werror -Wextra
CFLAGS  	= -Wall -Werror -Wextra -g
MLXFLAGS 	= -lmlx -lXext -lX11

VALGRIND 	= @valgrind --leak-check=full --show-leak-kinds=all \
			  --track-origins=yes --quiet --tool=memcheck --keep-debuginfo= yes

REMOVE 		= rm -f

SRCS 		= $(addprefix ./src/, \
			  	so_long.c \
				checks.c \
				cleanup.c \
				utils.c \
				init_map.c \
				init_game.c \
				render_map.c \
				)

# Commands
# ========

all: 		${LIBFT} ${NAME}

${NAME}: 	
			${CC} ${SRCS} ${LIBFT} ${CFLAGS} ${MLXFLAGS} -o ${NAME}
			@echo "$(NAME): $(NAME) was compiled."
			@echo

${LIBFT}: 	
			@echo
			make all -C libft

clean: 
			make clean -C libft
			@echo

fclean:
			${REMOVE} ${NAME}
			@echo "${NAME}: ${NAME} and ${NAME_BONUS} were deleted."
			@echo

re: 		fclean all

run: 		${NAME}
			${VALGRIND} ./{NAME} resources/maps/map_1.ber
			
.PHONY: 	all clean fclean re valgrind run