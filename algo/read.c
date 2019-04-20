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

int		ft_rachl(char *line)
{
	if (ft_strstr(line, "##start") || ft_strstr(line, "##end"))
		return (1);
	if (ft_strstr(line, "#"))
		return (0);
	else if (ft_strstr(line, "##"))
		return (0);
	return (0);
}

int		ft_parse_double_ants(char *line)
{
	int		ants;
	int		i;
	int		len;

	ants = 0;
	i = -1;
	len = ft_strlen(line);
	while (++i < len)
	{
		if (ft_isdigit(line[i]) && ants == 0)
		{
			ants = ft_atoi(&line[i]);
			while (ft_isdigit(line[i]))
				i++;
		}
		if (ants > 0 && (line[i] == ' ' || line[i] == '\t'))
			while (++i < len)
				if (ft_isdigit(line[i]))
					exit(EXIT_FAILURE);
		i++;
	}
	return (ants);
}

void	ft_parse_errors_ants(t_lem_in *lemin)									//если нет муравьев
{
	char	*line;

	line = NULL;
	lemin->ants = 0;
	while (ft_gnl(0, &line) > -1 && line && !ft_rachl(line))
	{
		lemin->ants = ft_parse_double_ants(line);
		free(line);
		if (lemin->ants > 0)
			return ;
	}
	if (lemin->ants < 1 && ft_rachl(line))
		exit(EXIT_FAILURE);
}