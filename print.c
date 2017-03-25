#include "ft_printf.h"
#include "libft.h"


char *s_prec(char *str, int prec)
{
	int len;
	int i;

	i = 0;
	len = (int)ft_strlen(str);
	if (len <= prec)
		return (str);
	else
	{
		while (i != len)
		{
			str[i] = str[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
}

char *prec_neg(t_argmnt *tmp)
{
	char *ret;
	int size;

	ret = (ft_itoa(ft_atoi(tmp->arg) * -1));
	size = (tmp->prec - (int)ft_strlen(ret));
	if (size > 0)
		ret = ft_strjoin(fill_char(size, '0'), ret);
	return (ft_strjoin("-", ret));

}

void print_arg_prec(t_argmnt *tmp)
{
	int size;
	
	size = (tmp->prec - (int)ft_strlen(tmp->arg));
	if (tmp->prec > 0 && size > 0)
	{
		if (tmp->type != 's' || tmp->type != 'S')
		{
			if (tmp->arg[0] == '-')
				tmp->arg = prec_neg(tmp);
			else
				tmp->arg = ft_strjoin(fill_char(size, '0'), tmp->arg);
		}
		else if (tmp->type == 's' || tmp->type == 'S')
			tmp->arg = s_prec(tmp->arg, tmp->prec);
	}
}

void print_arg_width(t_argmnt *tmp)
{
	int size;

	size = (tmp->width - (int)ft_strlen(tmp->arg));
	if (tmp->width > 0 && size > 0)
	{
		if (tmp->flag.minus)
			tmp->arg = (ft_strcat(tmp->arg, fill_char(size, ' ')));
		else if (tmp->flag.zero)
			tmp->arg = flag_zero(tmp, size);
		else if (tmp->flag.space)
			tmp->arg = (ft_strcat(fill_char(size, ' '), tmp->arg));
		else if (!isflag(tmp->flag))
			tmp->arg = (ft_strjoin(fill_char(size, ' '), tmp->arg));
	}
}

void print_arg_modif(t_argmnt *tmp, va_list ap)
{
	if ((tmp->type == 'd' || tmp->type == 'i'))
		modif_di(tmp, ap);
}

void print_arg_flag(t_argmnt *tmp)
{
	if (tmp->flag.hash)
		flag_hashtg(tmp);
	else if (tmp->flag.zero && !tmp->width)
		tmp->arg = ft_strjoin(ctostr('0'), tmp->arg);
	else if (tmp->flag.space)
		tmp->arg = ft_strjoin(ctostr(' '), tmp->arg);
	else if (tmp->flag.plus && tmp->arg[0] != '-')
		tmp->arg = ft_strjoin("+", tmp->arg);
	else if (tmp->flag.minus && tmp->arg[0] != '-' && !tmp->width)
		tmp->arg = ft_strjoin("-", tmp->arg);
}


void		print_arg_type(t_argmnt *tmp, va_list ap)
{
	if (tmp->modif)
		print_arg_modif(tmp, ap);
	if (tmp->type == 's')
		tmp->arg = va_arg(ap, char*);
	if (tmp->type == 'u')
		tmp->arg = itoabase((unsigned int)va_arg(ap, unsigned long), 10);
	if (tmp->type == 'U')
		tmp->arg = itoabase((unsigned long)va_arg(ap, long), 10);
	if (tmp->type == 'D')
		tmp->arg = ft_itoa(va_arg(ap, long));
	if (tmp-> type == 'c')
		tmp->arg = ctostr(va_arg(ap, int));
	if (tmp-> type == 'C')
		tmp->arg = ft_print_special((wchar_t)va_arg(ap, wchar_t));
	if (tmp->type == 'p')
		tmp->arg = ft_strjoin("0x", conv_p((va_arg(ap, long))));
	if (tmp->type == 'x')
		tmp->arg = itoabase((unsigned int)(va_arg(ap, void*)), 16);
	if (tmp->type == 'X')
		tmp->arg = strtoup(itoabase((unsigned int)(va_arg(ap, void*)), 16));
	if ((tmp->type == 'd' || tmp->type == 'i') && !tmp->modif)
		tmp->arg = ft_itoa(va_arg(ap, int));
	if (tmp->type == 'o')
		tmp->arg = conv_o((va_arg(ap, unsigned long long)));
	if (tmp->type == 'O')
		tmp->arg = conv_o((va_arg(ap, long long)));
	if (tmp->type == 'b')
		tmp->arg = itoabase((int)(va_arg(ap, void*)), 2);
	if (tmp->type == '%')
		tmp->arg = "%";
}

char *print_arg(t_argmnt *tmp, va_list ap)
{
	if (tmp->type != '\0')
		print_arg_type(tmp, ap);
	if (isflag(tmp->flag))
		print_arg_flag(tmp);
	if (tmp->prec > 0)
		print_arg_prec(tmp);
	if (tmp->width > 0)
		print_arg_width(tmp);
	return (tmp->arg);
}
