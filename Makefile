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

SRC			= srcs/affichage.c \
			srcs/main.c \
			srcs/option.c \
			srcs/sort_tools.c \
			srcs/tools.c \

GIT 		= https://github.com/ptruffault/ft_ls.git

CFLAGS		= -Wall -Werror -Wextra

COULEUR		= \033[01;34m

SUCESS		= [\033[1;32mOK\033[00m]

$(NAME):
	@make -C ./libft/ all
	@echo "$(COULEUR) -Creating $(NAME) \033[00m"
	@gcc $(CFLAGS) $(SRC) -I ./includes -Llibft/ -lft -o $(NAME)
	@echo "$(SUCESS)"

all: $(NAME)

clean:
	@rm -rf $(NAME)

fclean: clean
	@make -C ./libft/ fclean

re:	clean all

.PHONY: all clean fclean re

save: fclean
	@git add * srcs/* includes/*
	@git commit -m  "make save"
	@git push
	@echo "$(DONE)"

load:
	@rm -rf *
	@git clone $(GIT) TMP && mv TMP/* . && rm -rf TMP libft
	@git clone https://github.com/ptruffault/libft.git
