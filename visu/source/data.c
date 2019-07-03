/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsnow-be <fsnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 23:21:35 by aim1c             #+#    #+#             */
/*   Updated: 2019/06/08 18:20:26 by fsnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

t_room	*new_vertex(char *name)
{
	t_room		*r;
	char		**y;
	int			i;

	y = ft_strsplit(name, ' ');
	r = (t_room *)malloc(sizeof(t_room));
	r->name = ft_strdup(y[0]);
	r->x = ft_atoi(y[1]);
	r->y = ft_atoi(y[2]);
	i = -1;
	while (++i < 3)
		free(y[i]);
	free(y);
	return (r);
}

int		while_is_dig(char *s)
{
	int i;
	int size;

	i = 0;
	size = ft_strlen(s);
	while (++i < size)
	{
		if (!ft_isdigit(s[i]))
			return (1);
	}
	return (0);
}

int		return_n(t_data **d)
{
	int		n;
	char 	*l;

	n = 0;
	(*d)->data = (*d)->data_head;
	while ((*d)->data)
	{
		l = (*d)->data->content;
		if (ft_strchr(l, '-'))
			break ;
		if (!ft_strchr(l, '#'))
			n++;
		(*d)->data = (*d)->data->next;
	}
	return (n);
}

t_room **get_rooms(t_data **d, t_full **f)
{
	char	*l;
	t_room	**r;
	int i = 1;

	(*f)->n = return_n(d) - 1;
	r = malloc(sizeof(t_room *) * (*f)->n);
	(*d)->data = (*d)->data_head;
	while ((*d)->data)
	{
		l = (*d)->data->content;
		if (while_is_dig(l))
		{
			if (ft_strstr(l, "##"))
			{
				if (ft_strstr(l, "start"))
				{
					r[0] = new_vertex((*d)->data->next->content);
					(*d)->data = (*d)->data->next->next;
					l = (*d)->data->content;
				}
				if (ft_strstr(l, "end"))
				{
					r[(*f)->n - 1] = new_vertex((*d)->data->next->content);
					(*d)->data = (*d)->data->next->next;
					l = (*d)->data->content;
				}
			}
			if (!ft_strchr(l, '#') && !ft_strchr(l, '-'))
			{
				r[i] = new_vertex(l);
				i++;
			}
		}
		if (i == (*f)->n)
			break ;
		(*d)->data = (*d)->data->next;
	}
	return (r);
}

void	get_full_data(t_full **f, t_data **d)
{
	(*f)->ants = get_value_ants(d);
	if ((*f)->ants == 0)
		exit(EXIT_SUCCESS);
	(*f)->room = get_rooms(d, f);
}

t_mlx	*init_all(void)
{
	t_mlx	*m;

	m = (t_mlx *)malloc(sizeof(t_mlx) + 1);
	m->dat = (t_data *)malloc(sizeof(t_data) + 1);
	m->sdl = (t_sdl *)malloc(sizeof(t_sdl) + 1);
	m->f = (t_full *)malloc(sizeof(t_full) + 1);
	sdl_to_null(&m->sdl);
	return (m);
}

void	exit_warn(char *ln)
{
	ft_printf(ln);
	exit(EXIT_SUCCESS);
}

void	get_lst_data(t_data **d)
{
	char	*ln;

	(*d)->data = NULL;
	(*d)->data_head = NULL;
	while (ft_gnl(0, &ln) > 0)
	{
		if ((*d)->data_head == 0)
		{
			(*d)->data_head = ft_lstnew(ln, ft_strlen(ln) + 1);
			(*d)->data = (*d)->data_head;
		}
		else
		{
			(*d)->data->next = ft_lstnew(ln, ft_strlen(ln) + 1);
			(*d)->data = (*d)->data->next;
		}
	}
}

int		get_value_ants(t_data **d)
{
	int i;
	int len;
	char *l;

	(*d)->data = (*d)->data_head;
	while ((*d)->data)
	{
		len = (int)ft_strlen((*d)->data->content);
		l = (char *)(*d)->data->content;
		i = -1;
		while (++i < len)
		{
			if (!ft_isdigit(l[i]))
				return (0);
		}
		if (i == len)
			return (ft_atoi(l));
		(*d)->data = (*d)->data->next;
	}
	return (0);
}