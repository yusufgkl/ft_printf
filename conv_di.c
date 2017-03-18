/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:23:09 by ygokol            #+#    #+#             */
/*   Updated: 2017/03/18 20:27:13 by ygokol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void modif_di(t_argmnt *tmp, va_list ap)
{
	if (!ft_strcmp(tmp->modif, "h"))
		tmp->arg = itoa_h((short)va_arg(ap, int), 10);
	if (!ft_strcmp(tmp->modif, "hh"))
		tmp->arg = itoabase((int)va_arg(ap, int), 10);
	if (!ft_strcmp(tmp->modif, "l"))
		tmp->arg = itoabase((long int)va_arg(ap, long), 10);
	if (!ft_strcmp(tmp->modif, "ll"))
		tmp->arg = itoabase((long long)va_arg(ap, long long), 10);
	if (!ft_strcmp(tmp->modif, "j"))
		tmp->arg = itoabase((intmax_t)va_arg(ap, intmax_t), 10);
	if (!ft_strcmp(tmp->modif, "z"))
		tmp->arg = itoabase((int)va_arg(ap, int), 10);
}
