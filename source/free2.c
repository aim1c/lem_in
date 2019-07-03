/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsnow-be <fsnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 21:43:10 by masprigg          #+#    #+#             */
/*   Updated: 2019/06/08 19:12:04 by fsnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	free_split(char **split)
{
	ft_strdel(&split[0]);
	ft_strdel(&split[1]);
	free(split);
}

void	crash_links(t_list **links)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (*links == NULL)
		return ;
	tmp = (*links)->next;
	if ((*links)->content)
		free((*links)->content);
	tmp2 = tmp;
	while (tmp2)
	{
		if (tmp2->content)
			free(tmp2->content);
		tmp = tmp2->next;
		free(tmp2);
		tmp2 = tmp;
	}
	free(*links);
	*links = NULL;
}

void	del_nodes(t_node *list)
{
	t_node	*tmp;

	tmp = list;
	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}
