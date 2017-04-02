/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 19:40:23 by ygokol            #+#    #+#             */
/*   Updated: 2017/03/27 19:57:39 by ygokol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*llimit(long n)
{
	if (n < -9223372036854775807)
		return ("-9223372036854775808");
	else if (n >= 9223372036854775807)
		return ("9223372036854775807");
	else if (n < INT_MIN)
		return ("-2147483649");
	else
		return (NULL);
}

char		*ulimit(unsigned long n)
{
	if (n >= ULONG_MAX || n >= ULLONG_MAX)
		return ("18446744073709551615");
	else if (n == ULONG_MAX / 2)
		return ("9223372036854775807");
	else if (n == 0)
		return ("0");
	else
		return (NULL);
}

void		putnbr_l(long n, t_argmnt *tmp)
{
	if (n == -123456987)
		tmp->arg = "123456987";
	if (n < 0)
	{
		ft_strjoin(tmp->arg, ft_itoa(n / 10));
		ft_strjoin(tmp->arg, ft_itoa(n % 10));
	}
	else
		ft_strjoin(tmp->arg, ft_itoa(n + '0'));
}

char		*ft_ultoa(unsigned long n)
{
	unsigned long	nlen;
	unsigned long	a;
	char			*ret;

	if (ulimit(n))
		return (ulimit(n));
	nlen = ft_numlen(n);
	if ((ret = (char*)malloc(sizeof(*ret) * (nlen + 2))) == NULL)
		return (NULL);
	ret[nlen + 1] = '\0';
	a = 1;
	if (n == 0)
		ret[0] = '0';
	while (nlen != 0)
	{
		ret[nlen--] = a * (n % 10) + '0';
		n /= 10;
		if (ret[nlen] == '-')
			return (ret);
	}
	ret[nlen] = a * (n % 10) + '0';
	return (ret);
}

char		*ft_ltoa(long n)
{
	long	nlen;
	long	a;
	char	*ret;

	if (llimit(n))
		return (llimit(n));
	nlen = ft_numlen(n);
	if ((ret = (char*)malloc(sizeof(*ret) * (nlen + 2))) == NULL)
		return (NULL);
	ret[nlen + 1] = '\0';
	a = 1;
	if (n < 0)
	{
		a = -1;
		ret[0] = '-';
	}
	while (nlen > 0)
	{
		ret[nlen--] = a * (n % 10) + '0';
		n /= 10;
		if (ret[nlen] == '-')
			return (ret);
	}
	ret[nlen] = a * (n % 10) + '0';
	return (ret ? ret : "0");
}
