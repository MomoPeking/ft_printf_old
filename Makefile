# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/20 18:03:37 by qdang             #+#    #+#              #
#    Updated: 2019/11/22 13:41:45 by qdang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

FLAGS = -Wall -Wextra -Werror -g

LIB_PATH = ./libft
LIB_LINK = -I $(LIB_PATH) -L $(LIB_PATH) -lft

$(NAME):
	@make -C $(LIB_PATH)
	@gcc -c *.c
	@gcc $(LIB_LINK) -lm *.o -o $(NAME)

all: $(NAME)

clean: 
	@make clean -C $(LIB_PATH)
	@rm *.o

fclean:
	@rm $(NAME)
	@rm $(LIB_PATH)/*.a
