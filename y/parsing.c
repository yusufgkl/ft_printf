/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 21:37:00 by ygokol            #+#    #+#             */
/*   Updated: 2017/03/14 20:49:43 by ygokol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_width(const char *chr, t_argmnt *tmp, int i)
{
	int x = i;
	tmp->width = 0;
	while ((chr[x] != ' ' || ft_isdigit(chr[x])) && chr[x - 1] != '.')
	{
		if (ft_isdigit(chr[x]) == 1)
			tmp->width = ft_atoi(&chr[x]);
		x++;
	}
	x = 0;
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
	x = 0;
}

void		parse_arg_type(t_argmnt *tmp, va_list ap)
{
	if (tmp->type == 's')
		tmp->arg = va_arg(ap, char*);
	//if (tmp->type == 'S')
		//tmp->arg = va_arg(ap, char*);
	if (tmp->type == 'p')
		tmp->arg = itoabase((int)(va_arg(ap, void*)), 16);
	if (tmp->type == 'd' || tmp->type == 'i')
		tmp->arg = ft_itoa(va_arg(ap, int));
}

void		parse_type2(char chr, t_argmnt *tmp)
{
	if (chr == 'o')
		tmp->type = 'o';
	if (chr == 'O')
		tmp->type = 'O';
	if (chr == 'u')
		tmp->type= 'u';
	if (chr == 'O')
		tmp->type = 'O';
	if (chr == 'D')
		tmp->type = 'D';
	if (chr == 'x')
		tmp->type = 'x';
	if (chr == 'X')
		tmp->type = 'X';
	if (chr == 'c')
		tmp->type = 'c';
	if (chr == 'c')
		tmp->type = 'C';
	if (chr == '%')
		tmp->type = '%';
}
void		parse_type(const char* chr, t_argmnt *tmp, int i, va_list ap)
{
	int x;
	x = i;

	tmp->type = '\0';
	while (tmp->type == '\0')
	{
		parse_type2(chr[x], tmp);
		if (chr[x] == 's')
			tmp->type = 's';
		if (chr[x] == 'S')
			tmp->type = 'S';
		if (chr[x] == 'p')
			tmp->type= 'p';
		if (chr[x] == 'd')
			tmp->type = 'd';
		if (chr[x] == 'D')
			tmp->type = 'D';
		if (chr[x] == 'i')
			tmp->type = 'i';
		x++;
	}
	x = 0;
	parse_arg_type(tmp, ap);
	parse_modif(chr, tmp, i);
}

void		parse_modif(const char *chr, t_argmnt *tmp, int x)
{
	int i = x;

	tmp->modif = NULL;
	while (chr[i] != ' ' && chr[i + 1] != '%')
	{
		if (chr[i] == 'h')
			tmp->modif = "h";
		if (chr[i] == 'h' && (chr[i + 1] == 'h' || chr[i - 1] == 'h'))
			tmp->modif = "hh";
		if (chr[i] == 'l')
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
	parse_flags(chr, tmp, x);
}

void		parse_flags(const char *chr, t_argmnt *tmp, int i)
{
	int j = i;

	tmp->flag = '.';
	while (chr[j] != ' ' || (chr[j] == ' ' && chr[j - 1] == '%'))
	{
		if (chr[j] == '#')
			tmp->flag = '#';
		if (chr[j] == '0')
			tmp->flag = '0';
		if (chr[j] == '-')
			tmp->flag = '-';
		if (chr[j] == '+')
			tmp->flag = '+';
		if (chr[j] == ' ')
			tmp->flag = ' ';
		j++;
	}
	j = 0;
	parse_width(chr, tmp, i);
}
