/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_ways.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsnow-be <fsnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 21:51:38 by masprigg          #+#    #+#             */
/*   Updated: 2019/06/08 19:09:32 by fsnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zconf.h>
#include "../includes/lem_in.h"

int		ft_how_way(t_vertex *vertex)
{
	t_node	*cur;
	int		i;

	i = 0;
	cur = vertex->list;
	while (cur)
	{
		i++;
		cur = cur->next;
	}
	return (i);
}

void	save_way(t_lem_in *le, t_list *cur_w, int a)
{
	t_list	*tmp;

	if (!cur_w)
		return ;
	if (!le->ways)
		le->ways = cur_w;
	tmp = le->ways;
	while (tmp->next->content)
		tmp = tmp->next;
	free(tmp->next);
	tmp->next = 0;
}

void	ft_init_way(t_lem_in *lemin, char *first_link, int fd)
{
	int		max;
	t_node	*cur;

	max = 0;
	lemin->first_links = ft_connect_room(lemin->graph,
			first_link, lemin->rooms_num, fd);
	lemin->max_ways = ft_how_way(lemin->graph[0]);
	bfs(lemin->graph, lemin->rooms_num);
	cur = lemin->graph[lemin->rooms_num - 1]->list;
	while (cur)
	{
		if (max < cur->vertex->cost)
			max = cur->vertex->cost;
		cur = cur->next;
	}
	lemin->max_count = max;
}

int		next_way(t_vertex *vertex, int max)
{
	t_node	*cur;
	int		min;

	min = vertex->cost;
	while (min <= max)
	{
		cur = vertex->list;
		while (cur)
		{
			if (cur->vertex->cost == min)
			{
				vertex->cost = min + 1;
				return (0);
			}
			cur = cur->next;
		}
		min++;
	}
	return (1);
}

t_list	*way_choose(t_lem_in *lemin, t_list **a)
{
	crash_links(a);
	if (next_way(lemin->graph[lemin->rooms_num - 1], lemin->max_count))
	{
		bfs(lemin->graph, lemin->rooms_num);
		if (lemin->graph[lemin->rooms_num - 1]->cost < 1)
			return (0);
	}
	return (get_one_way(lemin->graph[lemin->rooms_num - 1], 0, lemin));
}
