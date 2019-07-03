/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsnow-be <fsnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:32:56 by fsnow-be          #+#    #+#             */
/*   Updated: 2019/06/08 19:11:58 by fsnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_node		*ft_initialization(t_vertex *ver, int *count, t_node **front,
		t_node **rear)
{
	t_node	*in;

	ver->mark = ++(*count);
	ver->cost = 0;
	in = (t_node*)malloc(sizeof(t_node));
	in->vertex = ver;
	in->next = 0;
	*front = in;
	*rear = in;
	return (in);
}

void		go_to_next_queue(t_vertex *w, t_node **rear)
{
	t_node	*next_queue;

	next_queue = (t_node*)malloc(sizeof(t_node));
	next_queue->vertex = w;
	next_queue->next = 0;
	(*rear)->next = next_queue;
	*rear = next_queue;
}

void		do_bfs(t_vertex *vertex, int *count)
{
	t_node	*front;
	t_node	*temp;
	t_node	*rear;
	t_node	*p;

	ft_initialization(vertex, count, &front, &rear);
	while (front != 0)
	{
		p = front->vertex->list;
		while (p != 0)
		{
			if (p->vertex->mark == 0 && p->vertex->way == 0)
			{
				p->vertex->mark = ++(*count);
				if (p->vertex->cost == -1)
					p->vertex->cost = front->vertex->cost + 1;
				go_to_next_queue(p->vertex, &rear);
			}
			p = p->next;
		}
		temp = front;
		front = front->next;
		free(temp);
	}
}

void		ft_init_cost_mark(t_vertex *room)
{
	room->cost = -1;
	room->mark = 0;
}

int			bfs(t_vertex *graph[], int num_rooms)
{
	int i;
	int count;

	i = -1;
	count = 0;
	while (++i < num_rooms)
		ft_init_cost_mark(graph[i]);
	i = -1;
	while (++i < num_rooms)
		if (graph[i]->mark == 0 && graph[i]->way == 0)
			do_bfs(graph[i], &count);
	return (ft_no_way(graph[num_rooms - 1]));
}
