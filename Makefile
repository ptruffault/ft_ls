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

NAME		= 	ft_ls
FILES		= 	affichage.c \
				option.c \
				sort_tools.c \
				tools.c \
				main.c 
GIT 		= 	https://github.com/ptruffault/ft_ls.git
FLAGS		= 	-Wall -Werror -Wextra

FILES_FOLD	= 	./srcs/
OBJ_FOLD	= 	./bin/
SRC 		=	 $(addprefix $(FILES_FOLD), $(FILES))
OBJ			= 	$(addprefix $(OBJ_FOLD), $(FILES:.c=.o))

COLOR		= 	\033[01;34m
NO_COLOR	= 	\033[00m
OP_COLOR	= 	\033[1;31m
DONE 		= 	$(NO_COLOR)[\033[1;32mOK$(NO_COLOR)]

all: bin $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft/ all
	@echo "$(COLOR) -Creating $(NAME)$(NO_COLOR)"
	@gcc $(FLAGS) $(OBJ) -I ./includes -Llibft -lft -o $(NAME)
	@echo "$(DONE)"

bin:
	@mkdir $@

bin/%.o: $(FILES_FOLD)/%.c 
	@gcc $(FLAG) -I includes/ -c $< -o $@
	@echo "$(DONE) $(COLOR)$<"

clear:
	@clear

cln:
	@rm -rf bin/*

clean: cln
	@make -C libft/ fclean

fclean: clean
	@rm -rf $(NAME)

re:	clear fclean all

save: clear fclean
	@git add * srcs/* includes/*
	@git commit -m  "make save"
	@git push
	@echo "$(DONE)"

update: clear 
	@rm -rf *
	@echo "$(COLOR)download $(NAME)$(NO_COLOR)"
	@git clone $(GIT) TMP && mv TMP/* . && rm -rf TMP libft
	@echo "$(COLOR)download libft$(NO_COLOR)"
	@git clone https://github.com/ptruffault/libft.git
	
.PHONY: all cln clean fclean re save update