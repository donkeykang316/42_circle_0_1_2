# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaan <kaan@student.42.de>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 14:44:47 by kaan              #+#    #+#              #
#    Updated: 2024/02/05 23:35:31 by kaan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT = ./supp/libft/libft.a

PRINTF = ./supp/printf/libftprintf.a

GNL = ./supp/get_next_line/gnl.a

MINILIBX = ./supp/minilibx-linux/libmlx.a

INC	= inc/ supp/libft/ supp/printf/ supp/get_next_line/ supp/minilibx-linux/

SRC_DIR = src/

OBJ_DIR	= obj/

CC = cc

CFLAGS = -Wall -Werror -Wextra

LIBS = -lXext -lX11 -lmx

RM = rm -f

SRC = $(SRC_DIR)so_long.c\
		$(SRC_DIR)ft_list.c\
		$(SRC_DIR)ft_more_tile.c\
		$(SRC_DIR)ft_move.c\
		$(SRC_DIR)ft_tile.c\
		$(SRC_DIR)map_check_1.c\
		$(SRC_DIR)map_check_2.c\
		$(SRC_DIR)map_check_3.c\
		$(SRC_DIR)map_check_4.c\
		$(SRC_DIR)utils_sl.c\
		$(SRC_DIR)utils_sl_1.c\
		$(SRC_DIR)utils_sl_2.c\
		$(SRC_DIR)utils_sl_3.c\

OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

all: 					$(MINILIBX) $(LIBFT) $(PRINTF) $(GNL) $(NAME)

$(NAME): 				$(OBJ) $(MINILIBX) $(LIBFT) $(PRINTF) $(GNL)
						@$(CC) $(CFLAGS) $(OBJ) $(MINILIBX) $(LIBFT) $(PRINTF) $(GNL) -o $(NAME)

$(LIBFT):
	@make -C ./supp/libft

$(PRINTF):
	@make -C ./supp/printf

$(GNL):
	@make -C ./supp/get_next_line

$(MINILIBX):
	@make -C ./supp/minilibx-linux

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@make clean -C ./supp/libft
	@make clean -C ./supp/minilibx-linux
	@make clean -C ./supp/get_next_line
	@make clean -C ./supp/printf

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)
	@$(RM) $(PRINTF)
	@$(RM) $(GNL)
	@$(RM) $(MINILIBX)

re: fclean all

.PHONY: all clean fclean re
