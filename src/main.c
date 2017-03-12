/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 10:25:41 by rlambert          #+#    #+#             */
/*   Updated: 2017/02/13 16:25:50 by ygokol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <inttypes.h>
#include <libft.h>
#include <locale.h>
#include <wchar.h>
#include "ft_printf.h"

int	main(void)
{
	char	*test;
	char	c;

	test = "{%c}";
	c = '\0';
	printf("PRINTF :\n");
	printf("%d\n", printf(test, c));
	printf("FT_PRINTF\n");
	printf("%d\n", ft_printf(test, c));
	return (0);
}
