/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 00:31:37 by masprigg          #+#    #+#             */
/*   Updated: 2018/11/29 21:17:38 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int	n;

	if (s == NULL)
		return ;
	n = ft_strlen(s);
	if (s != NULL)
	{
		while (n >= 0)
		{
			s[n] = '\0';
			n--;
		}
	}
}
