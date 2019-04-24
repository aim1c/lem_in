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

void ft_error(char *line)
{
	printf("%s", line);
	exit(EXIT_FAILURE);
}

void	ft_no_way(t_vertex *end)
{
	if (end->cost == 0)
	{
		printf("NO WAY");
		exit(EXIT_FAILURE);
	}
}

void	ft_rooms_errors(t_list *head)
{
	t_list	*cur;
	int		start;
	int		end;

	start = 0;
	end = 0;
	cur = head;
	if (!head)
		ft_error("NO ROOMS");
	while (cur)
	{
		if (ft_strstr(cur->content, "##start"))
			start++;
		if (ft_strstr(cur->content, "##end"))
			end++;
		cur = cur->next;
	}
	if (start == 0 || end == 0)
		ft_error("NO START/END");
	else if (start > 1 || end > 1)
		ft_error("MANY START/END");
}