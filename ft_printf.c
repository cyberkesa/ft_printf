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

int			precision(const char *precision_format, va_list *ap, t_t *t)
{
	int		precision;

	if (ft_isalpha(*precision_format))
		precision = 0;
	if (ft_isdigit(*precision_format))
		precision = ft_unsigned_atoi(precision_format);
	if (findsymbol(precision_format, '*'))
		precision = va_arg(*ap, int);
	t->p_yes = 1;
	return (precision);
}

char		*pf_widht(const char *format, t_t *t, va_list *ap)
{
	t->s = 0;
	t->s = findsymbol(format, '*');
	if (pf_find(format, '*') && t->s[0] != '.')
	{
		t->wight = va_arg(*ap, int);
		if (t->wight < 0)
		{
			t->wight = -t->wight;
			t->minus = 1;
		}
	}
	if (format[0] == '-' || format[1] == '-' || format[2] == '-')
		t->minus = 1;
	if (format[0] == '0')
		t->null = 1;
	if (ft_atoi(format))
		t->wight = ft_unsigned_atoi(format);
	if (t->wight == 0 && t->null == 1)
		t->wight = ft_unsigned_atoi(format + 1);
	t->s = pf_find(format, '.');
	if (t->s)
		t->precision = precision(t->s + 1, ap, t);
	t->null = (t->minus == 1) ? 0 : t->null;
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
	t_t		t;
	va_list	ap;

	pf_ret(0, 1);
	va_start(ap, format);
	pf_loop(format, &t, &ap);
	va_end(ap);
	return (pf_ret(0, 0));
}
