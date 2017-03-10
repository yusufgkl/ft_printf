/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 20:43:58 by ygokol            #+#    #+#             */
/*   Updated: 2017/02/24 19:38:15 by ygokol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_argmnt
{
	char				flag;
	char				larg;
	char				prec;
	char				*modif;
	char				type;
	void				*arg;
	struct s_argmnt		*next;
}				t_argmnt;

void			parse_width(const char* chr, t_argmnt *tmp);
void			parse_prec(const char* chr, t_argmnt *tmp);
void			parse_type(char chr, t_argmnt *tmp);
void			parse_modif(const char* chr, t_argmnt *tmp);
void			parse_flags(char chr, t_argmnt *tmp);
#endif
