/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_ants.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsnow-be <fsnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 21:57:34 by masprigg          #+#    #+#             */
/*   Updated: 2019/06/08 19:12:05 by fsnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	go_next_ant(t_lem_in *lemin, t_list *way)
{
	int		*id2;
	int		*id1;

	way = way->next;
	while (way->next)
	{
		id1 = way->content;
		id2 = (way->next) ? way->next->content : id1;
		if (!lemin->graph[*id1]->ant)
			return ;
		if (!lemin->graph[*id2]->ant || *id2 == lemin->rooms_num - 1)
			break ;
		way = way->next;
	}
	if (*id2 == lemin->rooms_num - 1)
		lemin->graph[*id2]->ant++;
	else
		lemin->graph[*id2]->ant = lemin->graph[*id1]->ant;
	ft_printf("L%d-%s ", lemin->graph[*id1]->ant,
			lemin->graph[*id2]->name);
	lemin->graph[*id1]->ant = 0;
}

void	go_by_way(t_lem_in *lemin, t_list *way)
{
	int		*id;

	if (!way)
		return ;
	id = way->next->content;
	while (!lemin->graph[*id]->ant && way->next->next->next)
	{
		way = way->next;
		if (way->next)
			id = way->next->content;
	}
	while (lemin->graph[*id]->ant)
		go_next_ant(lemin, way);
}

void	first_steps(t_lem_in *lemin, int *first_to_wait)
{
	t_list	*ways;
	t_list	*curr;
	int		*id;

	ways = lemin->ways;
	while (ways && *first_to_wait <= lemin->ants)
	{
		curr = ways->content;
		curr = curr->next;
		id = curr->content;
		if (!lemin->graph[*id]->ant)
		{
			lemin->graph[*id]->ant = (*first_to_wait)++;
			ft_printf("L%d-%s ", lemin->graph[*id]->ant,
	lemin->graph[*id]->name);
		}
		ways = ways->next;
	}
}

void	go_go_ants(t_lem_in *lemin)
{
	t_list	*curr_way;
	t_list	*cp_way;
	int		*first_to_wait;

	lemin->graph[0]->ant = lemin->ants;
	cp_way = ft_get_fullcp_way(lemin->ways);
	first_to_wait = ft_memalloc(1);
	*first_to_wait = 1;
	while (lemin->graph[lemin->rooms_num - 1]->ant < lemin->ants)
	{
		curr_way = cp_way;
		while (curr_way)
		{
			go_by_way(lemin, curr_way->content);
			curr_way = curr_way->next;
		}
		if (*first_to_wait <= lemin->ants)
			first_steps(lemin, first_to_wait);
		lemin->var_ant = lemin->ants - *first_to_wait + 1;
		del_usefull_ways(lemin);
		ft_printf("\b\n");
		lemin->len_count++;
	}
	free_ways(&cp_way);
	free(first_to_wait);
}

void	go_simple_way(t_lem_in *lemin)
{
	int		first_to_wait;

	first_to_wait = 1;
	while (lemin->graph[lemin->rooms_num - 1]->ant != lemin->ants)
	{
		ft_printf("L%d-%s\n", first_to_wait,
				lemin->graph[lemin->rooms_num - 1]->name);
		lemin->graph[lemin->rooms_num - 1]->ant = first_to_wait++;
	}
}
