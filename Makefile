# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/08 19:04:38 by fsnow-be          #+#    #+#              #
#    Updated: 2019/06/08 21:03:59 by masprigg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

FLAGGS = -Wall -Wextra -Werror

SRCS := source/al_ways.c
SRCS += source/algo.c
SRCS += source/ants.c
SRCS += source/connect.c
SRCS += source/cp_ways.c
SRCS += source/errors.c
SRCS += source/free.c
SRCS += source/free2.c
SRCS += source/get_way.c
SRCS += source/go_ants.c
SRCS += source/main.c
SRCS += source/read.c
SRCS += source/rooms.c

FLAGS = -I./includes

OBJ = $(SRCS:.c=.o)

all: $(NAME)

newline:
		@echo "\033[38;5;166m\033[0m\n"

$(NAME): $(OBJ)
	make -C libft/libft
	gcc $(FLAGGS) -o $(NAME) $(FLAGS) $(OBJ) libft/libft/libft.a
	echo "lem_in done"

clean:
	make clean -C libft/libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft/libft
	rm -f $(NAME)

re: fclean all
