/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 19:54:16 by ygokol            #+#    #+#             */
/*   Updated: 2017/03/27 19:54:29 by ygokol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*reverse(char *str)
{
	char	temp;
	int		i;
	int		j;

	i = 0;
	j = strlen(str) - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	return (str);
}

char		*itoabase(unsigned int num, int base)
{
	int		i;
	int		isnegative;
	char	*str;
	int		rem;

	i = 0;
	isnegative = 0;
	str = malloc(sizeof(char) * (ft_numlen(num) + 2));
	if (num == 0)
		return ("0");
	while (num != 0)
	{
		rem = num % base;
		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num = num / base;
	}
	if (isnegative)
		str[i++] = '-';
	str[i] = '\0';
	str = reverse(str);
	return (str);
}

char		*strtoup(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	else
		while (str[i] != '\0')
		{
			if ((int)str[i] <= 122 && (int)str[i] >= 97 && !ft_isdigit(str[i]))
				str[i] = ft_toupper((int)str[i]);
			i++;
		}
	return (str);
}

int			nb_flags(t_flags f)
{
	int i;

	i = 0;
	if (f.hash)
		i++;
	if (f.zero)
		i++;
	if (f.minus)
		i++;
	if (f.plus)
		i++;
	if (f.space)
		i++;
	return (i);
}
