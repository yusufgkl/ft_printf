/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 17:54:40 by ygokol            #+#    #+#             */
/*   Updated: 2017/01/14 22:05:10 by ygokol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list		ap;
	int i;
	t_argmnt	*arg;
	t_argmnt	*tmp;
	if (!(arg = (t_argmnt *)malloc(sizeof(t_argmnt))))
		return (-1);
	tmp = arg;
	va_start(ap, format);
	i = 0;
	int x = 0;
	while (i <= (int)va_arg(ap, void*))
	{
		tmp->arg = va_arg(ap, void*);
		if ((char)format[x] == '%')
		{
			tmp->flag[0] = (char)format[x];
			tmp->flag[1] = (char)format[x + 1];
			i++;
		}
		printf("OK\n");
		tmp = tmp->next;
		x++;
		printf("%c", format[x]);
	}
	tmp->next = NULL;
	printf("nb d'arguments: %d\n", i);
	va_end(ap);
	printf("%s, %s/n", tmp->flag, (char*)tmp->arg);
	return (0);
}

int main ()
{
	int i = ft_printf("ok%d %s %p %s", 1, 2 , 3 , "lol");
	//printf("|retour : %d|\n", printf("{%ls}", L"\xF0\x9D\x84\x9E"));
	printf("return: %d\n", i);
	return (0);
}
