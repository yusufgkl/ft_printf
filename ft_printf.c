/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 17:54:40 by ygokol            #+#    #+#             */
/*   Updated: 2017/01/15 20:03:07 by ygokol           ###   ########.fr       */
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
	while (format[x] != '\0')
	{
		if ((char)format[x] == '%')
		{
			tmp->arg = va_arg(ap, void*);
			tmp->type = (char)format[x + 1];
			printf("type: |%c| nb: %d\n", tmp->type, i);
			if (!(tmp->next = (t_argmnt *)malloc(sizeof(t_argmnt))))
				return (-1);
			tmp = tmp->next;
			i++;
		}
		x++;
	}
	printf("OK\n");
	tmp->next = NULL;
	printf("nb d'arguments: %d\n", i);
	va_end(ap);
	return (0);
}

int main ()
{
	int i = ft_printf("ok%d %s %p %s", 1, 2 , 3 , "lol");
	//printf("|retour : %d|\n", printf("{%ls}", L"\xF0\x9D\x84\x9E"));
	printf("return: %d\n", i);
	return (0);
}
