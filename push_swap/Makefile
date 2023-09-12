# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 19:45:15 by jschroed          #+#    #+#              #
#    Updated: 2023/09/12 19:45:17 by jschroed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Werror -Wall -Wextra

RM = rm -rf

SRCS = $(wildcard src/*.c utils/*.c)
OBJS = $(SRCS:.c=.o) # Convert .c to .o for object files
LIBS = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make all -C libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)

re: fclean all
