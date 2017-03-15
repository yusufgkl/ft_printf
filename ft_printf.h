/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 20:43:58 by ygokol            #+#    #+#             */
/*   Updated: 2017/03/15 15:19:44 by ygokol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef struct	s_argmnt
{
	char				flag;
	int					width;
	int					prec;
	char				*modif;
	char				type;
	char				*arg;
	struct s_argmnt		*next;
}				t_argmnt;

void			parse_width(const char* chr, t_argmnt *tmp, int i);
void			parse_prec(const char* chr, t_argmnt *tmp, int i);
void			parse_type(const char *chr, t_argmnt *tmp, int i, va_list ap);
void			parse_modif(const char* chr, t_argmnt *tmp, int i);
void			parse_flags(const char* chr, t_argmnt *tmp, int i);
char			*itoabase(int num, int base);
char			*strtoup(char *str);
long int conv_o(int n);



void flag_hashtg(t_argmnt *tmp);
#endif
