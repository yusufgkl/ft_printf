/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 21:37:00 by ygokol            #+#    #+#             */
/*   Updated: 2017/03/27 19:17:06 by ygokol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		parse_prec(const char *chr, t_argmnt *tmp, int i)
{
	int x;

	x = i;
	tmp->prec = 0;
	while ((chr[x] != ' ' || ft_isdigit(chr[x])))
	{
		if (chr[x] == '.' && (chr[x - 1] == '%' || chr[x + 1] == tmp->type))
			tmp->pad++;
		if (ft_isdigit(chr[x]) == 1 && chr[x - 1] == '.')
			tmp->prec = (int)ft_atoi(&chr[x]);
		x++;
	}
	(tmp->prec) ? tmp->pad += (x - 1) : tmp->pad;
	x = 0;
}

void		parse_type2(char chr, t_argmnt *tmp)
{
	if (chr == 'o')
		tmp->type = 'o';
	else if (chr == 'O')
		tmp->type = 'O';
	else if (chr == 'u')
		tmp->type = 'u';
	else if (chr == 'O')
		tmp->type = 'O';
	else if (chr == 'D')
		tmp->type = 'D';
	else if (chr == 'x')
		tmp->type = 'x';
	else if (chr == 'X')
		tmp->type = 'X';
	else if (chr == 'c')
		tmp->type = 'c';
	else if (chr == 'C')
		tmp->type = 'C';
	else if (chr == 'b')
		tmp->type = 'b';
	else if (chr == 'U')
		tmp->type = 'U';
	else if (chr == 'S')
		tmp->type = 'S';
}

void		parse_type(const char *chr, t_argmnt *tmp, int i)
{
	int x;

	x = i;
	while (tmp->type == '\0')
	{
		parse_type2(chr[x], tmp);
		if (chr[x] == 's')
			tmp->type = 's';
		else if (chr[x] == 'p')
			tmp->type = 'p';
		else if (chr[x] == 'd')
			tmp->type = 'd';
		else if (chr[x] == 'D')
			tmp->type = 'D';
		else if (chr[x] == 'i')
			tmp->type = 'i';
		else if (tmp->type == chr[x] &&
				!ft_strchr("dDioOuUxXpbicCsS", tmp->type))
			tmp->arg = ctostr(chr[x]);
		x++;
	}
	x = 0;
	(tmp->type) ? tmp->pad++ : tmp->pad;
	parse_modif(chr, tmp, i);
}

void		parse_modif(const char *chr, t_argmnt *tmp, int x)
{
	int i;

	i = x;
	while (chr[i] != ' ' && chr[i + 1] != '%' && !tmp->modif)
	{
		if (chr[i] == 'h' && chr[i + 1] != 'h')
			tmp->modif = "h";
		if (chr[i] == 'h' && (chr[i + 1] == 'h'))
			tmp->modif = "hh";
		if (chr[i] == 'l' && chr[i + 1] != 'l')
			tmp->modif = "l";
		if (chr[i] == 'l' && chr[i + 1] == 'l')
			tmp->modif = "ll";
		if (chr[i] == 'j')
			tmp->modif = "j";
		if (chr[i] == 'z')
			tmp->modif = "z";
		i++;
	}
	i = 0;
	(tmp->modif) ? tmp->pad += (int)ft_strlen(tmp->modif) : tmp->pad;
	parse_flags(chr, tmp, x);
}

void		parse_flags(const char *chr, t_argmnt *tmp, int i)
{
	int j;

	j = i;
	while ((((chr[j] != ' ' && chr[j] != '%') ||
	(chr[j] == ' ' && chr[j - 1] == '%')) && !ft_isdigit(chr[j - 1]))
	|| ft_strchr("#0- +", chr[j - 1]))
	{
		if (chr[j] == '#')
			tmp->flag.hash = 1;
		if (chr[j] == '0')
			tmp->flag.zero = 1;
		if (chr[j] == '-')
			tmp->flag.minus = 1;
		if (chr[j] == '+')
			tmp->flag.plus = 1;
		if (chr[j] == ' ')
			tmp->flag.space = 1;
		j++;
	}
	j = 0;
	(nb_flags(tmp->flag) > 0) ? tmp->pad += nb_flags(tmp->flag) : tmp->pad;
	(tmp->type == 's' && tmp->flag.plus == 1) ? tmp->flag.plus = 0 : tmp->pad;
	parse_width(chr, tmp, i);
}
