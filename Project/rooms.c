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

t_vertex	*ft_find_room(t_vertex **graph, char *name, int num)
{
	int		i;

	i = -1;
	while (++i < num)
		if (ft_strcmp(graph[i]->name, name) == 0)
			return (graph[i]);
	return (NULL);
}

void ft_search_and_connect(t_vertex **graph, char *link, int num)
{
	char	**rooms;
	t_vertex	*a;
	t_vertex	*b;

	rooms = ft_strsplit(link, '-');
	a = ft_find_room(graph, rooms[0], num);
	b = ft_find_room(graph, rooms[1], num);
	if (a && b)
		connect(a, b);
	free(rooms);
}

t_list	*ft_add_links(char *first, int fd)
{
	t_list	*head;

	if (ft_strchr(first, '-'))
		head = ft_lstnew(first, ft_strlen(first));
	free (first);
	while (ft_gnl(fd, &first) > 0)
	{
		if (ft_strchr(first, '-'))
			ft_lstadd(&head, ft_lstnew(first, ft_strlen(first)));
		free(first);
	}
	return (head);
}

t_list *ft_connect_room(t_vertex **graph, char *link, int num, int fd)
{
	char		*line;
	t_list		*links_head;
	t_list		*cur;

	links_head = ft_add_links(link, fd);
	cur = links_head;
	while (cur)
	{
		ft_search_and_connect(graph, cur->content, num);
		cur = cur->next;
	}
	return (links_head);
}

