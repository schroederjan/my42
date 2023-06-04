# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschroed <jschroed@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 18:51:23 by jschroed          #+#    #+#              #
#    Updated: 2023/06/04 19:23:42 by jschroed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
INCLUDE		= include
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
			@$(AR) $(NAME) $(OBJ)
			@echo "ft_printf compiled!"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo "Compiling: $<"
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:
			@$(RM) -rf $(OBJ_DIR)
			@echo "ft_printf object files cleaned!"

fclean:		clean
			@$(RM) -f $(NAME)
			@echo "ft_printf executable files cleaned!"

re:			fclean all
			@echo "Cleaned and rebuilt everything for ft_printf!"

norm:
			@norminette $(SRC_DIR) $(INCLUDE) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm
