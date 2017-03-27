/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygokol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 20:43:58 by ygokol            #+#    #+#             */
/*   Updated: 2017/03/27 16:29:45 by ygokol           ###   ########.fr       */
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
# include <wchar.h>
# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"


typedef struct			s_flags
{
	int					hash;
	int					zero;
	int					minus;
	int					plus;
	int					space;
}						t_flags;

typedef struct	s_argmnt
{
	struct s_flags		flag;
	int					width;
	int					prec;
	char				*modif;
	char				type;
	char				*arg;
	int					pad;
	struct s_argmnt		*next;
}						t_argmnt;

int						ft_printf(const char *format, ...);
void					parse_width(const char* chr, t_argmnt *tmp, int i);
void					parse_prec(const char* chr, t_argmnt *tmp, int i);
void					parse_type(const char *chr, t_argmnt *tmp, int i);
void					parse_modif(const char* chr, t_argmnt *tmp, int i);
void					parse_flags(const char* chr, t_argmnt *tmp, int i);
char					*itoabase(unsigned int num, int base);
char					*itoa_h(short num, int base);
char					*strtoup(char *str);
char					*conv_o(unsigned long long n);
char					*conv_p(unsigned long long n);



void					flag_hashtg(t_argmnt *tmp);
char					*flag_zero(t_argmnt *tmp, int size);
char					*fill_char(int i, char c);
void					putnbr_l(long n, t_argmnt *tmp);
void					modif_di(t_argmnt *tmp, va_list ap);
char					*ctostr(char c);
char					*width_di(t_argmnt *tmp);

void					print_arg_modif(t_argmnt *tmp, va_list ap);
void					print_arg_flag(t_argmnt *tmp);
void					print_arg_type(t_argmnt *tmp, va_list ap);
int						isflag (t_flags flag);
char					*print_arg(t_argmnt *tmp, va_list ap);
char					*ft_ltoa(long n);
void					putnbr_l(long n, t_argmnt *tmp);
char					*ft_wputchar(wchar_t c);
char					*ft_ultoa(unsigned long n);
void					modif_ouxX(t_argmnt *tmp, va_list ap);
char					*ft_print_special(wint_t c);
int						nb_flags(t_flags f);

#endif
