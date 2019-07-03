/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aim1c <aim1c@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 22:31:55 by aim1c             #+#    #+#             */
/*   Updated: 2019/05/31 22:32:40 by aim1c            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	let_start(int *en, int *f, t_sdl **s)
{
	SDL_SetRenderDrawColor((*s)->renderer, 255, 102, 0, 1);
	SDL_RenderClear((*s)->renderer);
	text(s, "Enter any button...", 72, 350, 300, MAIN_TEXT_COL);
	SDL_RenderPresent((*s)->renderer);
	while (SDL_PollEvent(&(*s)->e) != 0)
	{
		if ((*s)->e.type == SDL_KEYDOWN)
			*en = 1;
		if ((*s)->e.type == SDL_QUIT)
		{
			*en = 1;
			*f = 1;
		}
	}
}