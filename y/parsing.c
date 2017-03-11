/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 21:37:00 by ygokol            #+#    #+#             */
/*   Updated: 2017/03/11 22:27:23 by ygokol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_width(const char *chr, t_argmnt *tmp)
{
}

void		parse_prec(const char *chr, t_argmnt *tmp)
{

}

int		parse_type(char* chr, t_argmnt *tmp, int i)
{
	int x;
	x = i;

	tmp->type = '\0';
	while (tmp->type == '\0')
	{
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
	return (1);
}

void		parse_modif(const char *chr, t_argmnt *tmp)
{
	int i;
	i = 0;
	tmp->modif = NULL;
	while (chr[i] != ' ')
	{
		if (chr[i] == 'h')
			tmp->modif = "h";
		if (chr[i] == 'h' && chr[i + 1] == 'h')
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
}

void		parse_flags(char chr, t_argmnt *tmp)
{
	if (chr == '#')
		tmp->flag = '#';
	if (chr == '0')
		tmp->flag = '0';
	if (chr == '-')
		tmp->flag = '-';
	if (chr == '+')
		tmp->flag = '+';
	if (chr == ' ')
		tmp->flag = ' ';
	else
		tmp->flag = '\0';
}
