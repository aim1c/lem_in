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

#ifndef UNTITLED_LEM_IN_H
#define UNTITLED_LEM_IN_H

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft/libft.h"

typedef struct			s_lem_in
{
	int					ants;
	struct	s_vertex	**graph;
	int					rooms_num;
	t_list				*ways;
}						t_lem_in;

typedef struct			s_vertex
{
	char				*name;
	int					id;
	int					mark;
	int					cost;
	int					x;
	int					y;
	struct s_node		*list;
}						t_vertex;

typedef struct			s_node
{
	struct s_vertex		*vertex;
	struct s_node		*next;
}						t_node;
struct Queue {
};

/*
** ------------------------------ search errors --------------------------------
*/

void 					ft_error(char *line);
void					ft_no_way(t_vertex *end);
void					ft_rooms_errors(t_list *head);

/*
** ------------------------------ create rooms-links list ----------------------
*/

t_list					*ft_add_links(char *first, int fd);

/*
** ------------------------------ search->connect ------------------------------
*/

t_vertex				*ft_find_room(t_vertex **graph, char *name, int num);
void					ft_search_and_connect(t_vertex **graph, char *link, int num);
t_list					*ft_connect_room(t_vertex **graph, char *link, int num, int fd);

/*
** ------------------------------ create rooms, coonect rooms ------------------
*/

t_vertex				*new_vertex(char *name);
void					do_connect(t_vertex* a, t_vertex* b);
void					connect(t_vertex* a, t_vertex* b);

/*
** ------------------------------ print way ------------------------------------
*/

t_list					*pr(t_vertex *vertex);

/*
** ------------------------------ parse_rooms ----------------------------------
*/

char					*ft_read_file(t_lem_in *lemin, int fd);

/*
** ------------------------------ main algo bfs --------------------------------
*/

void					bfs(t_vertex *graph[], int num_rooms);
void	ft_init_cost_mark(t_vertex *room);
#endif //UNTITLED_LEM_IN_H
