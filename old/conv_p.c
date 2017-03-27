#include "ft_printf.h"
#include "libft.h"

static int				switch_hexa(int x)
{
	if (0 <= x && x <= 9)
		return (48 + x		);
	if (x >= 10 && x <= 15)
	{
		x = x - 10;
		return (97 + x);
	}
	return (0);
}

char					*conv_p(unsigned long long n)
{
	char				*str;
	int					size;
	unsigned long long	x;

	x = n;
	size = 0;
	while (x >= 16)
	{
		x /= 16;
		size++;
	}
	str = (char *)malloc(sizeof(str) * (size + 1));
	if (str)
	{
		str[size + 1] = '\0';
		while (size >= 0)
		{
			x = n % 16;
			str[size] = switch_hexa(x);
			n /= 16;
			size--;
		}
	}
	return (str);
}
