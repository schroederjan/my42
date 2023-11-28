# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 12:24:25 by jschroed          #+#    #+#              #
#    Updated: 2023/11/28 13:00:03 by jschroed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
# =========

Name 		= so_long

GREEN 		= \033[0;32m # for creation
RED			= \033[0;31m # for deletion
RESET		= \033[0m # for color reset

LIBFT 		= ./libft/libft.a

CC 			= cc
CFLAGS  	= -Wall -Werror -Wextra
MLXFlAGS 	= -lmlx -lXext -lX11

VALGRIND 	= @valgrind --leak-check=full --show-leak-kinds=all \
			  --track-origins=yes --quiet --tool=memcheck --keep-debuginfo= yes

REMOVE 		= rm -f

SRCS 		= $(addprefix ./src/, 	\
			  	so_long.c 			\
			  	utils.c)

# Commands
# ========

all: 		${LIBFT} ${NAME}

${NAME}: 	
			${CC} ${SRCS} ${LIBFT} ${CFLAGS} ${MLXFFLAGS} -o ${NAME}
			@echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"
			@echo

${LIBFT}: 	
			@echo
			make all -C libft

clean: 
			make clean -C libft
			@echo

fclean:
			${REMOVE} ${NAME}
			@echo "${NAME}: ${RED}${NAME} and ${NAME_BONUS} were deleted${RESET}"
			@echo

re: 		fclean all

run: 		${NAME}
			${VALGRIND} ./{NAME} resources/maps/map_1.ber
			
.PHONY: 	all clean fclean re valgrind run
