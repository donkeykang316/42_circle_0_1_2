# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 14:44:47 by kaan              #+#    #+#              #
#    Updated: 2024/01/28 17:07:19 by kaan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

PRINTF = ./printf/libftprintf.a
MINILIBX = ./miniLibX-linux/libmlx.a

INC	= inc/

SRC_DIR = src/

OBJ_DIR	= obj/

CC = gcc

FLAGS = -Wall -Wextra -Werror -I

RM = rm -f

SRC = $(SRC_DIR)so_long.c\

OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

start:
	@make all

$(PRINTF):
	@make -C ./printf

$(MINILIBX):
	@make -C ./miniLibX-linux

all: $(NAME)

$(NAME): $(OBJ) $(PRINTF)
	@$(CC) $(FLAGS) $(INC) $(OBJ) $(PRINTF) -o $(NAME)

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) $(INC) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@make clean -C ./printf

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(PRINTF)

re: fclean all

.PHONY: start all clean fclean re
