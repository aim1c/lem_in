/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsnow-be <fsnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:54:31 by masprigg          #+#    #+#             */
/*   Updated: 2019/06/08 19:11:59 by fsnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_rachl(char *line)
{
	if (ft_strstr(line, "#"))
		return (0);
	else if (ft_isdigit(*line))
		return (2);
	else
		return (1);
}

int		ft_parse_ants(char *line)
{
	int		ants;
	int		i;
	int		len;

	ants = 0;
	i = 0;
	len = ft_strlen(line);
	if (len)
	{
		if (ft_isdigit(line[i]))
		{
			ants = ft_atoi(&line[i]);
			while (ft_isdigit(line[i]))
				i++;
		}
		if (line[i] == ' ' || line[i] == '\t')
			i++;
		if (line[i] && line[i] != '#')
			return (-1);
	}
	return (ants);
}

void	ft_parse_errors_ants(t_lem_in *lemin, int fd)
{
	char	*line;

	line = NULL;
	lemin->ants = 0;
	while (ft_gnl(fd, &line) > -1 && line && !ft_rachl(line))
		free(line);
	if (line && ft_rachl(line) == 2)
	{
		lemin->ants = ft_parse_ants(line);
		ft_printf("%d\n", lemin->ants);
		lemin->var_ant = lemin->ants;
		ft_strdel(&line);
		if (lemin->ants > 0)
			return ;
	}
	if (lemin->ants < 1)
		ft_error("ANTS ERROR");
}
