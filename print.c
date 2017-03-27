#include "ft_printf.h"
#include "libft.h"


char *s_prec(char *str, int prec)
{
	char *ret;

	ret = malloc(sizeof(char) * (prec + 1));
	if ((int)ft_strlen(str) <- prec)
		return (str);
	else
	{
		ft_strncpy(ret, str, prec);
		ret[prec] = '\0';
		return (ret);
	}
}

char *prec_neg(t_argmnt *tmp)
{
	char *ret;
	int size;

	size = 0;
	ret = (ft_itoa(ft_atoi(tmp->arg) * -1));
	size = (tmp->prec - (int)ft_strlen(ret));
	if (size > 0 && tmp->prec > 0)
		ret = ft_strjoin(fill_char(size, '0'), ret);
	return (ft_strjoin("-", ret));

}

void print_arg_prec(t_argmnt *tmp)
{
	int size;
	size = 0;
	if (tmp->prec > 0 && tmp->type != 's' && tmp->type != 'S')
	{
		size = (tmp->prec - (int)ft_strlen(tmp->arg));
		if (size > 0 && tmp->prec > 0)
		{
			if (tmp->arg[0] == '-')
				tmp->arg = prec_neg(tmp);
			else
				tmp->arg = ft_strjoin(fill_char(size, '0'), tmp->arg);
		}
	}
	else if (tmp->prec > 0 && (tmp->type == 's' || tmp->type == 'S'))
		tmp->arg = s_prec(tmp->arg, tmp->prec);
}

void print_arg_width(t_argmnt *tmp)
{
	int size;

	size = 0;
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
	if (ft_strchr("di", tmp->type))
		modif_di(tmp, ap);
	if (ft_strchr("ouxX", tmp->type))
		modif_ouxX(tmp, ap);
}

void print_arg_flag(t_argmnt *tmp)
{
	if (tmp->flag.hash && !ft_strchr("cdinpsu", tmp->type))
		flag_hashtg(tmp);
	else if (tmp->flag.zero && !tmp->width)
		tmp->arg = ft_strjoin("0", tmp->arg);
	else if (tmp->flag.space && tmp->arg[0] != '-' && 
	!tmp->flag.plus && ft_strchr("dDi", tmp->type))
		tmp->arg = ft_strjoin(ctostr(' '), tmp->arg);
	else if (tmp->flag.plus && tmp->arg[0] != '-' && ft_strchr("di", tmp->type))
		tmp->arg = ft_strjoin("+", tmp->arg);
	else if (tmp->flag.minus && tmp->arg[0] != '-' && !tmp->width)
		tmp->arg = ft_strjoin("-", tmp->arg);
}

char *ft_wputstr(wchar_t *s)
{
	int i;
	char *ret;
	i = 0;
	ret = malloc(sizeof(wchar_t*) * 100);
	while (s[i])
	{
		ret = ft_strcat(ret, ft_wputchar((wchar_t)s[i]));
		i++;
	}
	return (ret);
}


void		print_arg_type(t_argmnt *tmp, va_list ap)
{
	if (tmp->modif)
		print_arg_modif(tmp, ap);
	if (tmp->type == 's' || tmp->type == 'S')
		tmp->arg = va_arg(ap, char*);
	//if (tmp->type == 'S')
	//	tmp->arg = ft_wputstr(va_arg(ap, wchar_t *));
	if (tmp->type == 'u')
		tmp->arg = itoabase((unsigned int)va_arg(ap, unsigned long), 10);
	if (tmp->type == 'U')
		tmp->arg = ft_ultoa(va_arg(ap, unsigned long));
	if (tmp->type == 'D')
		tmp->arg = ft_ltoa(va_arg(ap, long));
	if (tmp-> type == 'c')
		tmp->arg = ctostr((char)va_arg(ap, int));
	if (tmp-> type == 'C')
		tmp->arg = ft_wputchar(va_arg(ap, wchar_t));
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
	if (isflag(tmp->flag) && tmp->arg)
		print_arg_flag(tmp);
	if (tmp->prec >= 0)
		print_arg_prec(tmp);
	if (tmp->width > 0)
		print_arg_width(tmp);
	return (tmp->arg);
}
