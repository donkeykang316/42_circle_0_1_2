# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 14:44:47 by kaan              #+#    #+#              #
#    Updated: 2024/01/28 12:46:33 by kaan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INC	= inc/

SRC_DIR = srcs/

OBJ_DIR	= obj/

CC = gcc

FLAGS = -Wall -Wextra -Werror -I

RM = rm -f

AR	= ar rcs

SRC = $(SRC_DIR)ft_printf.c\
				ft_putchar_printf.c\
				ft_strlen_printf.c\
				ft_putstr_printf.c\
				ft_putnbr_printf.c\
				spec_handle_1.c\
				spec_handle_2.c\
				ft_puthex.c

OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) $(INC) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@$(RM) .cache_exists

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
