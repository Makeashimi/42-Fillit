# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/07 13:14:29 by jcharloi          #+#    #+#              #
#    Updated: 2016/12/21 12:55:07 by jcharloi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = fillit
SRC = main.c \
	ft_openfile.c \
	ft_checktetri.c \
	ft_split.c \
	ft_optiblock.c \
	ft_backtracking.c \
	ft_postetri.c \
	ft_free.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C Libft
	@$(CC) -o $@ $^ Libft/libft.a $(CFLAGS)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean fclean re

clean:
	@rm -f $(OBJ)
	@make -C Libft clean                

fclean: clean
	@rm -f $(NAME)
	@make -C Libft fclean

re: fclean all