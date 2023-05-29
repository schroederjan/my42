NAME = 			libftprintf.a

SRC_DIR = 		./
SRCS = 			$(wildcard $(SRC_DIR)/*.c)

OBJ_DIR = 		obj
OBJECTS =		$(SRCS:.c=$(OBJ_DIR).o)

LIBFT_PATH = 	../libft 
LIBFT = 		$(LIBFT_PATH)/libft.a

CC = 			gcc
CFLAGS = 		-Wall -Wextra -Werror
AR =			ar
ARFLAGS =		rcs
RM =			rm -rf

$(OBJ_DIR)/%.o: %.c
				$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME)
#bonus: ?

$(NAME):		$(LIBFT) $(OBJ_DIR) $(OBJECTS)
				cp $(LIBFT) $(NAME)
				$(AR) $(ARFLAGS) $(NAME) $(OBJECTS)

$(LIBFT):		
				make -C $(LIBFT_PATH) all

$(OBJ_DIR):
				mkdir -p $(OBJ_DIR)

clean:
				make -C $(LIBFT_PATH) clean
				$(RM) $(OBJ_DIR)

fclean: 		clean
				make -C $(LIBFT_PATH) fclean
				$(RM) $(NAME)

re: 			fclean all

.PHONY:			all clean fclean re libft
