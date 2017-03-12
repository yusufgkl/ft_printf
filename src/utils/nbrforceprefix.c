/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbrforceprefix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 13:05:02 by rlambert          #+#    #+#             */
/*   Updated: 2015/11/12 18:02:02 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include "utils.h"

ssize_t	ft_printf_nbrforceprefix(uintmax_t nbr,
		char *base, t_arg *arg, char *prefix)
{
	unsigned	nbr_len;
	size_t		nbr_cut;

	nbr_len = ft_printf_calc_nbrstrlen(nbr, base, NULL, arg) +
		ft_strlen(prefix);
	nbr_cut = ft_strlen(prefix);
	if (arg->got_width && !arg->right_pad && !arg->pad_zeroes)
	{
		ft_printf_width_pad(nbr_len, arg->width, ' ');
		nbr_cut += ft_max(arg->width - nbr_len, 0);
		arg->got_width = 0;
	}
	else if (arg->got_width)
		arg->width -= ft_strlen(prefix);
	ft_putstr(prefix);
	return (ft_printf_handle_uint(nbr, arg, base, NULL) + nbr_cut);
}
