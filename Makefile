# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gekido <gekido@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/06 10:41:47 by gekido            #+#    #+#              #
#    Updated: 2025/02/08 08:55:24 by gekido           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client

CFLAGS = -Wall -Werror -Wextra

SRC_SERVER = ./server.c
SRC_CLIENT = ./client.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

all : $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER)
		make -C ft_printf
		clang -o $(NAME_SERVER) $(OBJ_SERVER) $(CFLAGS) -Lft_printf -l:ft_printf.a

$(NAME_CLIENT): $(OBJ_CLIENT)
		make -C ft_printf
		clang -o $(NAME_CLIENT) $(OBJ_CLIENT) $(CFLAGS) -Lft_printf -l:ft_printf.a

clean:
		rm -rf $(OBJ_SERVER) $(OBJ_CLIENT)
		make clean -C ft_printf

fclean: clean
		rm -rf $(NAME_SERVER) $(NAME_CLIENT)
		make fclean -C ft_printf

re : fclean all

.PHONY : all clean fclean re