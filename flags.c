/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 15:12:06 by ygokol            #+#    #+#             */
/*   Updated: 2017/03/15 16:19:45 by ygokol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void flag_hashtg(t_argmnt *tmp)
{
	if (tmp->type == 'x')
		tmp->arg = ft_strjoin("0x", tmp->arg);
	if (tmp->type == 'X')
		tmp->arg = ft_strjoin("0X", tmp->arg);
	if (tmp->type == 'o' && tmp->arg[0] != '0')
		tmp->arg = ft_strjoin("0", tmp->arg);
}

char *fill_zero(int i)
{
	char *zero;
	int x;

	x = 0;
	zero = (char *)malloc(sizeof(char) * (i + 1));
	while (x != i)
	{
		zero[x] = '0';
		x++;
	}
	return (zero);
}

void flag_zero(t_argmnt *tmp)
{
	int i;
	if (tmp->width != 0)
	{
		i = (tmp->width - (ft_strlen(tmp->arg)));
		if (i > 0)
			tmp->arg = ft_strjoin(fill_zero(i), tmp->arg);
	}
}
