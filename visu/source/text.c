/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsnow-be <fsnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 22:33:28 by aim1c             #+#    #+#             */
/*   Updated: 2019/06/08 16:18:37 by fsnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	text(t_sdl	**s, char *t, int size_f, int x, int y, SDL_Color col)
{
	TTF_Font	*font = TTF_OpenFont("../font.ttf", size_f);
	SDL_Surface *text = TTF_RenderUTF8_Blended(font, t, col);
	SDL_Texture *texture = SDL_CreateTextureFromSurface((*s)->renderer, text);
	SDL_FreeSurface(text);
	text = NULL;
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;

	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
	SDL_RenderCopy((*s)->renderer, texture, NULL, &dest);
	SDL_DestroyTexture(texture);
	texture = NULL;
	TTF_CloseFont(font);
}