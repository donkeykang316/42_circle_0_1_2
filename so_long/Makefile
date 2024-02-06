# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmooney <kmooney@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 14:44:47 by kaan              #+#    #+#              #
#    Updated: 2024/02/06 14:54:24 by kmooney          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = so_long

# Compilation flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

# lib directory
LIBS_DIR = ./libs/

# Linked libraries
LFLAGS = -lft -lmlx -lftprintf -l:gnl.a -lXext -lX11

# Library Directories
LIBFT_DIR = $(LIBS_DIR)libft/
MLX_DIR = $(LIBS_DIR)minilibx-linux/
PRINTF_DIR = $(LIBS_DIR)printf/
GNL_DIR = $(LIBS_DIR)get_next_line/

# Compiler flags to link to libraries
LIBS = -L$(LIBFT_DIR) -L$(MLX_DIR) -L$(PRINTF_DIR) -L$(GNL_DIR)

# MLX := "minilibx-linux"
# MLX_URL = "https://cdn.intra.42.fr/document/document/21656/minilibx-linux.tgz"

# RM = rm -f
# MLX_URL = ""

SRC_DIR = src/
OBJ_DIR	= obj/

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
DEPENDS := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.d, $(SRCS))

# $(MLX):
# 	@if [ ! -d $(MLX) ]; then \
# 		echo "GETTING MLX LIBRARY"; \
# 		git clone https://github.com/42Paris/minilibx-linux.git; \
# 		echo "MLX LIBRARY cloned"; \
# 	fi

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(MLX_DIR)
	@make -C $(PRINTF_DIR)
	@make -C $(GNL_DIR)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) -o $(NAME) $(LIBS) $(LFLAGS) 

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c -MMD -MP $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)
	
-include $(DEPENDS)

clean:
	@$(RM) -r $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PRINTF_DIR)
	@make clean -C $(GNL_DIR)
	@make clean -C $(MLX_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
