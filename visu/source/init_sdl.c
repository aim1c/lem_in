/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aim1c <aim1c@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 00:32:39 by aim1c             #+#    #+#             */
/*   Updated: 2019/05/31 04:12:51 by aim1c            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	sdl_to_null(t_sdl **s)
{
	(*s)->win = NULL;
	(*s)->renderer = NULL;
}

void	init_create(t_sdl **s)
{
	(*s)->win = SDL_CreateWindow("lem_in", SDL_WINDOWPOS_CENTERED,
								 SDL_WINDOWPOS_CENTERED, WI, HI,
								 SDL_WINDOW_SHOWN);
	if ((*s)->win == NULL)
	{
		ft_printf("Could not create window: %s\n", SDL_GetError());
		exit(EXIT_SUCCESS);
	}
	(*s)->renderer = SDL_CreateRenderer((*s)->win, -1, 0);
	(*s)->main_block.x = 1001;
	(*s)->main_block.y = 0;
	(*s)->main_block.w = 280;
	(*s)->main_block.h = 720;
}