/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 17:54:40 by ygokol            #+#    #+#             */
/*   Updated: 2017/03/10 18:35:33 by ygokol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

int		analyze(const char *format, va_list *ap)
{
	printf("\n__________ Analyze __________\n");
	t_argmnt	*tmp;
	int x = 0;
	tmp = malloc(sizeof(t_argmnt));
	while (format[x] != '\0')
	{
		if (format[x] == '%')
		{
			x++;
			if (format[x] == '%')
				ft_putchar('%');
			parse_type(format[x], tmp);
			parse_flags(format[x], tmp);
			parse_modif(format, tmp);
			parse_prec(format, tmp);
			parse_width(format, tmp);
		}
		else
			ft_putchar(format[x]);
		x++;
	}
	
printf("\n|s_argmnt|\narg: %s \nflag: %c \nprec: %c\nmodif: %d\ntype: %c\n_ _ _ _ _ \n", (char*)tmp->arg, tmp->flag, tmp->prec
		,(int)tmp->modif, tmp->type);
	
	tmp->next = NULL;
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int i;
	int count;
	
	va_start(ap, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && ++i)
		{
			count += analyze(format, &ap);
		}
		else
			i += write(1, &format[i], 1);
	}
	va_end(ap);
	return (count + i);
}

int		main ()
{
	int i = ft_printf("ok%d %#2.5ls %p %s %%", 1, 2 , 3 , "lol");
	//i = ft_printf("%", 1, 2 , 3 , "lol");
	//printf("|retour : %d|\n", printf("{%ls}", L"\xF0\x9D\x84\x9E"));
	printf("return: %d\n", i);
	return (0);
}
