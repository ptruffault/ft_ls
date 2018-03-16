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
			srcs/Sort_tools.c \
			srcs/Tools.c \
			
CFLAGS		= -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@clear
	@make -C $(LIB_PATH) all
	@gcc $(CFLAGS) $(SRC) -I $(LIB_PATH) $(LIB) -o $(NAME)
	@echo "Create $(NAME)"

small_clean:
	@rm -rf $(NAME)
	@echo "Clean $(NAME)"

clean:
	@make -C $(LIB_PATH) clean
	@echo "Clean libft/"

fclean:
	@make -C $(LIB_PATH) fclean
	@rm -f $(NAME)
	@echo "Clean $(NAME)"

re:	fclean all

fast_re: small_clean all

no_flag: small_clean
	@gcc $(SRC) -I $(LIB_PATH) $(LIB) -o $(NAME)
	@echo "Create $(NAME)"

save: fclean
	@git add *
	@git commit -m "make save"
	@git push

load: fclean
	@rm -rf srcs
	@rm -rf includes
	@rm -rf libft
	@rm -rf auteur
	@git clone https://github.com/ptruffault/ft_ls.git
	@cp -r ft_ls/srcs .
	@cp -r ft_ls/includes .
	@cp -r ft_ls/libft .
	@cp ft_ls/auteur .
	@rm -rf ft_ls

.PHONY: all small_clean clean fclean re fast_re
