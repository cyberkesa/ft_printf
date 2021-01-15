/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 19:36:10 by vwinfred          #+#    #+#             */
/*   Updated: 2020/12/24 19:36:11 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

char		*super_ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while (ft_strchr(".*-1234567890", s[i]))
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	if (c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

char		*ft_strchr_time(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)(s + i - 1));
		i++;
	}
	if (c == '\0')
		return ((char *)(s + i - 1));
	return (NULL);
}

int			pf_ret(int	i, int	s)
{
	int	static ret;
	if (s)
		ret = 0;
	ret += i;
	return (ret);
}

void		pf_print(int c, size_t n)
{
	if (n && c)
		while (n != 0)
		{
			write(1, &c, 1);
			n--;
		}
}

void		pf_print_char(char *s, int n)
{
	if (n && s)
		while (n--)
		{
			write(1, s, 1);
			s++;
		}
}

char		*pf_itoa_base(int value, int base)
{
	static	char rep[] = "0123456789abcdef";
	static	char buf[50];
	char	*ptr;
	int		num;

	ptr = &buf[49];
	*ptr = '\0';
	num = value;
	if (value < 0 && base == 10)
		value *= -1;
	if (value == 0)
		*--ptr = rep[value % base];
	while (value != 0)
	{
		*--ptr = rep[value % base];
		value /= base;
	}
	if (num < 0 && base == 10)
		*--ptr = '-';
	return (ptr);
}

//void		print_x(char *s, int n)
//{

//}

//void		print_X(char *s, int n)
//{

//}

void		print_p(t_flag *flag)
{
	int		nnull;
	int		nspace;

	if (flag->precision > 1 || flag->sign == 1)
		flag->null = 0;
	if (flag->original < 0)
		flag->sign = 1;
	nnull = flag->precision - flag->len_data_u;
	nnull = (nnull < 0) ? 0 : nnull;
	nspace = flag->wight - (flag->sign + flag->len_data_u + nnull);
	nspace = (nspace < 0) ? 0 : nspace;
	if (flag->minus == 0 && flag->null == 0)
		pf_print(' ', nspace);
	pf_print_char("0x", 2);
	if (flag->minus == 0 && flag->null == 1)
		pf_print('0', nspace);
	pf_print('0', nnull);
	ft_putstr_fd(pf_itoa_base(flag->data_p, 16), 1);
	if (flag->minus == 1)
		pf_print(' ', nspace);
	pf_ret(nspace + flag->sign + flag->len_data_u + nnull, 0);
}

void		di_null(t_flag *flag)
{
	int		nspace;

	nspace = flag->wight;
	nspace = (nspace < 0) ? 0 : nspace;
	if (flag->minus == 0 && flag->null == 0)
		pf_print(' ', nspace);
	if (flag->minus == 0 && flag->null == 1)
		pf_print('0', nspace);
	if (flag->minus == 1)
		pf_print(' ', nspace);
	pf_ret(nspace, 0);
}

void		u_null(t_flag *flag)
{
	int		nspace;

	nspace = flag->wight;
	nspace = (nspace < 0) ? 0 : nspace;
	if (flag->minus == 0 && flag->null == 0)
		pf_print(' ', nspace);
	if (flag->minus == 0 && flag->null == 1)
		pf_print('0', nspace);
	if (flag->minus == 1)
		pf_print(' ', nspace);
	pf_ret(nspace, 0);
}

void		s_null(t_flag *flag)
{
	int		nspace;
	char	*null;
	null = "(null)";

	nspace = 0;
	flag->data_s = null;
	if (flag->precision >= 6 || flag->p_yes == 0)
	{
		nspace = flag->wight - 6;
		pf_ret(6, 0);
	}
	if (flag->precision > 0 && flag->precision < 6)
	{
		nspace = flag->wight - flag->precision;
		pf_ret(flag->precision, 0);
	}
	if (flag->precision == 0 && flag->p_yes == 1)
		nspace = flag->wight;
	nspace = (nspace < 0) ? 0 : nspace;
	if (flag->minus == 0 && nspace)
		pf_print(' ', nspace);
	if (flag->precision > 0 && flag->precision < 6)
		pf_print_char(null, flag->precision);
	if (flag->precision >= 6 || (flag->precision == 0 && flag->p_yes == 0))
		ft_putstr_fd(null, 1);
	if (flag->minus == 1 && nspace)
		pf_print(' ', nspace);
	pf_ret(nspace, 0);
}

void		print_c(t_flag *flag)
{
	int		nspace;

	nspace = flag->wight - 1;
	nspace = (nspace < 0) ? 0 : nspace;
	if (flag->minus == 0)
		pf_print(' ', nspace);
	if (flag->data_c == 0)
		pf_print(0, 1);
	ft_putchar_fd(flag->data_c, 1);
	if (flag->minus == 1)
		pf_print(' ', nspace);
	pf_ret(nspace + 1, 0);
}

void		print_u(t_flag *flag)
{
	int		nnull;
	int		nspace;

	if (flag->precision > 1 || flag->sign == 1)
		flag->null = 0;
	if (flag->original < 0)
		flag->sign = 1;
	nnull = flag->precision - flag->len_data_u;
	nnull = (nnull < 0) ? 0 : nnull;
	nspace = flag->wight - (flag->sign + flag->len_data_u + nnull);
	if (nspace < 0)
		nspace = 0;
	if (flag->minus == 0 && flag->null == 0)
		pf_print(' ', nspace);
	if (flag->sign != 0)
		pf_print('-', flag->sign);
	if (flag->minus == 0 && flag->null == 1)
		pf_print('0', nspace);
	pf_print('0', nnull);
		ft_putnbr_fd(flag->data_u, 1);
	if (flag->minus == 1)
		pf_print(' ', nspace);
	pf_ret(nspace + flag->sign + flag->len_data_u + nnull, 0);
}

void		print_di(t_flag *flag)
{
	int		nnull;
	int		nspace;

	if (flag->precision > 1 || flag->sign == 1)
		flag->null = 0;
	if (flag->original < 0)
		flag->sign = 1;
	if (flag->original == -2147483648)
		flag->sign = 0;
	nnull = flag->precision - flag->len_data_u;
	nnull = (nnull < 0) ? 0 : nnull;
	nspace = flag->wight - (flag->sign + flag->len_data_u + nnull);
	nspace = (nspace < 0) ? 0 : nspace;
	if (flag->minus == 0 && flag->null == 0)
		pf_print(' ', nspace);
	if (flag->sign != 0)
		pf_print('-', flag->sign);
	if (flag->minus == 0 && flag->null == 1)
		pf_print('0', nspace);
	pf_print('0', nnull);
		ft_putnbr_fd(flag->di_unsigned, 1);
	if (flag->minus == 1)
		pf_print(' ', nspace);
	pf_ret(nspace + flag->sign + flag->len_data_u + nnull, 0);
}

int			precision(const char *precision_format, va_list *ap, t_flag *flag)
{
	int		precision;

	if (ft_isalpha(*precision_format))
		precision = 0;
	if (ft_isdigit(*precision_format))
		precision = ft_unsigned_atoi(precision_format);
	if (super_ft_strchr(precision_format, '*'))
		precision = va_arg(*ap, int);
	flag->p_yes = 1;
	return (precision);
}

void		print_percentum(t_flag *flag)
{
	int		space;

	space = flag->wight - 1;
	if (space < 0)
		space = 0;
	if (flag->minus == 0 && flag->null == 0)
		pf_print(' ', space);
	else if (flag->minus == 0 && flag->null == 1)
		pf_print('0', space);
	pf_print(37, 1);
	if (flag->minus == 1)
		pf_print(' ', space);
	pf_ret(1 + space, 0);
}

char		*pf_parcespec(const char *format, t_flag *flag, va_list *ap)
{
	int		i;

	i = 0;
	while (flag->spec == 0)
		flag->spec = ft_strchr("dicspuixX%", format[i++]);
	if (*flag->spec == 'c')
	{
		flag->data_c = va_arg(*ap, int);
		print_c(flag);
	}
	if (*flag->spec == 's')
	{
		flag->data_s = va_arg(*ap, char*);
		if (flag->data_s == 0)
			s_null(flag);
		else
			print_s(flag);
	}
	if (*flag->spec == '%')
		print_percentum(flag);
	if (*flag->spec == 'd' || *flag->spec == 'i')
	{
		char	*s;
		flag->original = va_arg(*ap, int);
		if (flag->original < 0)
			flag->di_unsigned = -flag->original;
		else
			flag->di_unsigned = flag->original;
		s = ft_itoa(flag->di_unsigned);
		flag->len_data_u = ft_strlen(s);
		free(s);
		if (flag->precision < 0)
			flag->precision = 0;
		if (flag->original == 0 && flag->precision == 0 && flag->p_yes == 1)
			di_null(flag);
		else
			print_di(flag);
	}
	if (*flag->spec == 'u')
	{
		char	*s;
		flag->data_u = va_arg(*ap, unsigned int);
		s = ft_itoa(flag->data_u);
		flag->len_data_u = ft_strlen(s);
		free(s);
		if (flag->precision < 0)
			flag->precision = 0;
		if (flag->data_u == 0 && flag->precision == 0 && flag->p_yes == 1)
			u_null(flag);
		else
			print_u(flag);
	}
	//if (*flag->spec == 'x')
	//	print_x(flag);
	//if (*flag->spec == 'X')
	//	print_X(flag);
	if (*flag->spec == 'p')
	{
		flag->data_p = va_arg(*ap, unsigned long);
		print_p(flag);
	}
	return (ft_strchr(format, *flag->spec));
}

char		*pf_widht(const char *format, t_flag *flag, va_list *ap)
{
	char	*s;

	if (format[0] == '-' || format[1] == '-' || format[2] == '-')
		flag->minus = 1;
	if (format[0] == '0')
		flag->null = 1;
	if (ft_atoi(format))
		flag->wight = ft_unsigned_atoi(format);
	if (flag->wight == 0 && flag->null == 1)
		flag->wight = ft_unsigned_atoi(format + 1);
	s = ft_strchr_time(format, '*');
	if (super_ft_strchr(format, '*') && s[0] != '.')
	{
			flag->wight = va_arg(*ap, int);
			if (flag->wight < 0)
			{
				flag->wight = -flag->wight;
				flag->minus = 1;
			}
	}
	s = super_ft_strchr(format, '.');
	if (s)
		flag->precision = precision(s + 1, ap, flag);
	if (flag->minus == 1)
		flag->null = 0;
	return (pf_parcespec(format, flag, ap));
}

char		*pf_loop(const char *format, t_flag *flag, va_list *ap)
{
	ft_bzero(flag, sizeof(t_flag));
	while (*format != '%' && *format != '\0')
	{
		write(1, format++, 1);
		pf_ret(1, 0);
	}
	if (*format == '%')
	{
		flag->parce = pf_widht(format + 1, flag, ap);
		if (*flag->parce)
			pf_loop(flag->parce + 1, flag, ap);
	}
	return (0);
}

int			ft_printf(const char *format, ...)
{
	t_flag	flag;
	va_list	ap;
	pf_ret(0, 1);

	va_start(ap, format);
	pf_loop(format, &flag, &ap);
	va_end (ap);
	return (pf_ret(0, 0));
}
