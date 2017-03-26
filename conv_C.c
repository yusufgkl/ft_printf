#include "ft_printf.h"
#include "libft.h"



static void ft_putchar4(wchar_t c, int tab[4])
{
	tab[0]	|= 0xC0;
	tab[0] |= (c >> 6);
	tab[1] |= 0x80;
	tab[1] |= (c & 0x3F);
}

static void ft_wputchar3(wchar_t c, int tab[4])
{
	tab[0] |= 0xE0;
	tab[0] |= (c >>		12);
	tab[1] |= 0x80;
	tab[1] |= ((c >> 6) & 0x3F);
	tab[2] |= 0x80;
	tab[2] |= (c & 0x3F);
}

static void ft_wputchar2(wchar_t c, int tab[4])
{
	tab[0] |= 0xF0;
	tab[0] |= (c >> 18);
	tab[1] |= 0x80;
	tab[1] |= ((c >> 12) & 0x3F);
	tab[2] |= 0x80;
	tab[2] |= ((c >> 6) & 0x3F);
	tab[3] |= 0x80;
	tab[3] |= (c & 0x3f);
}

char*		ft_wputchar(wchar_t c)
{
	int nb;
	int tab[4];
	int i;
	char *ret;
	if (sizeof(c) < 4)
		return (ctostr(c));
	ret = malloc(sizeof(char) * 4);
	i = 0;
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = 0;
	nb = ft_strlen(itoabase(c, 2));
	if (nb <= 7)
		tab[0] = (char)c;
	else if (nb <= 11)
		ft_putchar4(c, tab);
	else if (nb <= 16)
		ft_wputchar3(c, tab);
	else
		ft_wputchar2(c, tab);
	while (tab[i])
		ret = ft_strjoin(ret, ctostr(tab[i++]));
	return (ret);
}




/*
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
*/

