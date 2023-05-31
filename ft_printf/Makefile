# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 18:51:23 by jschroed          #+#    #+#              #
#    Updated: 2023/05/31 20:01:45 by jschroed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
INCLUDE		= include
LIBFT		= libft
SRC_DIR		= src/
OBJ_DIR		= obj/
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I
RM			= rm -f
AR			= ar rcs

#Sources
SRC_FILES	= 	$(wildcard $(SRC_DIR)*.c)
OBJ 		= 	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC_FILES))
OBJF		=	.cache_exists

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C $(LIBFT)
			@cp $(LIBFT)/libft.a .
			@mv libft.a $(NAME)
			@$(AR) $(NAME) $(OBJ)
			@echo "ft_printf compiled!"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo "Compiling:"
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:
			@$(RM) -rf $(OBJ_DIR)
			@make clean -C $(LIBFT)
			@echo "ft_printf object files cleaned!"

fclean:		clean
			@$(RM) -f $(NAME)
			@$(RM) -f $(LIBFT)/libft.a
			@echo "ft_printf executable files cleaned!"
			@echo "libft executable files cleaned!"

re:			fclean all
			@echo "Cleaned and rebuilt everything for ft_printf!"

norm:
			@norminette $(SRC) $(INCLUDE) $(LIBFT) | grep -v Norme -B1 || true
			@norminette $(SRC) $(INCLUDE) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm
