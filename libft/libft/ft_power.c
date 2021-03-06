/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 17:59:43 by wqarro-v          #+#    #+#             */
/*   Updated: 2019/02/09 22:59:33 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(int base, int power)
{
	int		i;
	int		number;

	number = 1;
	i = -1;
	while (++i < power)
		number *= base;
	return (number);
}
