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

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

LIB_PATH = ./libft
SRC_PATH = ./src/*.c
INC_PATH = ./include/*.h

$(NAME):
	@make -C $(LIB_PATH)
	@gcc $(FLAGS) -c $(SRC_PATH) -I $(INC_PATH)
	@ar rc $(NAME) *.o $(LIB_PATH)/*.o 

all: $(NAME)

clean: 
	@make clean -C $(LIB_PATH)
	@rm -f *.o

fclean: clean
	@rm -f $(LIB_PATH)/*.a
	@rm -f *.a

re: fclean all

temp:
	@gcc main.c libftprintf.a