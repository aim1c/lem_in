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

// creates a new vertex and return pointer to it
t_vertex	*new_vertex(char name)
{
	t_vertex* vertex;
	vertex = (t_vertex*)malloc(sizeof(t_vertex));
	vertex->name = name;
	vertex->list = 0;
	return (vertex);
}
// connect the vertex a to vertex b
// by adding b to a's linked list!
void		do_connect(t_vertex* a, t_vertex* b)
{
	t_node* node;
	node = (t_node*)malloc(sizeof(t_node));
	node->vertex = b;
	node->next = a->list;
	a->list = node;
}
// connects a to b and b to a
void		connect(t_vertex* a, t_vertex* b)
{
	do_connect (a, b);
	do_connect (b, a);
}
// visit function
void		visit(t_vertex* vertex)
{
	printf ("\n%5d. %c\t%d", vertex->mark, vertex->name, vertex->cost);
}

// breadth first search

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
void pr(t_vertex *vertex)
{
	int		*a;
	int		cost;
	int		i;
	t_node	*cur;

	cost = vertex->cost;
	i = cost;
	a = (int *)malloc(sizeof(int) * (cost + 1));
	cur = vertex->list;
	while (vertex->id != 0)
	{
		if (vertex->cost - 1 == cur->vertex->cost)
		{
			a[i] = vertex->id;
			i--;
			vertex = cur->vertex;
			cur = vertex->list;
		}
		else
			cur = cur->next;
	}
	a[0] = vertex->id;
	i = cost;
	while (i >= 0)
	{
		printf("%d->", a[i]);
		i--;
	}
}

void bfs(t_vertex *graph[]) {
	int i;
	int count = 0;
// set all to unvisited
	for (i = 0; i < NUM_VERTEX; i ++) {
		graph[i]->cost = -1;
		graph[i]->mark = 0;
		graph[i]->id = i;
	}
// each vertex bfs it
	for (i = 0; i < NUM_VERTEX; i ++) {
		if (graph[i]->mark == 0) {
			do_bfs (graph[i], &count);
		}
	}
	pr(graph[NUM_VERTEX - 1]);
}
// main function
int main()
{
// create a adjacency list
	t_vertex *graph[NUM_VERTEX] = {
			new_vertex('0'), //[0]
			new_vertex('1'), //[1]
			new_vertex('2'), //[2]
			new_vertex('3'), //[3]
			new_vertex('4'), //[4]
			new_vertex('5'), //[5]
			new_vertex('6'), //[6]
			new_vertex('7'), //[7]
	};
// connect the vertices
	connect(graph[0], graph[1]);
	connect(graph[0], graph[2]);
	connect(graph[1], graph[4]);
	connect(graph[1], graph[3]);
	connect(graph[1], graph[6]);
	connect(graph[2], graph[4]);
	connect(graph[2], graph[3]);
	connect(graph[4], graph[5]);
	connect(graph[6], graph[5]);
	connect(graph[3], graph[7]);
	connect(graph[5], graph[7]);
// depth first search
//	printf ("DFS: ");
//	dfs (graph);
// breadth first search
	printf ("\n\n");
	printf ("BFS: ");
	bfs (graph);
	printf ("\n\nAnd that's it!!");
	return (1);
}