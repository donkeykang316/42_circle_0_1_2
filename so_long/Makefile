# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 14:44:47 by kaan              #+#    #+#              #
#    Updated: 2024/02/06 12:22:56 by kaan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT = ./supp/libft/libft.a

PRINTF = ./supp/printf/libftprintf.a

GNL = ./supp/get_next_line/gnl.a

MINILIBX = ./minilibx-linux/libmlx.a

INC	= inc/ supp/libft/ supp/printf/ supp/get_next_line/ minilibx-linux

SRC_DIR = src/

OBJ_DIR	= obj/

CC = cc

CFLAGS = -Wall -Werror -Wextra

MLX := "minilibx-linux"

MLX_URL = "https://cdn.intra.42.fr/document/document/21656/minilibx-linux.tgz"

LIBS = -Lminilibx-linux -lmlx -L./minilibx-linux -Iminilibx-linux -lXext -lX11 -lm -lz

RM = rm -f

MLX_URL = ""

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

getmlxlib:
	@if [ ! -d $(MLX) ]; then \
		echo "GETTING MLX LIBRARY"; \
		git clone https://github.com/42Paris/minilibx-linux.git; \
		echo "MLX LIBRARY cloned"; \
	fi
	@make -C $(MLX)

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
	@make -C ./minilibx-linux

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@make clean -C ./supp/libft
	@make clean -C ./minilibx-linux
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
