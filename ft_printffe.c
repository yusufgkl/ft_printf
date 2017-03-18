/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 17:54:40 by ygokol            #+#    #+#             */
/*   Updated: 2017/03/18 17:53:12 by ygokol           ###   ########.fr       */
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

int		main ()
{
	ft_printf(" \n \n %ls \n \n","  😊  Ȁ❤ ☀ ☆ ☂ ☻ ♞ ☯ ☭ ☢ € → ༼ つ ◕_◕ ༽つAMENO༼ つ ◕_◕ ༽つ 繁体字 / 繁體字 ( ͡° ͜ʖ ͡°)");
	ft_printf("test c: %c", 'a');
	printf("\n__\n");
	char *ptr = "Hello world!";
	char *np = 0;
	int i = 5;
	unsigned int bs = sizeof(int)*8;
	int mi;
	char buf[80];

	mi = (1 << (bs-1)) + 1;
	ft_printf("\n%s\n", ptr);
	ft_printf("printf test\n");
	ft_printf("%s is null pointer\n", np);
	ft_printf("%d = 5\n", i);
	ft_printf("%d = - max int\n", mi);
	ft_printf("char %c = 'a'\n", 'a');
	ft_printf("hex %x = ff\n", 0xff);
	ft_printf("hex %02x = 00\n", 0);
	ft_printf("\nsigned %d = unsigned %u = hex %x\n", -3, -3, -3);
	printf("\nprintf : signed %d = unsigned %u = hex %x\n", -3, -3, -3);
	ft_printf("\n");
	ft_printf("%d %s(s) with %%\n", 0, "message");


	return (0);
}
