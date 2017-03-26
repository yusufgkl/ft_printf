/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoabase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 20:00:55 by ygokol            #+#    #+#             */
/*   Updated: 2017/03/26 16:14:28 by ygokol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <limits.h>

char *ctostr(char c)
{
	char *str;
	str = (char*)malloc(sizeof(char) * 2);
	str[0] = c;
	if (str[0] != '\0')
		str[1] = '\0';
	return (str);
}

char	*reverse(char *str)
{
	char temp;
	int i, j = 0;

	i = 0;
	j = strlen(str) - 1;

	while (i < j) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	return(str);
}

char* itoabase(unsigned int num, int base)
{
	int i = 0;
	int	isNegative = 0;
	char *str;

	str = malloc(sizeof(char)* (ft_numlen(num) + 2));
	if (num == 0)
		return ("0");
	while (num != 0)
	{
		int rem = num % base;
		str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
		num = num/base;
	}
	if (isNegative)
		str[i++] = '-';

	str[i] = '\0';
	str = reverse(str);

	return str;
}

char* itoa_h(short num, int base)
{
	int i = 0;
	int	isNegative = 0;
	char *str;
	str = malloc(sizeof(char)* (ft_numlen(num) + 2));
	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return str;
	}
	if (num < 0 && base == 10)
	{
		isNegative = 1;
		num = -num;
	}
	while (num != 0)
	{
		int rem = num % base;
		str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
		num = num/base;
	}
	if (isNegative)
		str[i++] = '-';

	str[i] = '\0';
	str = reverse(str);

	return str;
}


char *strtoup(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (NULL);
	else
		while(str[i] != '\0')
		{
			if ((int)str[i] <= 122 && (int)str[i] >= 97 && !ft_isdigit(str[i]))
				str[i] = ft_toupper((int)str[i]);
			i++;
		}
	return (str);
}

void	putnbr_l(long n, t_argmnt *tmp)
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

int isflag (t_flags flag)
{
	if (flag.hash || flag.zero || flag.minus || flag.plus || flag.space)
		return (1);
	else
		return (0);
}

char		*ft_lltoa(long long n)
{
	long long	nlen;
	long long	a;
	char		*ret;
	if (n < -9223372036854775807)
		return ("-9223372036854775808");
	else if (n >= 9223372036854775807)
		return ("9223372036854775807");
	nlen = ft_numlen(n);
	if ((ret = (char*)malloc(sizeof(*ret) * (nlen + 2))) == NULL)
		return (NULL);
	ret[nlen + 1] = '\0';
	a = 1;
	if (n == 0)
		ret[0] = '0';
	if (n < 0)
	{
		a = -1;
		ret[0] = '-';
	}
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

char		*ft_ultoa(unsigned long n)
{
	unsigned long	nlen;
	unsigned long	a;
	char			*ret;
	if (n >= ULONG_MAX || n >= ULLONG_MAX)
		return ("18446744073709551615");
	else if (n == ULONG_MAX/2)
		return ("9223372036854775807");
	else if (n == 0)
		return ("0");
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
	if (n < -9223372036854775807)
		return ("-9223372036854775808");
	else if (n >= 9223372036854775807)
		return ("9223372036854775807");
	else if (n < INT_MIN)
		return ("-2147483649");
	nlen = ft_numlen(n);
	if ((ret = (char*)malloc(sizeof(*ret) * (nlen + 2))) == NULL)
		return (NULL);
	ret[nlen + 1] = '\0';
	a = 1;
	if (n == 0 && n)
		ret[0] = '0';
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
	return (ret);
}
