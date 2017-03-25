#include "ft_printf.h"
#include "libft.h"

char *ft_putchar_w(char *mem)
{
	char *str;

	str = mem;
	return (str);
}
static char*		ft_print_special_3(char str[4], wint_t c)
{
	str[0] = (((c &		 0x1c0000) >> 18) + 0xF0);
	str[1] = (((c & 0x03F000) >> 12) + 0x80);
	str[2] = (((c & 0x0Fc0) >> 6) + 0x80);
	str[3] = ((c & 0x003F) + 0x80);
	return (ft_putchar_w(str));
}

static char* ft_print_special_2(char str[4]		, wint_t c)
{
	str[0] = (((c & 0xF000) >> 12) + 0xE0);
	str[1] = (((c & 0x0Fc0) >> 6) + 0x80);
	str[2] = ((c & 0x003F) + 0x80);
	return (ft_putchar_w(str));
}

static char* ft_print_special_1(char str[4], wint_t c)
{
	str[0] = (((c & 0x07c0) >> 6) + 0xc0);
	str[1] = ((c & 0x003F) + 0x80);
	return (ft_putchar_w(str));
}

char *ft_print_special(wint_t c)
{
	char str[4];
	int rt;

	rt = 1;
	if (c <= 0x7F)
		return (ft_putchar_w((char *)&c));
	else if (c <= 0x7FF)
		return (ft_print_special_1(str, c));
	else if (c <= 0xFFFF)
		return (ft_print_special_2(str, c));
	else if (c <= 0x10FFFF)
		return (ft_print_special_3(str, c));
	else
		return ("-1");
}


