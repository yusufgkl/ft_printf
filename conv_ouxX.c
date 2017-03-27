/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_ouxX.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:32:11 by ygokol            #+#    #+#             */
/*   Updated: 2017/03/27 17:13:18 by ygokol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"



void modif_ouxX(t_argmnt *tmp, va_list ap)
{
	//if (!ft_strcmp(tmp->modif, "h"))
	//	tmp->arg = ctostr((unsigned char)va_arg(ap, char*));
	if (!ft_strcmp(tmp->modif, "hh") && ft_strchr("oOuU", tmp->type))
		tmp->arg = ft_ultoa((unsigned char)va_arg(ap, unsigned int));
	if (!ft_strcmp(tmp->modif, "l"))
		tmp->arg = ft_ultoa((unsigned long)va_arg(ap, unsigned long));
	else if (!ft_strcmp(tmp->modif, "ll"))
		tmp->arg = ft_ultoa((unsigned long long)va_arg(ap, unsigned long long));
	else if (!ft_strcmp(tmp->modif, "j"))
		tmp->arg = ft_ultoa(va_arg(ap, uintmax_t));
	else if (!ft_strcmp(tmp->modif, "z"))
		tmp->arg = ft_ultoa(va_arg(ap, size_t));
}

char	*conv_o(unsigned long long n)
{
	char*str;
	int size;
	unsigned long long x;

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


