/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_from_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsnow-be <fsnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 23:01:07 by fsnow-be          #+#    #+#             */
/*   Updated: 2019/04/10 13:51:00 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	*ft_prs_links(char *line_from_previous, t_list *head_links)
{
	t_list		*current;
	char		*line;

	line = NULL;
	current = ft_lstnew(line_from_previous, ft_strlen(line_from_previous));
	head_links = current;
	while (ft_gnl(0, &line) > 0 && line)
	{
		current->next = ft_lstnew(line, ft_strlen(line));
		current = current->next;
		free(line);
	}
	return (head_links);
}

void	ft_parse_room_links(t_lem_in *lemin, t_lemin_links *parse_to_val)
{
	char		*line;
	t_list		*curren;

	line = NULL;
	lemin->num_rooms = 0;
	if (ft_gnl(0, &line) && line)
	{
		curren = ft_lstnew(line, ft_strlen(line));
		parse_to_val->head_rooms = curren;
	}
	while (ft_gnl(0, &line) && line)
	{
		if (!ft_strchr(line, '#') && !ft_strchr(line, '-'))
			lemin->num_rooms++;
		curren->next = ft_lstnew(line, ft_strlen(line));
		curren = curren->next;
		if (ft_strchr(line, '-'))
		{
			parse_to_val->head_links = ft_prs_links(line, parse_to_val->head_links);
			return ;
		}
		free(line);
	}
}

void	fill_room_params(t_room *room, char *list, int id, t_lem_in *lem)
{
	size_t	tospace;
	int		i;

	tospace = 0;
	i = 0;
	while (list[tospace] != ' ')
		tospace++;
	room->name = (char *)malloc(sizeof(char) * (tospace + 1));
	while (tospace)
	{
		room->name[i] = list[i];
		i++;
		tospace--;
	}
	room->name[i] = 0;
	room->id = id;
	room->y_ccrd = ft_atoi(ft_strchr(list, ' '));
	room->x_ccrd = ft_atoi(ft_strrchr(list, ' '));
}

void	ft_finale_parse(t_lem_in *lemin, t_lemin_links *lin_links)
{
	int		i;
	int		end;
	t_list	*cur;

	i = 1;
	end = lemin->num_rooms - 1;
	lemin->room = (t_room *)malloc(sizeof(t_room) * lemin->num_rooms + 1);
	cur = lin_links->head_rooms;
	while (cur)
	{
		if (ft_strstr(cur->content, "##start"))
			fill_room_params(&lemin->room[0], cur->next->content, 0, lemin);
		else if (ft_strstr(cur->content, "##end"))
			fill_room_params(&lemin->room[end], cur->next->content, end, lemin);
		else if (ft_strstr(cur->content, "#"))
			cur = cur->next;
		else if (i < end)
		{
			fill_room_params(&lemin->room[i], cur->next->content, i, lemin);
			i++;
		}
		cur = cur->next;
	}
}

t_room	*ft_find_rm(t_room *rm, const char *nm, int max, int a)
{
	int		i;
	char	*find;
	char	**av;

	i = -1;
	av = ft_strsplit(nm, '-');
	find = ft_strcmp(av[0], rm[a].name) ? av[0] : av[1];
	while (++i < max)
	{
		if (a == i)
			i++;
		if (ft_strstr(find, rm[i].name))
			return (&rm[i]);
	}
	return (NULL);
}

void	ft_finale_parse_links(t_room *room, t_list *links, t_lem_in *lem)
{
	t_list			*cur_link;
	t_adcn			*cur_adcn;
	int				i;

	i = -1;
	while (++i < lem->num_rooms)
	{
		cur_link = links;
		room[i].lin_to_room = (t_adcn *)malloc(sizeof(t_adcn));
		cur_adcn = room[i].lin_to_room;
		cur_adcn->next = NULL;
		while (cur_link)
		{
			if (ft_strstr(cur_link->content, room[i].name))
			{
				cur_adcn->room = ft_find_rm(room, cur_link->content, lem->num_rooms, i);
				if (!cur_adcn->room)
					break ;
				cur_adcn->next = (t_adcn *)malloc(sizeof(t_adcn));
				cur_adcn = cur_adcn->next;
				cur_adcn->next = NULL;
				cur_adcn->room = NULL;
			}
			cur_link = cur_link->next;
		}
	}
}

int		parse_from_file(t_lem_in *lemin, t_lemin_links *lemin_links)			//парсит файл (с валидацией)
{
	char	*line;																//gnl

	line = NULL;
	ft_parse_errors_ants(lemin);												//валидирует муравьев и записывает в limin->ants
	ft_parse_room_links(lemin, lemin_links);									//записывает комнаты и связи в отдельные списки lemin_links
	ft_finale_parse(lemin, lemin_links);										//заносит комнаты и связи в главную структуру (как тебе подавать связи?)
	ft_finale_parse_links(lemin->room, lemin_links->head_links, lemin);
	ft_prints_all_params_roms(lemin);
	return (0);
}