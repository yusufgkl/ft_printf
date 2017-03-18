/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 15:12:06 by ygokol            #+#    #+#             */
/*   Updated: 2017/03/18 17:53:10 by ygokol           ###   ########.fr       */
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

char *fill_char(int i, char c)
{
	char *zero;
	int x;

	x = 0;
	zero = (char *)malloc(sizeof(char) * (i));
	while (x != i)
	{
		zero[x] = c;
		x++;
	}
	free(zero);
	return (zero);
}

void flag_zero(t_argmnt *tmp)
{
	int i;
	if (tmp->width != 0)
	{
		i = (tmp->width - (ft_strlen(tmp->arg)));
		if (i > 0)
			tmp->arg = ft_strjoin(fill_char(i, '0'), tmp->arg);
	}
}
