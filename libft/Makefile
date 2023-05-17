NAME = libft.a

SRC_DIR = ./
SRCS = $(wildcard $(SRC_DIR)/*.c)

OBJECTS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) rcs $@ $^

bonus: $(OBJECTS) $(BOBJECTS)
	$(AR) -r $(NAME) $?

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean bonus fclean re

