# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aruiz-mo <aruiz-mo@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 16:59:36 by aruiz-mo          #+#    #+#              #
#    Updated: 2022/09/01 20:22:53 by aruiz-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

OBJ = pipex.o

NAME = pipex

all:$(NAME) ./printf/libftprintf.a

%.o: &.c
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@make -C ./printf
	$(CC) $(OBJ) ./printf/libftprintf.a -o $(NAME)
clean:
	@rm -f $(OBJ)
	@make -C printf/ clean

fclean: clean
	@rm -f $(NAME)
	make -C printf/ fclean

re:	fclean all

.PHONY: clean fclean