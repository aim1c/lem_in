# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsnow-be <fsnow-be@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/08 16:05:26 by fsnow-be          #+#    #+#              #
#    Updated: 2019/06/08 19:17:17 by fsnow-be         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../visual

SRCS := source/data.c
SRCS += source/init_sdl.c
SRCS += source/main_info_block.c
SRCS += source/main.c
SRCS += source/strt.c
SRCS += source/text.c

FLAGS = -I./source

OBJ = $(SRCS:.c=.o)

SDL_CFLAGS = $(shell sdl2-config --cflags)
SDL_LDFLAGS = $(shell sdl2-config --libs)
SDL_TTF = -I/Users/fsnow-be/.brew/include/SDL2 -D_THREAD_SAFE
SDL_TTF2 = -L/Users/fsnow-be/.brew/lib -lSDL2_ttf
all: $(NAME)

newline:
		@echo "\033[38;5;166m\033[0m\n"

$(NAME): $(OBJ)
	make -C libft/libft
	gcc -o $(NAME) $(FLAGS) $(OBJ) $(SDL_CFLAGS) $(SDL_LDFLAGS) $(SDL_TTF) $(SDL_TTF2) libft/libft/libft.a
	echo "visu done"

clean:
	make clean -C libft/libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft/libft
	rm -f $(NAME)

re: fclean all