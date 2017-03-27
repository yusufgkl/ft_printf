/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 19:14:59 by ygokol            #+#    #+#             */
/*   Updated: 2017/03/27 19:16:44 by ygokol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		parse_width(const char *chr, t_argmnt *tmp, int i)
{
	int x;

	x = i;
	if (chr[x] == ' ' || chr[x] == '-')
		x++;
	while (ft_isdigit(chr[x]) && (chr[x - 1] != '.'))
	{
		if (ft_isdigit(chr[x]) == 1 && !ft_isdigit(chr[x + 1])
			&& !ft_isdigit(chr[x - 1]))
			tmp->width = ft_atoi(&chr[x]);
		if (ft_isdigit(chr[x]) && ft_isdigit(chr[x + 1]))
			tmp->width = ft_atoi(ft_strjoin(ctostr(chr[x]),
			ctostr(chr[x + 1])));
		x++;
	}
	x = 0;
	(tmp->width) != 0 ? tmp->pad++ : tmp->pad;
	(tmp->width) > 9 ? tmp->pad++ : tmp->pad;
	if (tmp->type == '|')
		return ;
	parse_prec(chr, tmp, i);
}
