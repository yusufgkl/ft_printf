/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 17:54:40 by ygokol            #+#    #+#             */
/*   Updated: 2017/03/27 19:08:23 by ygokol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_argmnt		*init_struct(t_argmnt *tmp)
{
	tmp->flag.hash = 0;
	tmp->flag.zero = 0;
	tmp->flag.minus = 0;
	tmp->flag.plus = 0;
	tmp->flag.space = 0;
	tmp->width = 0;
	tmp->prec = 0;
	tmp->modif = NULL;
	tmp->type = '\0';
	tmp->arg = NULL;
	tmp->pad = 0;
	return (tmp);
}

int				analyze(const char *format, va_list ap, int *i)
{
	t_argmnt	*tmp;
	int			x;

	x = *i;
	tmp = malloc(sizeof(t_argmnt));
	tmp = init_struct(tmp);
	while (format[x] != '\0' && format[x] == '%')
	{
		if (format[x] == '%')
		{
			x++;
			parse_type(format, tmp, x);
		}
		else
			x++;
	}
	tmp->arg = print_arg(tmp, ap);
	(tmp->arg == NULL && !tmp->prec) ? tmp->arg = "(null)" : tmp->arg;
	if (tmp->type == '\0')
		return (0);
	*i += tmp->pad;
	if ((tmp->type == 'c' || tmp->type == 'C') && tmp->arg[0] == 0)
		return (1);
	return (write(1, tmp->arg, (int)ft_strlen(tmp->arg)));
}

int				is_percent(const char *str, int i)
{
	if (str[i] == '%' && str[i + 1] == '%')
	{
		i++;
		return (1);
	}
	else
		return (0);
}

int				ft_iswildcard(const char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '*' && str[i - 1] == '.')
			return (1);
		if (str[i] == '*' && str[i - 1] == '%')
			return (1);
		i++;
	}
	return (0);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!ft_strcmp(format, "%") || ft_iswildcard(format))
		return (0);
	if (!ft_strchr(format, '%'))
	{
		ft_putstr((char*)format);
		return ((int)ft_strlen((char*)format));
	}
	va_start(ap, format);
	while (format[i] && i <= (int)ft_strlen(format))
	{
		if (format[i] == '%' && format[i + 1] && !is_percent(format, i))
			j += analyze(format, ap, &i);
		else if (!is_percent(format, i))
			j += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (j);
}
