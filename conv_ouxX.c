/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_ouxX.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:32:11 by ygokol            #+#    #+#             */
/*   Updated: 2017/03/17 20:41:03 by ygokol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void modif_ouxX(t_argmnt *tmp, va_list ap)
{
	if (!ft_strcmp(tmp->modif, "h"))
		tmp->arg = ctostr((unsigned char)va_arg(ap, char*));
	else if (!ft_strcmp(tmp->modif, "hh"))
		tmp->arg = itoa_h((unsigned short)va_arg(ap, int), 10);
	else if (!ft_strcmp(tmp->modif, "l"))
		tmp->arg = itoa_h((unsigned long)va_arg(ap, unsigned long), 10);
	else if (!ft_strcmp(tmp->modif, "ll"))
		tmp->arg = itoa_h((unsigned long long)va_arg(ap, unsigned long long), 10);
	else if (!ft_strcmp(tmp->modif, "j"))
		tmp->arg = itoa_h((uintmax_t)va_arg(ap, uintmax_t), 10);
	else if (!ft_strcmp(tmp->modif, "z"))
		tmp->arg = itoa_h((size_t)va_arg(ap, size_t), 10);
}
