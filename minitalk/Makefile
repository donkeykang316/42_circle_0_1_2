# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 17:56:54 by kaan              #+#    #+#              #
#    Updated: 2024/02/06 18:16:38 by kaan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

PRINTF = ./libraries/printf/libftprintf.a

LIBFT = ./libraries/libft/libft.a

INC	= inc/

SRC_DIR = src/

OBJ_DIR	= obj/

CC = gcc

FLAGS = -I

# FLAGS = -Wall -Wextra -Werror -I

RM = rm -f

SRC = $(SRC_DIR)minitalk.c\

OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

start:
	@make all

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	@$(CC) $(FLAGS) $(INC) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) $(INC) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@make clean -C ./libraries/printf
	@make clean -C ./libraries/libft

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(PRINTF)
	@$(RM) $(LIBFT)

re: fclean all

.PHONY: start all clean fclean re
