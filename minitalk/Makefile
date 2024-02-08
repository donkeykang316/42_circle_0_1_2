# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 17:56:54 by kaan              #+#    #+#              #
#    Updated: 2024/02/08 12:57:20 by kaan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client

SERVER = server

PRINTF = ./libraries/printf/libftprintf.a

LIBFT = ./libraries/libft/libft.a

CC = cc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

SSRC = server.c\

CSRC = client.c\

all:
	@make -C ./libraries/libft
	@make -C ./libraries/printf
	@$(CC) $(FLAGS) $(SSRC) $(LIBFT) $(PRINTF) -o $(SERVER)
	@$(CC) $(FLAGS) $(CSRC) $(LIBFT) $(PRINTF) -o $(CLIENT)

clean:
	@$(RM) -r $(SERVER)
	@$(RM) -r $(CLIENT)
	@make clean -C ./libraries/printf
	@make clean -C ./libraries/libft

fclean: clean
	@$(RM) $(SERVER)
	@$(RM) $(CLIENT)
	@$(RM) $(PRINTF)
	@$(RM) $(LIBFT)

re: fclean all

.PHONY: start all clean fclean re
