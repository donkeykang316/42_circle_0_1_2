# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 14:44:47 by kaan              #+#    #+#              #
#    Updated: 2024/01/28 13:13:36 by kaan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

PRINTF = ./printf/libftprintf.a

INC	= inc/

SRC_DIR = src/

OBJ_DIR	= obj/

CC = gcc

FLAGS = -Wall -Wextra -Werror -I

RM = rm -f

SRC = $(SRC_DIR)command_1.c\
		$(SRC_DIR)command_2.c\
		$(SRC_DIR)command_3.c\
		$(SRC_DIR)ft_atoi.c\
		$(SRC_DIR)ft_calloc.c\
		$(SRC_DIR)ft_lstadd_back.c\
		$(SRC_DIR)ft_lstadd_front.c\
		$(SRC_DIR)ft_lstlast.c\
		$(SRC_DIR)ft_lstnew.c\
		$(SRC_DIR)ft_lstsize.c\
		$(SRC_DIR)ft_split.c\
		$(SRC_DIR)ft_strlen.c\
		$(SRC_DIR)push_swap.c\
		$(SRC_DIR)sort_alg_1.c\
		$(SRC_DIR)sort_alg_2.c\
		$(SRC_DIR)sort_alg_3.c\
		$(SRC_DIR)sort_alg_4.c\
		$(SRC_DIR)sort_alg_5.c\
		$(SRC_DIR)utils_1.c\
		$(SRC_DIR)utils_2.c\
		$(SRC_DIR)utils_3.c\

OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

start:
	@make all

$(PRINTF):
	@make -C ./printf

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
