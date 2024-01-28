# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 14:44:47 by kaan              #+#    #+#              #
#    Updated: 2024/01/28 12:24:25 by kaan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

PRINTF = ./printf/libftprintf.a

INC	= inc/

SRC_DIR = srcs/

OBJ_DIR	= obj/

CC = gcc

FLAGS = -Wall -Wextra -Werror -I

RM = rm -f

SRC = $(SRC_DIR)command_1.c\
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
				utils_1.csss\
				utils_2.c\
				utils_3.c\
		

OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

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
