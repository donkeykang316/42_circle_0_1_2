# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 14:44:47 by kaan              #+#    #+#              #
#    Updated: 2023/11/25 16:31:00 by kaan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

CC = cc

FLAGS = -Wall -Wextra -Werror -I

SRC = *.c

OBJ = $(SRC:.c=.o)

EXECUT = main

all: $(NAME) $(EXECUT)
	
$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

main.o: main.c
	$(CC) $(FLAGS) -c main.c

$(EXECUT): $(NAME) main.o
	$(CC) $(FLAGS) -o $(EXECUT) main.o $(NAME)

%.o: %.c
		cc $(FLAGS) . -c $< -o $@
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
