/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_upc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 18:52:23 by ygokol            #+#    #+#             */
/*   Updated: 2017/03/27 18:56:00 by ygokol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_putchar4(wchar_t c, int tab[4])
{
	tab[0] |= 0xC0;
	tab[0] |= (c >> 6);
	tab[1] |= 0x80;
	tab[1] |= (c & 0x3F);
}

static void	ft_wputchar3(wchar_t c, int tab[4])
{
	tab[0] |= 0xE0;
	tab[0] |= (c >> 12);
	tab[1] |= 0x80;
	tab[1] |= ((c >> 6) & 0x3F);
	tab[2] |= 0x80;
	tab[2] |= (c & 0x3F);
}

static void	ft_wputchar2(wchar_t c, int tab[4])
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

char		*ft_wputchar(wchar_t c)
{
	int		nb;
	int		tab[4];
	int		i;
	char	*ret;

	if (sizeof(c) == 1)
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
