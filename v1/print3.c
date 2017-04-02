/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 19:27:41 by ygokol            #+#    #+#             */
/*   Updated: 2017/03/27 20:37:56 by ygokol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		print_arg_width(t_argmnt *tmp)
{
	int	size;

	size = 0;
	size = (tmp->width - (int)ft_strlen(tmp->arg));
	if (tmp->width > 0 && size > 0)
	{
		if (tmp->flag.minus)
			tmp->arg = (ft_strcat(tmp->arg, fill_char(size, ' ')));
		else if (tmp->flag.zero)
			tmp->arg = flag_zero(tmp, size);
		else if (tmp->flag.space)
			tmp->arg = (ft_strcat(fill_char(size, ' '), tmp->arg));
		else if (!isflag(tmp->flag))
			tmp->arg = (ft_strjoin(fill_char(size, ' '), tmp->arg));
	}
}

void		print_arg_modif(t_argmnt *tmp, va_list ap)
{
	if (ft_strchr("di", tmp->type))
		modif_di(tmp, ap);
	if (ft_strchr("ouxX", tmp->type))
		modif_ouxx(tmp, ap);
}

void		print_arg_flag(t_argmnt *tmp)
{
	if (tmp->flag.hash && !ft_strchr("cdinpsu", tmp->type))
		flag_hashtg(tmp);
	else if (tmp->flag.zero && !tmp->width)
		tmp->arg = ft_strjoin("0", tmp->arg);
	else if (tmp->flag.space && tmp->arg[0] != '-' &&
	!tmp->flag.plus && ft_strchr("dDi", tmp->type))
		tmp->arg = ft_strjoin(ctostr(' '), tmp->arg);
	else if (tmp->flag.plus && tmp->arg[0] != '-' && ft_strchr("di", tmp->type))
		tmp->arg = ft_strjoin("+", tmp->arg);
	else if (tmp->flag.minus && tmp->arg[0] != '-' && !tmp->width)
		tmp->arg = (char*)ft_strjoin("-", tmp->arg);
}
