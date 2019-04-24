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

// breadth first search

// main function

int	ft_how_way(t_vertex *vertex)
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

int		  ft_overlap(char **a, t_list *way)
{
	t_list	*cur;
	char	*my;

	cur = way;
	cur = cur->next;
	while (cur->next)
	{
		if (ft_strcmp(a[0], cur->content) == 0 || ft_strcmp(a[1], cur->content) == 0)
			return (1);
		cur = cur->next;
	}
	return (0);
}

t_list *dell_all(t_list *links, t_vertex *graph[], int num, t_list *way)
{
	int		i;
	t_list	*cur_links;
	t_list	*new;

	i = -1;
	cur_links = links;
	new = NULL;
	while (++i < num)
	{
		ft_init_cost_mark(graph[i]);
		graph[i]->list = 0;
	}
	while (cur_links)
	{
		if (!ft_overlap(ft_strsplit(cur_links->content, '-'), way))
		{
			if (!new)
				new = ft_lstnew(cur_links->content, ft_strlen(cur_links->content));
			else
				ft_lstadd(&new, ft_lstnew(cur_links->content, ft_strlen(cur_links->content)));
		}
		cur_links = cur_links->next;
	}
	free(links);
	while (new)
	{
		ft_search_and_connect(graph, new->content, num);
		new = new->next;
	}
	return (new);
}

int main(int argc, char **argv)
{
	int fd = open(argv[1], O_RDONLY);
	t_lem_in	*lemin;
	char		*first_link;
	int			i;
	t_list		*links_list;
	t_list		*way;

	i = -1;
	lemin = (t_lem_in *)malloc(sizeof(t_lem_in));
	first_link = ft_read_file(lemin, fd);
	lemin->rooms_num -= 2;
	while (++i < lemin->rooms_num)
		lemin->graph[i]->id = i;
	links_list = ft_connect_room(lemin->graph, first_link, lemin->rooms_num, fd);
	i = ft_how_way(lemin->graph[0]) + 1;
	while (--i != 0)
	{
		bfs(lemin->graph, lemin->rooms_num);
		way = pr(lemin->graph[lemin->rooms_num - 1]);
		links_list = dell_all(links_list, lemin->graph, lemin->rooms_num, way);
		free(way);
	}
	printf("\n");
	return (1);
}