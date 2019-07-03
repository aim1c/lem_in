/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_info_block.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aim1c <aim1c@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:29:32 by aim1c             #+#    #+#             */
/*   Updated: 2019/06/02 12:33:40 by aim1c            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	draw_info_texts(t_sdl **s, t_full **f)
{
	text(s, "lem_in", 54, 1060, 30, MAIN_TEXT_COL);
	text(s, "pow. by masprigg && fsnow-be", 12, 1050, 700, MAIN_TEXT_COL);
	text(s, ft_strjoin("Value of ants:     ", ft_itoa((*f)->ants)), 20, 1020, 150, MAIN_TEXT_COL);
	text(s, ft_strjoin("Value of rooms: ", ft_itoa((*f)->n)), 20, 1020, 180, MAIN_TEXT_COL);
	text(s, ft_strjoin("Value of links:    ", ft_itoa((*f)->l)), 20, 1020, 210, MAIN_TEXT_COL);
}

void	draw_lem_in_block(t_sdl **s, t_full **f)
{
	SDL_SetRenderDrawColor((*s)->renderer, 127, 0, 255, 1);
	SDL_RenderFillRect((*s)->renderer, &(*s)->main_block);
	SDL_RenderDrawRect((*s)->renderer, &(*s)->main_block);
	draw_info_texts(s, f);
}