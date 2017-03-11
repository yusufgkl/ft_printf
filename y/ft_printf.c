/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 17:54:40 by ygokol            #+#    #+#             */
/*   Updated: 2017/03/11 23:52:33 by ygokol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

void new_node()
{

}

t_argmnt		*analyze(const char *format, va_list *ap, int x)
{
	printf("\n__________ Analyze __________\n");
	t_argmnt	*tmp;
	tmp = malloc(sizeof(t_argmnt));
	while (format[x] != '\0' && format[x] != ' ')
	{
		if (format[x] == '%')
		{
			x++;
			parse_type((char *)format, tmp, x);
			parse_flags(format[x], tmp);
			//parse_modif(format, tmp);
			parse_prec(format, tmp);
			parse_width(format, tmp);
		}
		else
			x++;
	}
	
	printf("\narg: %s \nflag: %c \nprec: %c\nmodif: %s\ntype: %c\n_ _ _ _ _ \n", (char *)tmp->arg, tmp->flag, tmp->prec, (char*)tmp->modif, tmp->type);
	
	if (format[x] != '\0')
		new_node();
	return (tmp);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int i;
	int count;
	t_argmnt *args;

	va_start(ap, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			args = analyze(format, &ap, i);
			i++;
		}
		else
			i += write(1,&format[i],1);
	}
	va_end(ap);
	return (i);
}

int		main ()
{
	int i = ft_printf("\nft_printf: ok123%ls %d %hhs \n", 1, 2 , "lol");
	int j = printf("\nprintf: ok123%d %d %s \n", 1, 2 , "lol");
	//i = ft_printf("%", 1, 2 , 3 , "lol");
	//printf("|retour : %d|\n", printf("{%ls}", L"\xF0\x9D\x84\x9E"));
	printf("return ft_printf: %d\n", i);
	printf("return printf	: %d\n", j);
	return (0);
}
