/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 17:54:40 by ygokol            #+#    #+#             */
/*   Updated: 2017/03/18 17:42:25 by ygokol           ###   ########.fr       */
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

char		*analyze(const char *format, va_list ap, int x)
{
	//printf("\n__________ Analyze __________\n");
	t_argmnt	*tmp;
	
	tmp = malloc(sizeof(t_argmnt));
	while (format[x] != '\0' && format[x] != ' ')
	{
		if (format[x] == '%' && !is_percent(format, x))
		{
			x++;
			parse_type(format, tmp, x, ap);
		}
		else
			x++;
	}
	//printf("\narg: %s \nflag: |%c| \nprec: %d\nmodif: %s\ntype: %c\nwidth: %d\n_ _ _ _ _ \n", tmp->arg, tmp->flag, tmp->prec, (char*)tmp->modif, tmp->type, tmp->width);
	return (tmp->arg);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int i;
	int flag = 0;
	t_argmnt *args;

	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && flag == 0 && !is_percent(format, i))
		{
			flag = 1;
			ft_putstr(analyze(format, ap, i));
		}
		if (format[i] == ' ' && format[i - 1] != '%')
			flag = 0;
		if ((flag == 0 && format[i] != '%'))
			i += write(1,&format[i],1);
		else if (is_percent(format, i))
			i += write(1, "%", 1);
		else
			i++;
	}
	va_end(ap);
	return (i);
}
