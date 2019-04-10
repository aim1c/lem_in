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

void	parse_double_grid(t_lem_in *lemin, char *line, int *num_elem)			//парсит start и end
{
		*num_elem += 1;

}

void	ft_parse_errors_ants(t_lem_in *lemin)									//если нет муравьев
{
	char *line;

	line = NULL;
	if (ft_gnl(0, &line) > 0 && line && !ft_strchr(line, ' '))					//проверка для gnl
	{
		lemin->ants = ft_atoi(line);											//установка значение ants
		if (lemin->ants < 1)
			ft_error(BAD_ANT_DATA);												//вывод ошибки и выход
	}
	else
		ft_error(BAD_ANT_DATA);													//вывод ошибки и выход
}

int		parse_from_file(t_lem_in *lemin, t_room *room)							//парсит файл и распределяет по функциям
{
	char	*line;																//gnl
	int		num_elem;															//кол-во комнат для элемента структур

	line = NULL;
	num_elem = 0;
	ft_parse_errors_ants(lemin);												//функция для поиска ошибок в муравьях
	while (ft_gnl(0, &line) > 0 && line)
	{
		if (ft_strstr(line, "##start"))
			parse_double_grid(lemin, line, &num_elem);							//функция парсинга start и end
		free(line);
	}
	return (num_elem);
}