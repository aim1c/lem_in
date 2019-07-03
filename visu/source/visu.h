/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsnow-be <fsnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 23:24:07 by fsnow-be          #+#    #+#             */
/*   Updated: 2019/06/08 16:24:02 by fsnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_VISU_H
#define VISU_VISU_H

# include "../libft/libft/libft.h"
# include "/Users/fsnow-be/.brew/Cellar/sdl2/2.0.9_1/include/SDL2/SDL.h"
# include "/Users/fsnow-be/.brew/Cellar/sdl2/2.0.9_1/include/SDL2/SDL_ttf.h"

# define WI 1280
# define HI 720
# define MAIN_TEXT_COL (SDL_Color){250, 250, 250}

/*
** -------------------------- Struct with SDL2 structs -------------------------
 * ------------win		-> main window
 * ------------renderer	-> backgrond and reload images
 * ------------e		-> struct with events
*/

typedef struct		s_sdl
{
	SDL_Window		*win;
	SDL_Renderer	*renderer;
	SDL_Event		e;
	SDL_Rect		main_block;
	SDL_Point		*p;
}					t_sdl;

/*
** -------------------------- Save data, from lem_in ---------------------------
*/

typedef struct		s_data
{
	t_list			*data;
	t_list			*data_head;
	int				n;
	int				l;
}					t_data;

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
}					t_room;

typedef	struct		s_levels
{
	int				main_level;
	int				cur;
	int				mod;
}					t_levels;

typedef struct		s_ant
{
	char			*name;
	SDL_Rect		d;
	SDL_Rect		p;
}					t_ant;

typedef struct		s_full
{
	int 			ants;
	int				n;
	int				l;
	t_room			**room;
	t_ant			**anta;
}					t_full;
/*
** -------------------------- Main struct --------------------------------------
*/

typedef struct		s_mlx
{
	t_sdl			*sdl;
	t_data			*dat;
	t_full			*f;
}					t_mlx;

t_mlx				*init_all(void);
void				exit_warn(char *ln);
void				get_lst_data(t_data **d);
int					get_value_ants(t_data **d);
void				get_full_data(t_full **f, t_data **d);
t_room				**get_rooms(t_data **d, t_full **f);

/*
** -------------------------- SDL ----------------------------------------------
*/
void				sdl_to_null(t_sdl **s);
void				init_create(t_sdl **s);
void				draw_info_texts(t_sdl **s, t_full **f);
void				text(t_sdl	**s, char *t, int size_f, int x, int y, SDL_Color col);
void				let_start(int *en, int *f, t_sdl **s);
void				draw_lem_in_block(t_sdl **s, t_full **f);
#endif
