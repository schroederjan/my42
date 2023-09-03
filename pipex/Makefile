NAME = pipex

CC = gcc

# CFLAGS = -Werror -Wall -Wextra -fsanitize=address
CFLAGS = -Werror -Wall -Wextra

RM = rm -rf

# SRCS = 	src/test.c

SRCS = 	src/pipex.c\
		src/utils.c\
		libft/libft.a

$(NAME): 
	make all -C libft
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) *.o # This removes object files, assuming you'd compile to object files in the future.
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make clean -C libft

re: fclean all
