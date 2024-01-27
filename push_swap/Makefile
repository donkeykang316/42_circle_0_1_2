# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 14:44:47 by kaan              #+#    #+#              #
#    Updated: 2024/01/27 18:22:17 by kaan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HEADER = push_swap.h

FLAGS = -Wall -Wextra -Werror

SRC = command_1.c\
		command_2.c\
		command_3.c\
		ft_atoi.c\
		ft_calloc.c\
		ft_lstadd_back.c\
		ft_lstadd_front.c\
		ft_lstlast.c\
		ft_lstnew.c\
		ft_lstsize.c\
		ft_split.c\
		ft_strlen.c\
		push_swap.c\
		sort_alg_1.c\
		sort_alg_2.c\
		sort_alg_3.c\
		sort_alg_4.c\
		sort_alg_5.c\
		utils_1.c\
		utils_2.c\
		utils_3.c\
		libftprintf.a\
		

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	cc $(FLAGS) -I . -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re