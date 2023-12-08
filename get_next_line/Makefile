# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaan <kaan@student.42.de>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 14:59:49 by kaan              #+#    #+#              #
#    Updated: 2023/12/07 15:09:27 by kaan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

HEADER = get_next_line.h

FLAGS = -Wall -Wextra -Werror

SRC = get_next_line.c\
		get_next_line_utils.c

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