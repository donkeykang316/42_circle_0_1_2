# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 14:44:47 by kaan              #+#    #+#              #
#    Updated: 2024/01/30 13:02:06 by kaan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a

INC	= inc/

SRC_DIR = src/

OBJ_DIR	= obj/

CC = gcc

FLAGS = -Wall -Wextra -Werror -I

RM = rm -f

AR	= ar rcs

SRC = $(SRC_DIR)get_next_line_utils.c\
		$(SRC_DIR)get_next_line.c\

OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

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
