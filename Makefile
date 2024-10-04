# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabenet <mabenet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/24 11:01:54 by mabenet           #+#    #+#              #
#    Updated: 2024/10/04 09:29:50 by mabenet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra -g 

SRC = algo_utils.c\
	main.c \
	parse_utils.c \
	push_swap.c \
	free_all.c \
	push.c \
	r_rotate.c \
	rotate.c \
	swap.c \
	 


all: $(NAME)

$(NAME): $(SRC:.c=.o)
	$(CC) $(CFLAGS) -lm $(SRC) -o $(NAME)
	echo "Ready to push_swap"

clean:
	rm -rf $(SRC:.c=.o)
	echo "OBJ deleted"

fclean: clean
	rm -rf $(NAME)
	echo "$(NAME) deleted"

re: fclean all

.PHONY: all, clean, fclean, re, bonus

.SILENT: