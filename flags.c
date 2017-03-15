/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 15:12:06 by ygokol            #+#    #+#             */
/*   Updated: 2017/03/15 15:27:25 by ygokol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void flag_hashtg(t_argmnt *tmp)
{
	if (tmp->type == 'x')
		tmp->arg = ft_strjoin("0x", tmp->arg);
	if (tmp->type == 'X')
		tmp->arg = ft_strjoin("0X", tmp->arg);
	if (tmp->type == 'o' && tmp->arg[0] != '0')
		tmp->arg = ft_strjoin("0", tmp->arg);
}
