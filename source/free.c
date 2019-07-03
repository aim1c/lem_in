/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsnow-be <fsnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 18:39:39 by masprigg          #+#    #+#             */
/*   Updated: 2019/06/08 19:12:02 by fsnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	free_graph(t_lem_in *lemin)
{
	int		i;

	i = 0;
	while (i < lemin->rooms_num)
	{
		free(lemin->graph[i]->name);
		del_nodes(lemin->graph[i]->list);
		free(lemin->graph[i]);
		i++;
	}
	free(lemin->graph);
}

void	free_one_way(void *content, size_t size)
{
	if (size)
		free(content);
}

void	free_ways(t_list **ways)
{
	t_list	*tmp;
	t_list	*to_free;

	if (!*ways)
		return ;
	tmp = (*ways)->next;
	to_free = (*ways)->content;
	if (*ways == NULL)
		return ;
	ft_lstdel(&to_free, free_one_way);
	while (tmp != NULL)
	{
		to_free = tmp->content;
		ft_lstdel(&to_free, free_one_way);
		free(tmp);
		tmp = tmp->next;
	}
	free(*ways);
	*ways = NULL;
}

void	free_main(t_lem_in *lemin)
{
	free_ways(&lemin->ways);
	crash_links(&lemin->first_links);
	free_graph(lemin);
	free(lemin);
}
