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

t_list *pr(t_vertex *vertex)
{
	t_list *a;
	int cost;
	int i;
	t_node *cur;

	cost = vertex->cost;
	i = cost;
	cur = vertex->list;
	a = ft_lstnew(vertex->name, ft_strlen(vertex->name) + 1);
	while (vertex->id != 0)
	{
		if (vertex->cost - 1 == cur->vertex->cost)
		{
			vertex = cur->vertex;
			cur = vertex->list;
			ft_lstadd(&a, ft_lstnew(vertex->name,
									ft_strlen(vertex->name) + 1));
		} else
			cur = cur->next;
	}
	t_list *cur_a;
	cur_a = a;
	while (cur_a)
	{
		printf("%s->", cur_a->content);
		cur_a = cur_a->next;
	}
	printf("\n");
	return (a);
}