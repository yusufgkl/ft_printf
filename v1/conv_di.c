/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:23:09 by ygokol            #+#    #+#             */
/*   Updated: 2017/03/27 18:58:31 by ygokol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*width_di(t_argmnt *tmp)
{
	if (tmp->width && !isflag(tmp->flag))
		return (ft_strjoin(fill_char((tmp->width - (int)ft_strlen(tmp->arg))
					, ' '), tmp->arg));
	else
		return (tmp->arg);
}

char		*kill_zero(char *str)
{
	int		i;
	int		j;
	char	*ret;

	ret = NULL;
	i = 1;
	j = 0;
	if (str[0] == '0' && str[1])
	{
		ret = malloc(sizeof(char) * ((int)ft_strlen(str) - 1));
		ret[0] = str[i];
		while (str[i] != '\0')
		{
			ret[j] = str[i];
			i++;
			j++;
		}
		return (ret);
	}
	return (str);
}

void		modif_di(t_argmnt *tmp, va_list ap)
{
	if (!ft_strcmp(tmp->modif, "h"))
		tmp->arg = ft_itoa((short int)va_arg(ap, int));
	if (!ft_strcmp(tmp->modif, "hh"))
		tmp->arg = ft_itoa((char)va_arg(ap, long long int));
	if (!ft_strcmp(tmp->modif, "l"))
		tmp->arg = kill_zero(itoabase(va_arg(ap, long int), 10));
	if (!ft_strcmp(tmp->modif, "ll"))
		tmp->arg = ft_ltoa(va_arg(ap, long long int));
	if (!ft_strcmp(tmp->modif, "j"))
		tmp->arg = ft_ltoa(va_arg(ap, intmax_t));
	if (!ft_strcmp(tmp->modif, "z"))
		tmp->arg = ft_ltoa(va_arg(ap, size_t));
}
