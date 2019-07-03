/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsnow-be <fsnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:53:59 by masprigg          #+#    #+#             */
/*   Updated: 2019/06/08 19:12:28 by fsnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			fff(char *line)
{
	int		i;
	int		size;
	char	*sp1;
	char	*sp2;

	sp1 = ft_strchr(line, ' ');
	sp2 = 0;
	if (sp1)
		sp2 = ft_strchr(sp1 + 1, ' ');
	if (ft_strstr(line, "##start"))
		return (2);
	if (ft_strstr(line, "##end"))
		return (3);
	if (ft_strchr(line, '#'))
		return (0);
	if (!sp1 || !sp2)
		return (0);
	i = -1;
	size = (int)ft_strlen(line);
	while (++i < size)
		if ((ft_isdigit(line[i]) || ft_isalpha(line[i])) && ft_atoi(sp1) > -1 &&
			ft_atoi(sp2) > -1)
			return (1);
	return (0);
}

t_list		*ft_head_init(char *line, t_list **head, t_list **new)
{
	*head = ft_lstnew(line, ft_strlen(line) + 1);
	*new = *head;
	return (*head);
}

t_vertex	**ft_graph_init(int num, t_list *head)
{
	char		*name;
	int			i;
	t_vertex	**graph;

	graph = (t_vertex **)malloc(sizeof(t_vertex *) * num);
	i = 1;
	while (head)
	{
		name = head->content;
		if (!ft_strstr(name, "##"))
		{
			graph[i] = new_vertex(name);
			i++;
			head = head->next;
		}
		else
		{
			if (ft_strstr(name, "##start"))
				graph[0] = new_vertex(head->next->content);
			else if (ft_strstr(name, "##end"))
				graph[num - 1] = new_vertex(head->next->content);
			head = head->next->next;
		}
	}
	return (graph);
}

char		*ft_read_file(t_lem_in *lemin, int fd)
{
	char	*line;
	t_list	*head;
	t_list	*new;

	head = 0;
	ft_parse_errors_ants(lemin, fd);
	while (ft_gnl(fd, &line) && !ft_strchr(line, '-'))
	{
		if (fff(line) && ++lemin->rooms_num)
		{
			if (!head)
				ft_head_init(line, &head, &new);
			else
			{
				new->next = ft_lstnew(line, ft_strlen(line) + 1);
				new = new->next;
			}
		}
		ft_printf("%s\n", line);
		ft_strdel(&line);
	}
	ft_rooms_errors(head);
	lemin->graph = ft_graph_init(lemin->rooms_num - 2, head);
	crash_links(&head);
	return (line);
}
