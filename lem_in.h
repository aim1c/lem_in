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
	t_adcn				*adcn;
}						t_room;

/*
**-------------------------main struct lem_in-----------------------------------
*/

typedef struct			s_lem_in
{
	int					**madcn;		// матрица смежностей;
	int					ants;			// кол-во муравьев;
	t_room				room[];
}						t_lem_in;

/*
**-------------------------parse from file--------------------------------------
*/

int		parse_from_file(t_lem_in *lemin, t_room *room);

#endif
