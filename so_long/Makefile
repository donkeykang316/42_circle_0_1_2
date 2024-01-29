# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 14:44:47 by kaan              #+#    #+#              #
#    Updated: 2024/01/29 14:08:13 by kaan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

PRINTF = ./printf/libftprintf.a

MINILIBX = ./minilibx-linux/libmlx.a

INC	= inc/

SRC_DIR = src/

OBJ_DIR	= obj/

CC = gcc

FLAGS = -Wall -Wextra -Werror -I

MLB_FLAGS = -L ./minilibx-linux -lmlx -lXext -lX11

RM = rm -f

SRC = $(SRC_DIR)so_long.c\

OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

start:
	@make all

$(PRINTF):
	@make -C ./printf

$(MINILIBX):
	@make -C ./minilibx-linux

all: $(NAME)

$(NAME): $(OBJ) $(PRINTF) $(MINILIBX)
	@$(CC) $(FLAGS) $(MLB_FLAGS) $(INC) $(OBJ) $(PRINTF) -o $(NAME)

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) $(INC) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@make clean -C ./printf
	@make clean -C ./minilibx-linux

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(PRINTF)
	@$(RM) $(MINILIBX)

re: fclean all

.PHONY: start all clean fclean re
