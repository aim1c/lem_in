/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsnow-be <fsnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:32:56 by fsnow-be          #+#    #+#             */
/*   Updated: 2019/04/10 13:00:58 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_adcn	*ft_parent_init(t_lem_in *lemin)
{
	t_adcn	*current_parent;

	current_parent = (t_adcn *)malloc(sizeof(t_adcn));
	current_parent->next = (t_adcn *)malloc(sizeof(t_adcn));
	lemin->room[0].cost = 0;
	current_parent->room = &lemin->room[0];
	current_parent->next->room = NULL;
	return (current_parent);
}

t_adcn	*ft_give_way(t_adcn *way, t_adcn *start)
{
	t_adcn *cur;
	t_adcn *pred;
	cur = way->room->lin_to_room;
	pred = way;
	while (cur->room)
	{
		if (cur->room->step == 0)
			return (cur);
		if (cur->next->room)
			cur = cur->next;
		else
			return (start);
	}
	return (start);
}

void	ft_cost(t_adcn *rm, int cost)
{
	t_adcn *cur;

	cur = rm->room->lin_to_room;
	while (cur->room)
	{
		if (cur->room->cost == -1)
			cur->room->cost = cost + 1;
		else if (cur->room->cost > cost + 1)
			cur->room->cost = cost + 1;
		else
			cur->room->cost = cur->room->cost;
		if (cur->next->room)
			cur = cur->next;
		else
			return ;
	}
}

void	ft_lee_bsd(t_lem_in *lemin)
{
	t_adcn *parent;
	t_adcn *parent_head;
	t_adcn *prev_parent;
	t_adcn *start;

	start = ft_parent_init(lemin);
	parent = start;
	while (lemin->room[lemin->num_rooms - 1].cost == -1)
	{
		parent_head = parent;
		while (parent->room)
		{
			ft_cost(parent, parent->room->cost);
			if (parent->next->room)
				parent = parent->next;
			else
				break ;
		}
		prev_parent = parent;
		parent = ft_give_way(parent, start);
	}
}

void	ft_way(t_lem_in *lemin)
{
	int		way[lemin->room[lemin->num_rooms - 1].cost + 1];
	t_adcn	*cur;
	t_adcn	*head;
	t_room	*room;
	int		i;

	room = &lemin->room[lemin->num_rooms - 1];
	i = lemin->room[lemin->num_rooms - 1].cost;
	cur = room->lin_to_room;
	while (i >= 0)
	{
		if (room->cost - 1 == cur->room->cost)
		{
			way[i] = room->id;
			i--;
			room = cur->room;
			cur->next->room = NULL;
		}
		if (cur->next->room)
			cur = cur->next;
		else
			cur = room->lin_to_room;
		if (room->id == 0)
		{
			way[0] = room->id;
			break ;
		}

	}
	while (i <= lemin->room[lemin->num_rooms - 1].cost)
	{
		printf("%s->", lemin->room[way[i]].name);
		i++;
	}
}

int		main(void)
{
	t_lem_in	lemin;
	t_lemin_links lemin_prs_links;

	ft_bzero(&lemin, sizeof(t_lem_in));
	ft_bzero(&lemin_prs_links, sizeof(lemin_prs_links));
	parse_from_file(&lemin, &lemin_prs_links);
	ft_lee_bsd(&lemin);
//	int i = 0;
//	printf("%d\n", lemin.num_rooms);
//	while (i < lemin.num_rooms)
//	{
//		printf("%s\t%d\n", lemin.room[i].name, lemin.room[i].cost);
//		i++;
//	}
	ft_way(&lemin);
	exit(EXIT_SUCCESS);
    return (0);
}