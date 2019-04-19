/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:28:41 by null              #+#    #+#             */
/*   Updated: 2019/04/10 13:47:44 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// либа для ошибок

#ifndef LEM_IN_ERROR_H
#define LEM_IN_ERROR_H

# include <stdio.h>

#define CRED     "\x1b[31m"
#define CGREEN   "\x1b[32m"
#define CRESET   "\x1b[0m"

# define BAD_ANT_DATA "NO ONE ANT"
# define ALL_OK "ANTS VALIDATION COMPLETE"
# define ALL_OK_ROOMS "ROOMS VALIDATION COMPLETE"

void	ft_error(char *code);												//вывод ошибки и выход
void	ft_succes(char *code, int ants);

#endif //LEM_IN_ERROR_H
