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

#include "lem_in.h"

int main(void)
{
	t_lem_in	lemin;
	t_lemin_links lemin_prs_links;

	ft_bzero(&lemin, sizeof(t_lem_in));
	ft_bzero(&lemin_prs_links, sizeof(lemin_prs_links));
	parse_from_file(&lemin, &lemin_prs_links);
	exit(EXIT_SUCCESS);
    return (0);
}