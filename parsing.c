/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 21:37:00 by ygokol            #+#    #+#             */
/*   Updated: 2017/03/16 01:12:07 by ygokol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void parse_arg_modif(t_argmnt *tmp)
{
	char typeu;

	typeu = tmp->type;
	//if (ft_strcmp(tmp->modif,"h") == 0)
		//tmp->arg = (short)tmp->arg;
}

void parse_arg_flag(t_argmnt *tmp)
{
	if (tmp->flag == '#')
		flag_hashtg(tmp);
	if (tmp->flag == '0')
		flag_zero(tmp);
	if (tmp->flag == ' ')
		tmp->arg = ft_strjoin(fill_char(tmp->width, ' '), tmp->arg);
	//parse_arg_modif(tmp);
}

void		parse_arg_type(t_argmnt *tmp, va_list ap)
{
	if (tmp->type == 's')
		tmp->arg = va_arg(ap, char*);
	//if (tmp->type == 'S')
	//tmp->arg = va_arg(ap, char*);
	if (tmp->type == 'p')
		tmp->arg = ft_strjoin("0x", itoabase((int)(va_arg(ap, void*)), 16));
	if (tmp->type == 'x')
		tmp->arg = itoabase((int)(va_arg(ap, void*)), 16);
	if (tmp->type == 'X')
		tmp->arg = strtoup(itoabase((int)(va_arg(ap, void*)), 16));
	if (tmp->type == 'd' || tmp->type == 'i' || tmp->type == 'u' || tmp->type == 'D')
		tmp->arg = ft_itoa(va_arg(ap, int));
	if (tmp->type == 'o')
		tmp->arg = ft_itoa((int)conv_o((int)(va_arg(ap, void*))));
	if (tmp->type == 'O')
		tmp->arg = itoabase((int)(va_arg(ap, void*)), 6);
	if (tmp->type == 'b')
		tmp->arg = itoabase((int)(va_arg(ap, void*)), 2);
	if (tmp->flag != '|')
		parse_arg_flag(tmp);
}


void		parse_width(const char *chr, t_argmnt *tmp, int i)
{
	int x = i;
	tmp->width = 0;
	if (chr[x] == ' ')
		x++;
	while (ft_isdigit(chr[x]) && (chr[x - 1] != '.' || (chr[x - 1] == tmp->flag)))
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
	if (chr == 'b')
		tmp->type = 'b';
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
	parse_modif(chr, tmp, i);
	parse_arg_type(tmp, ap);
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

	tmp->flag = '|';
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
