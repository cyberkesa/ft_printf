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

//void		print_x(char *s, int n)
//{

//}

//void		print_X(char *s, int n)
//{

//}

int			ft_intlen_base(unsigned int nbr, int base)
{
	int	i;
	i = 0;
	if (nbr == 0)
		return 1;
	while (nbr)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

char		*pf_itoa_base(unsigned int nbr, int base)
{
	static char		buf[50];
	register int	len;
	char			c;
	len = ft_intlen_base(nbr, base);
	buf[len--] = '\0';
	while (len >= 0)
	{
		c = (char)(nbr % base);
		buf[len--] = c + ((c > 9) ? 'W' : '0');
		nbr /= base;
	}
	return (buf);
}

void		print_p(t_t *t)
{
	t->null = (t->precision > 1 || t->sign == 1) ? 0 : t->null;
	t->nnull = t->precision - t->len_p;
	t->nnull = (t->nnull < 0) ? 0 : t->nnull;
	t->nspace = t->wight - (t->len_p + t->nnull);
	t->nspace = (t->nspace < 0) ? 0 : t->nspace;
	if (t->minus == 0 && t->null == 0)
		pf_print(' ', t->nspace);
	pf_print_char("0x", 2);
	if (t->minus == 0 && t->null == 1)
		pf_print('0', t->nspace);
	pf_print('0', t->nnull);
	ft_putstr_fd(t->sixteen, 1);
	if (t->minus == 1)
		pf_print(' ', t->nspace);
	pf_ret(t->nspace + t->len_data_u + t->nnull, 0);
}

void		u_null(t_t *t)
{
	int		nspace;

	nspace = t->wight;
	nspace = (nspace < 0) ? 0 : nspace;
	if (t->minus == 0 && t->null == 0)
		pf_print(' ', nspace);
	if (t->minus == 0 && t->null == 1)
		pf_print('0', nspace);
	if (t->minus == 1)
		pf_print(' ', nspace);
	pf_ret(nspace, 0);
}

void		print_c(t_t *t)
{
	t->nspace = t->wight - 1;
	t->nspace = (t->nspace < 0) ? 0 : t->nspace;
	if (t->minus == 0)
		pf_print(' ', t->nspace);
	if (t->data_c == 0)
		pf_print(0, 1);
	ft_putchar_fd(t->data_c, 1);
	if (t->minus == 1)
		pf_print(' ', t->nspace);
	pf_ret(t->nspace + 1, 0);
}

void		print_u(t_t *t)
{
	if (t->precision > 1 || t->sign == 1)
		t->null = 0;
	if (t->original < 0)
		t->sign = 1;
	t->nnull = t->precision - t->len_data_u;
	t->nnull = (t->nnull < 0) ? 0 : t->nnull;
	t->nspace = t->wight - (t->sign + t->len_data_u + t->nnull);
	t->nspace = (t->nspace < 0) ? 0 : t->nspace;
	if (t->minus == 0 && t->null == 0)
		pf_print(' ', t->nspace);
	if (t->sign != 0)
		pf_print('-', t->sign);
	if (t->minus == 0 && t->null == 1)
		pf_print('0', t->nspace);
	pf_print('0', t->nnull);
		ft_putnbr_fd(t->data_u, 1);
	if (t->minus == 1)
		pf_print(' ', t->nspace);
	pf_ret(t->nspace + t->sign + t->len_data_u + t->nnull, 0);
}

int			precision(const char *precision_format, va_list *ap, t_t *t)
{
	int		precision;

	if (ft_isalpha(*precision_format))
		precision = 0;
	if (ft_isdigit(*precision_format))
		precision = ft_unsigned_atoi(precision_format);
	if (super_ft_strchr(precision_format, '*'))
		precision = va_arg(*ap, int);
	t->p_yes = 1;
	return (precision);
}

void		print_percentum(t_t *t)
{
	int		space;

	space = t->wight - 1;
	if (space < 0)
		space = 0;
	if (t->minus == 0 && t->null == 0)
		pf_print(' ', space);
	else if (t->minus == 0 && t->null == 1)
		pf_print('0', space);
	pf_print(37, 1);
	if (t->minus == 1)
		pf_print(' ', space);
	pf_ret(1 + space, 0);
}

char		*pf_parcespec(const char *format, t_t *t, va_list *ap)
{
	int		i;

	i = 0;
	while (t->spec == 0)
		t->spec = ft_strchr("dicspuixX%", format[i++]);
	if (*t->spec == 'c')
	{
		t->data_c = va_arg(*ap, int);
		print_c(t);
	}
	if (*t->spec == 's')
	{
		t->data_s = va_arg(*ap, char*);
		if (t->data_s == 0)
			s_null(t);
		else
			HUNTA(t);
	}
	if (*t->spec == '%')
		print_percentum(t);
	if (*t->spec == 'd' || *t->spec == 'i')
	{
		char	*s;
		t->original = va_arg(*ap, int);
		if (t->original < 0)
			t->di_unsigned = -t->original;
		else
			t->di_unsigned = t->original;
		s = ft_itoa(t->di_unsigned);
		t->len_data_u = ft_strlen(s);
		free(s);
		if (t->precision < 0)
			t->precision = 0;
		if (t->original == 0 && t->precision == 0 && t->p_yes == 1)
			di_null(t);
		else
			print_di(t);
	}
	if (*t->spec == 'u')
	{
		char	*s;
		t->data_u = va_arg(*ap, unsigned int);
		s = ft_itoa(t->data_u);
		t->len_data_u = ft_strlen(s);
		free(s);
		if (t->precision < 0)
			t->precision = 0;
		if (t->data_u == 0 && t->precision == 0 && t->p_yes == 1)
			u_null(t);
		else
			print_u(t);
	}
	//if (*t->spec == 'x')
	//	print_x(t);
	//if (*t->spec == 'X')
	//	print_X(t);
	if (*t->spec == 'p')
	{
		t->data_p = va_arg(*ap, unsigned long);
		print_p(t);
	}
	return (ft_strchr(format, *t->spec));
}

char		*pf_widht(const char *format, t_t *t, va_list *ap)
{
	char	*s;

	if (format[0] == '-' || format[1] == '-' || format[2] == '-')
		t->minus = 1;
	if (format[0] == '0')
		t->null = 1;
	if (ft_atoi(format))
		t->wight = ft_unsigned_atoi(format);
	if (t->wight == 0 && t->null == 1)
		t->wight = ft_unsigned_atoi(format + 1);
	s = ft_strchr_time(format, '*');
	if (super_ft_strchr(format, '*') && s[0] != '.')
	{
			t->wight = va_arg(*ap, int);
			if (t->wight < 0)
			{
				t->wight = -t->wight;
				t->minus = 1;
			}
	}
	s = super_ft_strchr(format, '.');
	if (s)
		t->precision = precision(s + 1, ap, t);
	if (t->minus == 1)
		t->null = 0;
	return (pf_parcespec(format, t, ap));
}

char		*pf_loop(const char *format, t_t *t, va_list *ap)
{
	ft_bzero(t, sizeof(t_t));
	while (*format != '%' && *format != '\0')
	{
		write(1, format++, 1);
		pf_ret(1, 0);
	}
	if (*format == '%')
	{
		t->parce = pf_widht(format + 1, t, ap);
		if (*t->parce)
			pf_loop(t->parce + 1, t, ap);
	}
	return (0);
}

int			ft_printf(const char *format, ...)
{
	t_t	t;
	va_list	ap;
	pf_ret(0, 1);

	va_start(ap, format);
	pf_loop(format, &t, &ap);
	va_end (ap);
	return (pf_ret(0, 0));
}
