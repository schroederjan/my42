# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 12:24:25 by jschroed          #+#    #+#              #
#    Updated: 2023/12/20 09:48:02 by jschroed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = so_long

LIBFT = ./libs/libft
LIBMLX = ./libs/minilibx-linux
LIBS = -L$(LIBMLX) -lmlx -lXext -lX11 -lm -lbsd

HEADERS = -I ./includes -I $(LIBMLX)
CC = cc
CFLAGS = -Wall -Werror -Wextra
# CFLAGS = -Wall -Werror -Wextra -g

SRCS = $(shell find ./src -iname "*.c")
OBJS = $(SRCS:.c=.o)

REMOVE = rm -rf
VALGRIND = @valgrind --leak-check=full --show-leak-kinds=all \
            --track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

# Commands
all: libmlx $(LIBFT)/libft.a $(NAME)

libmlx:
	@echo "Compiling MinilibX..."
	@make -C $(LIBMLX)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(LIBFT)/libft.a $(HEADERS) -o $(NAME)

$(LIBFT)/libft.a:
	@echo "Compiling libft..."
	@make all -C $(LIBFT)

clean:
	make clean -C $(LIBFT)
	$(REMOVE) $(OBJS)
	@make clean -C $(LIBMLX)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

val: $(NAME)
	$(VALGRIND) ./${NAME} resources/maps/map_small.ber

run: $(NAME)
	./${NAME} resources/maps/map_small.ber

norm:
	@norminette ./includes
	@norminette ./src
	@norminette ./libs/libft

.PHONY: all clean fclean re run val norm libmlx
