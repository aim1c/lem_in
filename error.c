/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:30:25 by null              #+#    #+#             */
/*   Updated: 2019/04/10 13:42:55 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include <stdlib.h>

void	ft_error(char *code)
{
	printf(CRED"ERROR: %s\n"CRESET, code);
	exit(EXIT_FAILURE);
}

void	ft_succes(char *code, int ants)
{
	printf(CGREEN"%s:%5d\n"CRESET, code, ants);
}