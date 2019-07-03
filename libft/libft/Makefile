# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsnow-be <fsnow-be@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/04 16:00:48 by masprigg          #+#    #+#              #
#    Updated: 2019/06/08 19:11:12 by fsnow-be         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = *.c

all: $(NAME)

$(NAME):
	gcc -c $(SRC)
	ar rc $(NAME) *.o
	ranlib libft.a

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all