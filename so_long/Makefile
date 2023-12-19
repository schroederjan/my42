# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 12:24:25 by jschroed          #+#    #+#              #
#    Updated: 2023/12/19 09:31:23 by jschroed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
# =========

NAME		= so_long

LIBFT 		= ./libs/libft/libft.a

CC 			= cc
CFLAGS  	= -Wall -Werror -Wextra
# CFLAGS  	= -Wall -Werror -Wextra -g
MLXFLAGS 	= -lmlx -lXext -lX11

VALGRIND 	= @valgrind --leak-check=full --show-leak-kinds=all \
			  --track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

REMOVE 		= rm -f

SRCS 		= $(addprefix ./src/, \
			  	so_long.c \
				utils.c \
				init_map.c \
				check_map.c \
				check_various.c \
				init_objects.c \
				init_game.c \
				render_map.c \
				handle_input.c \
				close_game.c \
				cleanup_game.c \
				)

OBJECTS = $(SRCS:.c=.o)

# Compile each .c into an .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Commands
# ========
all: $(LIBFT) $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBFT) $(MLXFLAGS) -o $(NAME)
	@echo "$(NAME): $(NAME) was compiled."

$(LIBFT):
	@echo
	make all -C libft

clean:
	make clean -C libft
	$(REMOVE) $(OBJECTS)

fclean: clean
	$(REMOVE) $(NAME)
	@echo "${NAME}: ${NAME} was deleted."

re: fclean all

val: $(NAME)
	$(VALGRIND) ./${NAME} resources/maps/map_small.ber

run: $(NAME)
	./${NAME} resources/maps/map_small.ber

.PHONY: all clean fclean re run val
