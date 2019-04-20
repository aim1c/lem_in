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
#define NUM_VERTEX 8

typedef struct		s_lem_in
{
	int				ants;
}					t_lem_in;

typedef struct		s_vertex
{
	char			name;
	int				mark;
	int				cost;
	int				id;
	struct s_node	*list;
}					t_vertex;

typedef struct		s_node
{
	struct s_vertex	*vertex;
	struct s_node	*next;
}					t_node;
struct Queue {
};

#endif //UNTITLED_LEM_IN_H
