# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 12:24:25 by jschroed          #+#    #+#              #
#    Updated: 2023/12/19 09:56:32 by jschroed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
# =========

NAME		= so_long

LIBFT 		= ./libs/libft/libft.a
LIBMLX 		= ./libs/MLX42
LIBS		= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

HEADERS		= -I ./includes -I $(LIBMLX)/include
CC 			= cc
CFLAGS  	= -Wall -Werror -Wextra
# CFLAGS  	= -Wall -Werror -Wextra -g

SRCS		= $(shell find ./src -iname "*.c")
OBJS 		= $(SRCS:.c=.o)

REMOVE 		= rm -rf
VALGRIND 	= @valgrind --leak-check=full --show-leak-kinds=all \
			  --track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

# Commands
# ========

all: libmlx $(LIBFT) $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"


$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(LIBFT) $(HEADERS) -o $(NAME)

$(LIBFT):
	@echo
	make all -C libft

clean:
	make clean -C libft
	$(REMOVE) $(OBJS)
	$(REMOVE) $(LIBMLX)/build

fclean: clean
	$(REMOVE) $(NAME)

re: clean all

val: $(NAME)
	$(VALGRIND) ./${NAME} resources/maps/map_small.ber

run: $(NAME)
	./${NAME} resources/maps/map_small.ber

.PHONY: all clean fclean re run val libmlx
