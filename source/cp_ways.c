/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cp_ways.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsnow-be <fsnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 22:06:54 by masprigg          #+#    #+#             */
/*   Updated: 2019/06/08 19:12:01 by fsnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	delete_at_all(t_lem_in *lemin, int save)
{
	t_list	*cp;

	cp = lemin->ways;
	while (--save)
		cp = cp->next;
	free_ways(&cp->next);
}

void	del_usefull_ways(t_lem_in *lemin)
{
	t_list	*cp;
	int		min;
	int		new;
	int		save;

	cp = ft_get_fullcp_way(lemin->ways);
	min = check_time(lemin, cp);
	save = ft_lstsize(cp);
	while (42)
	{
		if (zero_last(cp))
			break ;
		new = check_time(lemin, cp);
		if (new > min + 3 || save == 1)
			break ;
		if (new <= min)
		{
			min = new;
			save = ft_lstsize(cp);
		}
	}
	free_ways(&cp);
	delete_at_all(lemin, save);
}

t_list	*ft_get_fullcp_way(t_list *way)
{
	t_list	*cp;
	t_list	*r;
	t_list	*tmp;

	tmp = way;
	r = ft_lstnew(0, sizeof(t_list*));
	r->content = one_way(way->content);
	tmp = tmp->next;
	cp = r;
	while (tmp)
	{
		cp->next = ft_lstnew(0, sizeof(t_list*));
		cp->next->content = one_way(tmp->content);
		tmp = tmp->next;
		cp = cp->next;
	}
	return (r);
}

t_list	*ft_get_cp_way(t_list *way)
{
	t_list	*cp;
	t_list	*r;
	t_list	*tmp;

	tmp = way;
	r = ft_lstnew(tmp->content, sizeof(t_list*));
	tmp = tmp->next;
	cp = r;
	while (tmp)
	{
		cp->next = ft_lstnew(tmp->content, sizeof(t_list*));
		tmp = tmp->next;
		cp = cp->next;
	}
	return (r);
}
