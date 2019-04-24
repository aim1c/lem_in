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

t_node		*ft_initialization(t_node *in, t_vertex *ver, int *count)
{
	ver->mark = ++(*count);
	ver->cost = 0;
// initialize a queue, and initialize with vertex.
	in = (t_node*)malloc(sizeof(t_node));
	in->vertex = ver;
	in->next = 0;
	return (in);
}

void		do_bfs(t_vertex *vertex, int* count)
{
	t_node	*initialQueue;
	t_node	*front;
	t_node	*temp;
	t_node	*rear;
	t_node	*p;
	t_vertex *w;
// count = count + 1, mark vertex with count
	initialQueue = ft_initialization(initialQueue, vertex, count);
	front = initialQueue;
	rear  = initialQueue;
// while queue is not empty
	while (front != 0)
	{
// for vertyex w in V adjacent to the front vertex
		p = front->vertex->list;
		while (p != 0)
		{
			w = p->vertex;
// if w is marked with 0
			if (w->mark == 0)
			{
				t_node* nextQueue;
// count = count + 1, mark w with count
				w->mark = ++(*count);
				if (w->cost == -1)
					w->cost = front->vertex->cost + 1;
// add w to queue
				nextQueue = (t_node*)malloc(sizeof(t_node));
				nextQueue->vertex = w;
				nextQueue->next = 0;
				rear->next = nextQueue;
				rear = nextQueue;
			}
			p = p->next;
		}
// remove front vertex from queue
		temp = front;
		front = front->next;
		free (temp);
	}
}

void	ft_init_cost_mark(t_vertex *room)
{
	room->cost = -1;
	room->mark = 0;
}

void bfs(t_vertex *graph[], int num_rooms)
{
	int i;
	int count;
	t_list	*del;

	i = -1;
	count = 0;
	while (++i < num_rooms)
		ft_init_cost_mark(graph[i]);
	i = -1;
	while (++i < num_rooms)
		if (graph[i]->mark == 0)
			do_bfs (graph[i], &count);
	ft_no_way(graph[num_rooms - 1]);
}