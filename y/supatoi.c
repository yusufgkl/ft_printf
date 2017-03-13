/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supatoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:22:50 by ygokol            #+#    #+#             */
/*   Updated: 2017/03/13 17:30:33 by ygokol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"


unsigned int foo(const char * s) {
	unsigned int result = 0;
	int c ;
	if ('0' == *s && 'x' == *(s+1)) { s+=2;
		while (*s) {
			result = result << 4;
			if (c=(*s-'0'),(c>=0 && c <=9)) result|=c;
			else if (c=(*s-'A'),(c>=0 && c <=5)) result|=(c+10);
			else if (c=(*s-'a'),(c>=0 && c <=5)) result|=(c+10);
			else break;
			++s;
		}
	}
	return result;
}


int		supatoi(char *str, int base)
{
	char	*p;
	int		i;
	int		neg;
	int		nb;

	p = (char*)str;
	i = 0;
	neg = 1;
	nb = 0;
	while (ft_charblank(p[i]))
		i++;
	if (p[i] == '-' && ft_isdigit(p[i + 1]))
	{
		neg = -1;
		i++;
	}
	if (p[i] == '+' && ft_isdigit(p[i + 1]))
		i++;
	if ((p[i] == '-' || p[i] == '+') && !ft_isdigit(p[i + 1]))
		neg = 0;
	while (ft_isdigit(p[i]))
		nb = nb * base + p[i++] - '0';
	return (nb * neg);
}

int main(void)
{
	printf("%d\n", supatoi("Yusuf", 10));
	printf("%d\n", foo("Yusuf"));
	printf("%d\n", supatoi("Yusuf", 2));
	 printf("%08x\n",foo("0xff"));
	return (0);
}
