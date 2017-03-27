/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 19:54:36 by ygokol            #+#    #+#             */
/*   Updated: 2017/03/27 19:56:03 by ygokol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			isflag(t_flags flag)
{
	if (flag.hash || flag.zero || flag.minus || flag.plus || flag.space)
		return (1);
	else
		return (0);
}

char		*ctostr(char c)
{
	char *str;

	str = (char*)malloc(sizeof(char) * 2);
	str[0] = c;
	if (str[0] != '\0')
		str[1] = '\0';
	return (str);
}
