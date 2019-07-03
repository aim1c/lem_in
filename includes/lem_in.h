/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsnow-be <fsnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:32:56 by fsnow-be          #+#    #+#             */
/*   Updated: 2019/06/08 19:11:33 by fsnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNTITLED_LEM_IN_H
# define UNTITLED_LEM_IN_H

# include <stdio.h>
# include "../libft/libft/libft.h"

typedef struct			s_lem_in
{
	int					ants;
	int					var_ant;
	struct s_vertex		**graph;
	int					rooms_num;
	t_list				*ways;
	t_list				*first_links;
	int					max_ways;
	int					max_count;
	int					len_count;
}						t_lem_in;

typedef struct			s_vertex
{
	char				*name;
	int					ant;
	int					id;
	int					mark;
	int					cost;
	int					way;
	int					x;
	int					y;
	struct s_node		*list;
}						t_vertex;

typedef struct			s_node
{
	struct s_vertex		*vertex;
	struct s_node		*next;
}						t_node;

/*
** ----------------------------- al ways ---------------------------------------
*/

t_list					*way_choose(t_lem_in *lemin, t_list **a);
int						next_way(t_vertex *vertex, int max);
void					ft_init_way(t_lem_in *lemin, char *first_link, int fd);
void					save_way(t_lem_in *le, t_list *cur_w, int a);
int						ft_how_way(t_vertex *vertex);

/*
** ---------------------------- get ways ---------------------------------------
*/

t_list					*get_one_way(t_vertex *vertex, int check,
		t_lem_in *lemin);
t_list					*get_full_way(t_lem_in *lemin);
void					get_ways(t_lem_in *lemin, char *first_link, int fd);

/*
** ------------------------------ algo bfs -------------------------------------
*/

int						bfs(t_vertex *graph[], int num_rooms);
void					ft_init_cost_mark(t_vertex *room);
void					do_bfs(t_vertex *vertex, int *count);
void					go_to_next_queue(t_vertex *w, t_node **rear);
t_node					*ft_initialization(t_vertex *ver, int *count,
		t_node **front, t_node **rear);

/*
** ------------------------------ search errors --------------------------------
*/

void					ft_error(char *line);
int						ft_no_way(t_vertex *end);
void					ft_rooms_errors(t_list *head);

/*
** ------------------------------ free -----------------------------------------
*/

void					free_main(t_lem_in *lemin);
void					free_ways(t_list **ways);
void					free_graph(t_lem_in *lemin);
void					free_one_way(void *content, size_t size);

/*
** ------------------------------ free2 ----------------------------------------
*/

void					crash_links(t_list **links);
void					free_split(char	**split);
void					del_nodes(t_node *list);

/*
** --------------------------- ants on way -------------------------------------
*/

void					first_steps(t_lem_in *lemin, int *first_to_wait);
void					go_go_ants(t_lem_in *lemin);
void					go_by_way(t_lem_in *lemin, t_list *way);
void					go_simple_way(t_lem_in *lemin);
void					go_next_ant(t_lem_in *lemin, t_list *way);

/*
** ------------------------------ parse_rooms ----------------------------------
*/

char					*ft_read_file(t_lem_in *lemin, int fd);
t_vertex				**ft_graph_init(int num, t_list *head);
t_list					*ft_head_init(char *line, t_list **head, t_list **new);
int						fff(char *line);

/*
** ------------------------------ create rooms-links list ----------------------
*/

t_list					*ft_add_links(char *first, int fd);
t_vertex				*ft_find_room(t_vertex **graph, char *name, int num);
void					ft_search_and_connect(t_vertex **graph,
		char *link, int num);
t_list					*ft_connect_room(t_vertex **graph,
		char *link, int num, int fd);

/*
** ------------------------------ search->connect ------------------------------
*/

t_vertex				*new_vertex(char *name);
void					do_connect(t_vertex *a, t_vertex *b);
void					connect(t_vertex *a, t_vertex *b);

/*
** ------------------------------ Main -----------------------------------------
*/

t_list					*one_way(t_list *one);
int						check_time(t_lem_in *lemin, t_list *part);
int						zero_last(t_list *cp_ways);

/*
** ---------------------------- parse ants -------------------------------------
*/

void					ft_parse_errors_ants(t_lem_in *lemin, int fd);
int						ft_parse_ants(char *line);
int						ft_rachl(char *line);

/*
** ------------------------------ cp ways --------------------------------------
*/

t_list					*ft_get_cp_way(t_list *tmp);
t_list					*ft_get_fullcp_way(t_list *way);
void					del_usefull_ways(t_lem_in *lemin);
void					delete_at_all(t_lem_in *lemin, int save);

#endif
