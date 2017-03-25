/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:23:09 by ygokol            #+#    #+#             */
/*   Updated: 2017/03/23 13:27:06 by ygokol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <limits.h>

char *width_di(t_argmnt *tmp)
{
	if (tmp->width && !isflag(tmp->flag))
		return (ft_strjoin(fill_char((tmp->width - (int)ft_strlen(tmp->arg))
					, ' '), tmp->arg));
	else
		return (tmp->arg);
}

void modif_di(t_argmnt *tmp, va_list ap)
{
	if (!ft_strcmp(tmp->modif, "h"))
		tmp->arg = ft_itoa((short)va_arg(ap, int));
	if (!ft_strcmp(tmp->modif, "hh"))
		tmp->arg = ft_itoa((char)va_arg(ap, int));
	if (!ft_strcmp(tmp->modif, "l"))
		tmp->arg = ft_ltoa(va_arg(ap, long));
	if (!ft_strcmp(tmp->modif, "ll"))
		tmp->arg = ft_ltoa(va_arg(ap, long long));
	if (!ft_strcmp(tmp->modif, "j"))
		tmp->arg = ft_itoa(va_arg(ap, intmax_t));
	if (!ft_strcmp(tmp->modif, "z"))
		tmp->arg = ft_itoa(va_arg(ap, ssize_t));
}
