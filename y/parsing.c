/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 21:37:00 by ygokol            #+#    #+#             */
/*   Updated: 2017/03/10 17:59:58 by ygokol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_width(const char *chr, t_argmnt *tmp)
{
}

void		parse_prec(const char *chr, t_argmnt *tmp)
{

}

void		parse_type(char chr, t_argmnt *tmp)
{
	int i;
	i = 0;
	printf("__ TYPE : |%c|\n", chr);
	if (chr == 's')
		tmp->type = 's';
	if (chr == 'S')
		tmp->type = 'S';
	if (chr == 'p')
		tmp->type= 'p';
	if (chr == 'd')
		tmp->type = 'd';
	if (chr == 'D')
		tmp->type = 'D';
	if (chr == 'i')
		tmp->type = 'i';
	else
		tmp->type = '\0';
}

void		parse_modif(const char *chr, t_argmnt *tmp)
{
	int i;
	i = 0;
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
}
