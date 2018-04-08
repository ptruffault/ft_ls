# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 11:16:13 by ptruffau          #+#    #+#              #
#    Updated: 2018/04/08 18:16:59 by ptruffau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_ls

LIB_PATH	= ./libft/

LIB			= -Llibft/ -lft

SRC			= srcs/affichage.c \
			srcs/main.c \
			srcs/option.c \
			srcs/sort_tools.c \
			srcs/tools.c \
			
CFLAGS		= -Wall -Werror -Wextra

COULEUR		= \033[01;34m

SUCESS		= [\033[1;32mOK\033[00m]

all: $(NAME)

clear:
	@clear

$(NAME):
	@echo "$(COULEUR) -Creating libft.a \033[00m"
	@make -C $(LIB_PATH) all
	@echo "$(SUCESS)"
	@echo "$(COULEUR) -Creating $(NAME) \033[00m"
	@gcc $(CFLAGS) $(SRC) -I $(LIB_PATH) $(LIB) -o $(NAME)
	@echo "$(SUCESS)"

clean:
	@make -C $(LIB_PATH) clean

fclean:
	@echo "$(COULEUR) -Cleaning libft and delete $(NAME) \033[00m"
	@make -C $(LIB_PATH) fclean
	@rm -f $(NAME)
	@echo "$(SUCESS)"

re:	clear fclean all

.PHONY: all clean fclean re
