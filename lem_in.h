/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsnow-be <fsnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:52:40 by fsnow-be          #+#    #+#             */
/*   Updated: 2019/04/09 23:35:01 by fsnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H

# include "libft/libft/libft.h"
# include "error.h"

# define IGNORE 0
# define START -1
# define END -2
# define UNKNOW -3

/*
**-------------------------need to validation rooms and links-------------------
*/

typedef struct			s_lemin_lists_links
{
	struct	s_list		*head_rooms;
	struct	s_list		*head_links;
}						t_lemin_links;

/*
**-------------------------lists for adjacent rooms-----------------------------
*/

typedef	struct			s_adjacent
{
	struct	s_room		*room;
	struct	s_adjacent	*next;
}						t_adcn;

/*
**-------------------------structure for the room-------------------------------
*/

typedef struct			s_room
{
	int					id;
	char				*name;
	int					y_ccrd;
	int					x_ccrd;
	int					status;
	t_lemin_links		*adcn;
	t_adcn				*lin_to_room;
}						t_room;

/*
**-------------------------main struct lem_in-----------------------------------
*/

typedef struct			s_lem_in
{
	int					**madcn;		// матрица смежностей;
	int					ants;			// кол-во муравьев;
	int					num_rooms;
	t_room				*room;
}						t_lem_in;

/*
**-------------------------parse from file--------------------------------------
*/

int		parse_from_file(t_lem_in *lemin, t_lemin_links *lemin_links);
void	ft_parse_errors_ants(t_lem_in *lemin);
void	ft_print_rooms_links_list(t_list *head);
void	ft_prints_all_params_roms(t_lem_in *lemin);

#endif
