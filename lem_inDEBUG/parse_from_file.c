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

int fd;

int       ft_step_up(char *line)
{
    if (ft_strstr(line, "##start") || ft_strstr(line, "##end"))
        return (1);
    else if (ft_strchr(line, '#'))
        return (0);
    return (1);
}

void	ft_parse_links(char *line, t_lemin_links *pars)
{
	char	*new_line;
	t_list	*cur;

	new_line = line;
	if (!pars->head_links)
	{
		cur = ft_lstnew(new_line, ft_strlen(new_line));
		pars->head_links = cur;
	}
	while (ft_gnl(fd, &new_line) > 0)
	{
		if (ft_step_up(new_line))
		{
			cur->next = ft_lstnew(new_line, ft_strlen(new_line));
			cur = cur->next;
		}
	}
}

void	ft_parse_room_links(t_lem_in *lemin, t_lemin_links *parse_to_val)
{
	char		*line;
	t_list		*cur;

	line = NULL;
	while (ft_gnl(fd, &line) > 0)
	    if (ft_strstr(line, "##start"))
		{
			cur = ft_lstnew(line, 7);
			parse_to_val->head_rooms = cur;
			break ;
		}
	while (ft_gnl(fd, &line) > 0 && parse_to_val->head_rooms)
	{
		if (ft_strchr(line, '-') && ft_step_up(line))
		{
			ft_parse_links(line, parse_to_val);
			return ;
		}
		if (ft_strchr(line, '-') == NULL && ft_step_up(line) == 1)
		{
			!ft_strstr(line, "##end") ? lemin->num_rooms++ : 0;
			cur->next = ft_lstnew(line, ft_strlen(line));
			cur = cur->next;
		}
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
	room->cost = -1;
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
		{
			fill_room_params(&lemin->room[0], cur->next->content, 0, lemin);
			cur = cur->next;
		}
		else if (ft_strstr(cur->content, "##end"))
		{
			fill_room_params(&lemin->room[end], cur->next->content, end, lemin);
			cur = cur->next;
		}
		else if (i < end)
		{
			fill_room_params(&lemin->room[i], cur->content, i, lemin);
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
		if (i == max)
			return (NULL);
		if (ft_strstr(rm[i].name, find))
			return (&rm[i]);
	}
	return (NULL);
}

int	kostil(char *name, char *room_name)
{
	char **av;
	char *validate;
	int		a;
	int		b;

	av = ft_strsplit(name, '-');
	if (ft_strstr(av[0], room_name))
		validate = av[0];
	else
		validate = av[1];
	b = ft_strlen(validate);
	a = ft_strlen(room_name);
	if (ft_strstr(validate, room_name) && a == b)
		return (1);
	return (0);
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
			if (kostil(cur_link->content, room[i].name))
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
	fd = open("/Users/aleksandr/Documents/lem_in/lem_inDEBUG/maps/file.txt", O_RDONLY);
	ft_parse_errors_ants(lemin, fd);												//валидирует муравьев и записывает в limin->ants
	ft_parse_room_links(lemin, lemin_links);									//записывает комнаты и связи в отдельные списки lemin_links
	ft_finale_parse(lemin, lemin_links);										//заносит комнаты и связи в главную структуру (как тебе подавать связи?)
	ft_finale_parse_links(lemin->room, lemin_links->head_links, lemin);
	ft_prints_all_params_roms(lemin);
//	printf("\n%s\n", lemin->room[1].lin_to_room->room->name);
	return (0);
}