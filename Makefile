# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 11:16:13 by ptruffau          #+#    #+#              #
#    Updated: 2018/01/07 16:59:07 by ptruffau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_ls

LIB_PATH	= ./libft/

LIB			= -Llibft/ -lft

SRC			= srcs/Affichage.c \
			srcs/main.c \
			srcs/Options.c \
			srcs/Sort.c \
			srcs/Tools.c \
			
CFLAGS		= -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@make -C $(LIB_PATH) all
	@gcc $(CFLAGS) $(SRC) -I $(LIB_PATH) $(LIB) -o $(NAME)
	@echo "Create $(NAME)"

small_clean:
	@rm -rf $(NAME)

clean:
	@make -C $(LIB_PATH) clean

fclean:
	@make -C $(LIB_PATH) fclean
	@rm -f $(NAME)
	@echo "Clean $(NAME) and libft"

re:	fclean all

fast_re: small_clean all

no_flag: small_clean
	@gcc $(SRC) -I $(LIB_PATH) $(LIB) -o $(NAME)
	echo "Create $(NAME)"

.PHONY: all small_clean clean fclean re fast_re
