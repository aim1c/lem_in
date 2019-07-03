/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_way.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsnow-be <fsnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 21:36:37 by masprigg          #+#    #+#             */
/*   Updated: 2019/06/08 19:12:04 by fsnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_list	*get_one_way(t_vertex *vertex, int check, t_lem_in *lemin)
{
	t_list		*a;
	t_node		*cur;
	static int	count;

	check ? count = 0 : 0;
	if (check)
		return (NULL);
	cur = vertex->list;
	a = ft_lstnew(&vertex->id, sizeof(int));
	while (vertex->id != 0 && cur)
	{
		if (vertex->cost - 1 == cur->vertex->cost && !cur->vertex->way)
		{
			vertex = cur->vertex;
			cur = vertex->list;
			vertex->id ? vertex->way = count + 1 : 0;
			ft_lstadd(&a, ft_lstnew(&vertex->id, sizeof(int)));
		}
		else
			cur = cur->next;
	}
	if (vertex->id != 0 && !cur)
		return (way_choose(lemin, &a));
	count++;
	return (a);
}

t_list	*get_full_way(t_lem_in *lemin)
{
	int		w;
	t_list	*way;
	t_list	*ways;
	t_list	*first;

	w = 0;
	way = 0;
	ways = ft_lstnew(NULL, 0);
	first = ways;
	while (w < lemin->max_ways)
	{
		if (!(way = get_one_way(lemin->graph[lemin->rooms_num - 1], 0, lemin)))
			break ;
		ways->content = way;
		ways->next = ft_lstnew(NULL, 0);
		ways = ways->next;
		w++;
	}
	return (first);
}

void	get_ways(t_lem_in *lemin, char *first_link, int fd)
{
	t_list		*best;
	t_list		*new;

	ft_init_way(lemin, first_link, fd);
	best = 0;
	while (42)
	{
		new = get_full_way(lemin);
		if (!new || !new->content)
			break ;
		if (best && ft_lstsize(new) > ft_lstsize(best))
			free_ways(&best);
		if (!best)
			best = new;
		else
			free_ways(&new);
		if (ft_lstsize(best) - 1 == lemin->max_ways)
			break ;
	}
	if (new != best)
		free_ways(&new);
	save_way(lemin, best, 1);
}
