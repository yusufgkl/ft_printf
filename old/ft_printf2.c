/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 17:54:40 by ygokol            #+#    #+#             */
/*   Updated: 2017/03/21 22:05:49 by ygokol           ###   ########.fr       */
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

int is_arg(char c)
{
	char *str = "sSpdDiOouUxXcC%";
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int		analyze(const char *format, va_list ap, int i)
{
	t_argmnt	*tmp;
	int x = i;
	tmp = malloc(sizeof(t_argmnt));
	while (format[x] != '\0' && (format[x] != ' ' || !is_arg(format[x])))
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
	return (write(1, tmp->arg, (int)ft_strlen(tmp->arg)));
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int i;
	int j;
	va_start(ap, format);
	i = 0;
	j = 0;
	if (!ft_strcmp(format, "%"))
		return (-1);
	if (!ft_strchr(format, '%'))
	{
		ft_putstr((char*)format);
		return ((int)ft_strlen((char*)format));
	}
	while (format[i] && i <= (int)ft_strlen(format))
	{
		if (format[i] == '%')
			j += analyze(format, ap, i);
		else if (!is_arg(format[i]))
			j += write(1,&format[i],1);
		i++;
	}
	va_end(ap);
	return (j);
}
