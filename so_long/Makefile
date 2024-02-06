# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 14:44:47 by kaan              #+#    #+#              #
#    Updated: 2024/02/06 16:48:20 by kaan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -Imlx -g 

MLXFLAGS=	-L ./libraries/mlx -lmlx -lXext -lX11

LIBS	=	./libraries/libft/libft.a

PRINTF  =  ./libraries/printf/libftprintf.a

GNL  =  ./libraries/get_next_line/gnl.a

SRCS	=	main.c\
			ft_list.c\
			ft_more_tile.c\
			ft_move.c\
			ft_tile.c\
			map_check_1.c\
			map_check_2.c\
			map_check_3.c\
			map_check_4.c\
			utils_sl.c\
			utils_sl_1.c\
			utils_sl_2.c\
			utils_sl_3.c\

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME): $(OBJS)
			make -C ./libraries/mlx
			make -C ./libraries/libft
			make -C ./libraries/printf
			make -C ./libraries/get_next_line
			$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MLXFLAGS) $(PRINTF) $(GNL) -o $(NAME)

clean:
			make clean -C ./libraries/mlx
			make clean -C ./libraries/libft
			make clean -C ./libraries/printf
			make clean -C ./libraries/get_next_line
			rm -rf $(OBJS)
			
fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY: all clean fclean re
