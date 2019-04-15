/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_from_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsnow-be <fsnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 23:01:07 by fsnow-be          #+#    #+#             */
/*   Updated: 2019/04/10 13:51:00 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_print_rooms_links_list(t_list *head)									// проверка на запись в листы
{
	t_list	*current;

	current = head;
	while (current)
	{
		ft_printf(CRESET"%s\n", (char *)current->content);
		current = current->next;
	}
}

void	ft_prints_all_params_roms(t_lem_in *lemin)
{
	char *line = "********************************************************";
	t_adcn *cur;
	int i = -1;
	printf(BLUE"%s\n\t\t START PRINTING ROOMS\n%s\n"CRESET, line, line);
	while (++i < lemin->num_rooms)
	{
		printf(MADJENTA"ROOM ID:%d"CRESET, lemin->room[i].id);
		printf(GREEN"\tROOM NAME:%s"CRESET, lemin->room[i].name);
		printf(RED"\tROOM CCORD: [Y->%d X->%d]\n"CRESET, lemin->room[i].y_ccrd, lemin->room[i].x_ccrd);
		printf("LINKS WITH ROOMS: ");
		cur = lemin->room[i].lin_to_room;
		while (cur->room)
		{
			printf("%s\t", cur->room->name);
			cur = cur->next;
		}
		printf("\n");
	}
}