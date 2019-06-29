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

//typedef	struct				s_way
//{
//	int						id;
//	struct		s_vertex	*vertex;
//	struct		s_way		*next;
//}							t_way;
//
//ft_lst_way_new(t_vertex *vertex)
//{
//
//}

t_list	*pr(t_vertex *vertex)
{
	t_list	*a;
	t_node	*cur;

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
	t_list *curr;
	curr = a;
	while (curr)
	{
		ways->content[i] =
		printf("%s->", curr->content);
		curr  = curr->next;
	}
	printf("\n");
	return (a);
}