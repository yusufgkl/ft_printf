/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 17:54:40 by ygokol            #+#    #+#             */
/*   Updated: 2017/03/18 21:13:44 by ygokol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

int	is_percent(const char *str, int x)
{
	if (str[x] == '%' && str[x - 1] == '%')
		return (1);
	else
		return (0);
}

int		analyze(const char *format, va_list ap, int i)
{
	//printf("\n__________ Analyze __________\n");
	t_argmnt	*tmp;
	int x = i;
	tmp = malloc(sizeof(t_argmnt));
	while (format[x] != '\0' && format[x] != ' ')
	{
		if (format[x] == '%')
		{
			x++;
			parse_type(format, tmp, x, ap);
		}
		else
			x++;
	}
	//printf("\narg: %s \nflag: |%c| \nprec: %d\nmodif: %s\ntype: %c\nwidth: %d\n_ _ _ _ _ \n", tmp->arg, tmp->flag, tmp->prec, (char*)tmp->modif, tmp->type, tmp->width);
	//ft_putstr(tmp->arg);
	return (write(1, tmp->arg, (int)ft_strlen(tmp->arg)));
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int i;
	va_start(ap, format);
	i = 0;
	while (format[i] && i <= (int)ft_strlen(format))
	{
		if (format[i] == '%')
			i += analyze(format, ap, i);
		else
			i += write(1,&format[i],1);
	}
	va_end(ap);
	return (i);
}
