/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 15:12:06 by ygokol            #+#    #+#             */
/*   Updated: 2017/03/22 18:29:25 by ygokol           ###   ########.fr       */
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
	if ((tmp->type == 'o'|| tmp->type == 'd') && tmp->arg[0] != '0')
		tmp->arg = ft_strjoin("0", tmp->arg);
}

char *fill_char(int i, char c)
{
	char *zero;
	int x;

	x = 0;
	zero = (char *)malloc(sizeof(char) * (i) + 1);
	while (x != i)
	{
		zero[x] = c;
		x++;
	}
	free(zero);
	return (zero);
}

char *flag_zero(t_argmnt *tmp, int size)
{
	if (tmp->width || tmp->prec)
	{
		if (tmp->arg[0] != '-')
			return (ft_strcat(fill_char(size, '0'), tmp->arg));
		else if (tmp->arg[0] == '-')
		{
			tmp->arg = ft_itoa(ft_atoi(tmp->arg) * -1);
			tmp->arg = (ft_strjoin(fill_char(size, '0'), tmp->arg));
			tmp->arg = (ft_strjoin("-", tmp->arg));
			return (tmp->arg);
		}
	}
	return (tmp->arg);
}
