NAME = pipex

CC = cc

CFLAGS = -Werror -Wall -Wextra

RM = rm -rf

SRCS = src/pipex.c src/utils.c src/awk_utils.c
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
