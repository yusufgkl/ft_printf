/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 19:18:19 by ygokol            #+#    #+#             */
/*   Updated: 2017/03/27 19:25:06 by ygokol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_wputstr(wchar_t *s)
{
	int		i;
	char	*ret;

	i = 0;
	if (s)
	{
		ret = malloc(sizeof(wchar_t*) * 100);
		while (s[i])
		{
			ret = ft_strcat(ret, ft_wputchar((wchar_t)s[i]));
			i++;
		}
		return (ret);
	}
	else
		return (NULL);
}

char		*ft_str(char *s, t_argmnt *tmp)
{
	if (s)
		return (s);
	else if (!s && (tmp->prec || tmp->width))
		return ("");
	else
		return (NULL);
}

void		print_arg_type2(t_argmnt *tmp, va_list ap)
{
	if (tmp->type == 'p')
		tmp->arg = ft_strjoin("0x", conv_p((va_arg(ap, long))));
	if (tmp->type == 'x')
		tmp->arg = itoabase((unsigned int)(va_arg(ap, void*)), 16);
	if (tmp->type == 'X')
		tmp->arg = strtoup(itoabase((unsigned int)(va_arg(ap, void*)), 16));
	if ((tmp->type == 'd' || tmp->type == 'i') && !tmp->modif)
		tmp->arg = ft_itoa(va_arg(ap, int));
	if (tmp->type == 'o')
		tmp->arg = conv_o((va_arg(ap, unsigned long long)));
	if (tmp->type == 'O')
		tmp->arg = conv_o((va_arg(ap, long long)));
	if (tmp->type == 'b')
		tmp->arg = itoabase((int)(va_arg(ap, void*)), 2);
	if (tmp->type == '%')
		tmp->arg = "%";
}

void		print_arg_type(t_argmnt *tmp, va_list ap)
{
	if (tmp->modif)
		print_arg_modif(tmp, ap);
	print_arg_type2(tmp, ap);
	if (tmp->type == 's')
		tmp->arg = ft_str(va_arg(ap, char*), tmp);
	if (tmp->type == 'S')
		tmp->arg = ft_wputstr(va_arg(ap, wchar_t *));
	if (tmp->type == 'u')
		tmp->arg = itoabase((unsigned int)va_arg(ap, unsigned long), 10);
	if (tmp->type == 'U')
		tmp->arg = ft_ultoa(va_arg(ap, uintmax_t));
	if (tmp->type == 'D')
		tmp->arg = ft_ltoa(va_arg(ap, long));
	if (tmp->type == 'c')
		tmp->arg = ctostr((char)va_arg(ap, int));
	if (tmp->type == 'C')
		tmp->arg = ft_wputchar(va_arg(ap, wchar_t));
}

char		*print_arg(t_argmnt *tmp, va_list ap)
{
	if (tmp->type != '\0')
		print_arg_type(tmp, ap);
	if (isflag(tmp->flag) && tmp->arg && tmp->type != 'b')
		print_arg_flag(tmp);
	if (tmp->prec >= 0)
		print_arg_prec(tmp);
	if (tmp->width > 0)
		print_arg_width(tmp);
	return (tmp->arg);
}
