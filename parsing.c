/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 21:37:00 by ygokol            #+#    #+#             */
/*   Updated: 2017/03/23 14:02:30 by ygokol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void		parse_width(const char *chr, t_argmnt *tmp, int i)
{
	int x = i;
	if (chr[x] == ' ' || chr[x] == '-')
		x++;
	while (ft_isdigit(chr[x]) && (chr[x - 1] != '.'))
	{
		if (ft_isdigit(chr[x]) == 1 && !ft_isdigit(chr[x + 1]) && !ft_isdigit(chr[x - 1]))
			tmp->width = ft_atoi(&chr[x]);
		if (ft_isdigit(chr[x]) && ft_isdigit(chr[x + 1]))
			tmp->width = ft_atoi(ft_strjoin(ctostr(chr[x]), ctostr(chr[x + 1])));
		x++;
	}
	x = 0;
	(tmp->width) != 0 ? tmp->pad++ : tmp->pad;
	(tmp->width) > 9 ? tmp->pad++ : tmp->pad;
	if (tmp->type == '|')
		return ;
	parse_prec(chr, tmp, i);
}

void		parse_prec(const char *chr, t_argmnt *tmp, int i)
{
	int x = i;
	tmp->prec = 0;
	while ((chr[x] != ' ' || ft_isdigit(chr[x])))
	{
		if (ft_isdigit(chr[x]) == 1 && chr[x - 1] == '.')
			tmp->prec = (int)ft_atoi(&chr[x]);
		x++;
	}
	(tmp->prec) ? tmp->pad += x : tmp->pad;
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
	else if (chr == '%')
		tmp->arg = "%";
	else if (chr == 'b')
		tmp->type = 'b';
	else if (chr == 'U')
		tmp->type = 'U';
}
void		parse_type(const char* chr, t_argmnt *tmp, int i)
{
	int x;
	x = i;

	tmp->type = '\0';
	while (tmp->type == '\0')
	{
		parse_type2(chr[x], tmp);
		if (chr[x] == 's')
			tmp->type = 's';
		else if (chr[x] == 'S')
			tmp->type = 'S';
		else if (chr[x] == 'p')
			tmp->type= 'p';
		else if (chr[x] == 'd')
			tmp->type = 'd';
		else if (chr[x] == 'D')
			tmp->type = 'D';
		else if (chr[x] == 'i')
			tmp->type = 'i';
		//else if (ft_isalpha(chr[x]))
		//	tmp->type = chr[x];
		x++;
	}
	if (tmp->type == chr[x])
		tmp->arg = ctostr(chr[x]);

	x = 0;
	(tmp->type) ? tmp->pad++ : tmp->pad;
	parse_modif(chr, tmp, i);
}

void		parse_modif(const char *chr, t_argmnt *tmp, int x)
{
	int i = x;

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
	while ((chr[j] != ' ' || (chr[j] == ' ' && chr[j - 1] == '%')) && !ft_isdigit(chr[j - 1]))
	{
		if (chr[j] == '#')
			tmp->flag.hash  = 1;
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
	(isflag(tmp->flag)) ? tmp->pad ++ : tmp->pad;
	parse_width(chr, tmp, i);
}
/*
void		parse_flags(const char *chr, t_argmnt *tmp, int i)
{
	int j;
	int x;

	j = i;
	x = 0;

	while ((chr[j] != ' ' || (chr[j] == ' ' && chr[j - 1] == '%')) && !ft_isdigit(chr[j - 1]))
	{
		if (chr[j] == '#')
			tmp->flag[x] = '#';
		if (chr[j] == '0')
			tmp->flag[x] = '0';
		if (chr[j] == '-')
			tmp->flag[x] = '-';
		if (chr[j] == '+')
			tmp->flag[x] = '+';
		if (chr[j] == ' ')
			tmp->flag[x] = ' ';
		j++;
		x++;
	}
	j = 0;
	(tmp->flag) ? tmp->pad ++ : tmp->pad;
	parse_width(chr, tmp, i);
}
*/
