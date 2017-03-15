/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoabase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 20:00:55 by ygokol            #+#    #+#             */
/*   Updated: 2017/03/15 14:51:03 by ygokol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

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

long int conv_o(int n)
{
	long int n1,m=1,rem,ans=0;

	n1=n;
	while(n > 0)
	{
		rem=n%8;
		ans=(rem*m)+ans;
		n=n/8;
		m=m*10;
	}
	return (ans);
}

char* itoabase(int num, int base)
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