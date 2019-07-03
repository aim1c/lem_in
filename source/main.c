/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsnow-be <fsnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:32:56 by fsnow-be          #+#    #+#             */
/*   Updated: 2019/06/08 20:05:12 by fsnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_list	*one_way(t_list *one)
{
	t_list	*cp;
	t_list	*f;

	cp = ft_lstnew(one->content, 4);
	f = cp;
	one = one->next;
	while (one)
	{
		cp->next = ft_lstnew(one->content, 4);
		cp = cp->next;
		one = one->next;
	}
	return (f);
}

int		check_time(t_lem_in *lemin, t_list *part)
{
	int		time;
	t_list	*tmp;

	time = lemin->var_ant / ft_lstsize(part);
	tmp = part;
	while (tmp->next)
		tmp = tmp->next;
	time += ft_lstsize(tmp->content);
	if (lemin->var_ant != ft_lstsize(part) * time)
		time--;
	return (time);
}

int		zero_last(t_list *cp_ways)
{
	if (!cp_ways->next)
		return (1);
	while (cp_ways && cp_ways->next && cp_ways->next->next)
		cp_ways = cp_ways->next;
	if (cp_ways)
	{
		crash_links((t_list**)&cp_ways->next->content);
		free(cp_ways->next);
		cp_ways->next = 0;
	}
	return (0);
}

int		main(void)
{
	int			fd;
	t_lem_in	*lemin;
	char		*first_link;
	int			i;

	fd = 0;
	i = -1;
	lemin = (t_lem_in *)malloc(sizeof(t_lem_in));
	lemin->ways = 0;
	lemin->rooms_num = 0;
	lemin->len_count = 0;
	first_link = ft_read_file(lemin, fd);
	lemin->rooms_num -= 2;
	while (++i < lemin->rooms_num)
		lemin->graph[i]->id = i;
	get_ways(lemin, first_link, fd);
	del_usefull_ways(lemin);
	if (ft_lstsize(lemin->ways->content) < 3)
		go_simple_way(lemin);
	else
		go_go_ants(lemin);
	ft_printf("Result: %d, Ants: %d\n", lemin->len_count, lemin->ants);
	free_main(lemin);
	return (1);
}
