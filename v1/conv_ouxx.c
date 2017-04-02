/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_ouxX.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:32:11 by ygokol            #+#    #+#             */
/*   Updated: 2017/03/27 19:00:03 by ygokol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void				modif_ouxx(t_argmnt *tmp, va_list ap)
{
	if (!ft_strcmp(tmp->modif, "hh") && ft_strchr("oOuU", tmp->type))
		tmp->arg = ft_ultoa((unsigned char)va_arg(ap, unsigned int));
	else if (!ft_strcmp(tmp->modif, "h"))
		tmp->arg = ft_ultoa((unsigned short int)(va_arg(ap, unsigned int)));
	else if (!ft_strcmp(tmp->modif, "l"))
		tmp->arg = ft_ultoa(va_arg(ap, unsigned long int));
	else if (!ft_strcmp(tmp->modif, "ll"))
		tmp->arg = ft_ultoa(va_arg(ap, unsigned long long int));
	else if (!ft_strcmp(tmp->modif, "j"))
		tmp->arg = ft_ultoa(va_arg(ap, uintmax_t));
	else if (!ft_strcmp(tmp->modif, "z"))
		tmp->arg = ft_ultoa(va_arg(ap, unsigned long long int));
}

char				*conv_o(unsigned long long n)
{
	char			*str;
	int				size;
	unsigned long	x;

	x = n;
	size = 0;
	while (x > 7)
	{
		x /= 8;
		size++;
	}
	str = (char *)malloc(sizeof(str) * (size + 1));
	if (str)
	{
		str[size + 1] = '\0';
		while (size >= 0)
		{
			x = n % 8;
			str[size] = 48 + x;
			n /= 8;
			size--;
		}
	}
	return (str);
}
