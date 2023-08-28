NAME = pipex

CC = gcc

CFLAGS = -Werror -Wall -Wextra -fsanitize=address

RM = rm -rf

SRCS = 	src/test.c

# SRCS = 	src/pipex.c\
#         src/utils.c

$(NAME): 
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) *.o # This removes object files, assuming you'd compile to object files in the future.

fclean: clean
	$(RM) $(NAME)

re: fclean all
