/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 19:27:14 by ygokol            #+#    #+#             */
/*   Updated: 2017/03/27 19:27:33 by ygokol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*s_prec(char *str, int prec)
{
	char	*ret;

	ret = malloc(sizeof(char) * (prec + 1));
	if ((int)ft_strlen(str) < prec)
		return (str);
	else
	{
		ft_strncpy(ret, str, prec);
		ret[prec] = '\0';
		return (ret);
	}
}

char		*kill_plus(char *str)
{
	int		i;
	int		j;
	char	*ret;

	ret = NULL;
	i = 1;
	j = 0;
	if (str[0] == '+' && str[1])
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

char		*prec_plus(t_argmnt *tmp)
{
	char	*ret;
	int		size;

	size = 0;
	ret = kill_plus(tmp->arg);
	size = (tmp->prec - (int)ft_strlen(ret));
	if (size > 0 && tmp->prec > 0)
		ret = ft_strjoin(fill_char(size, '0'), ret);
	return (ft_strjoin("+", ret));
}

char		*prec_neg(t_argmnt *tmp)
{
	char	*ret;
	int		size;

	size = 0;
	ret = (ft_itoa(ft_atoi(tmp->arg) * -1));
	size = (tmp->prec - (int)ft_strlen(ret));
	if (size > 0 && tmp->prec > 0)
		ret = ft_strjoin(fill_char(size, '0'), ret);
	return (ft_strjoin("-", ret));
}

void		print_arg_prec(t_argmnt *tmp)
{
	int		size;

	size = 0;
	if (tmp->prec > 0 && tmp->type != 's' && tmp->type != 'S')
	{
		size = (tmp->prec - (int)ft_strlen(tmp->arg));
		if (size > 0 && tmp->prec > 0)
		{
			if (tmp->arg[0] == '-')
				tmp->arg = prec_neg(tmp);
			else if (tmp->arg[0] == '+')
				tmp->arg = prec_plus(tmp);
			else
				tmp->arg = ft_strjoin(fill_char(size, '0'), tmp->arg);
		}
	}
	else if (tmp->prec > 0 && (tmp->type == 's' || tmp->type == 'S'))
		tmp->arg = s_prec(tmp->arg, tmp->prec);
}
