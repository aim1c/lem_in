/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsnow-be <fsnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:32:56 by fsnow-be          #+#    #+#             */
/*   Updated: 2019/06/08 19:12:00 by fsnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_vertex	*new_vertex(char *name)
{
	t_vertex	*vertex;
	char		**y;
	int			i;

	y = ft_strsplit(name, ' ');
	vertex = (t_vertex*)malloc(sizeof(t_vertex));
	vertex->name = ft_strdup(y[0]);
	vertex->list = 0;
	vertex->way = 0;
	vertex->y = ft_atoi(y[1]);
	vertex->x = ft_atoi(y[2]);
	i = -1;
	while (++i < 3)
		free(y[i]);
	free(y);
	return (vertex);
}

void		do_connect(t_vertex *a, t_vertex *b)
{
	t_node	*node;

	node = (t_node*)malloc(sizeof(t_node));
	node->vertex = b;
	node->next = a->list;
	a->list = node;
}

void		connect(t_vertex *a, t_vertex *b)
{
	do_connect(a, b);
	do_connect(b, a);
}
