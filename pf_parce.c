/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parce.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 06:36:44 by vwinfred          #+#    #+#             */
/*   Updated: 2021/01/16 06:36:45 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*pf_parcespec(const char *format, t_t *t, va_list *ap)
{
	int		i;

	i = 0;
	while (t->spec == 0)
		t->spec = ft_strchr("dicspuixX%", format[i++]);
	if (*t->spec == 's' || *t->spec == 'c' || *t->spec == '%')
		return (pf_parcespec_sc(format, t, ap));
	if (*t->spec == 'd' || *t->spec == 'i')
		return (pf_parcespec_di(format, t, ap));
	if (*t->spec == 'p' || *t->spec == 'u')
		return (pf_parcespec_pu(format, t, ap));
	if (*t->spec == 'x' || *t->spec == 'X')
		return (pf_parcespec_x(format, t, ap));
	return (ft_strchr(format, *t->spec));
}

char		*pf_parcespec_sc(const char *format, t_t *t, va_list *ap)
{
	if (*t->spec == '%')
		print_percentum(t);
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
			print_s(t);
	}
	return (ft_strchr(format, *t->spec));
}

char		*pf_parcespec_x(const char *format, t_t *t, va_list *ap)
{
	if (*t->spec == 'x')
	{
		t->data_p = va_arg(*ap, unsigned long);
		t->sixteen = pf_itoa_base(t->data_p, 16);
		if (t->data_p >= 4294967296)
			u_null(t);
		else if (t->data_p == 0 && t->precision == 0 && t->p_yes == 1)
			di_null(t);
		else
			print_x(t);
	}
	if (*t->spec == 'X')
	{
		t->data_p = va_arg(*ap, unsigned long);
		t->sixteen = pf_itoa_base_big(t->data_p, 16);
		if (t->data_p >= 4294967296)
			u_null(t);
		else if (t->data_p == 0 && t->precision == 0 && t->p_yes == 1)
			di_null(t);
		else
			print_x_big(t);
	}
	return (ft_strchr(format, *t->spec));
}

char		*pf_parcespec_pu(const char *format, t_t *t, va_list *ap)
{
	if (*t->spec == 'u')
	{
		t->data_u = va_arg(*ap, int);
		t->data_s = pf_itoa_base((unsigned int)t->data_u, 10);
		t->len_data_u = ft_strlen(t->data_s);
		if (t->data_p >= 4294967296)
			u_null(t);
		else if (t->data_u == 0 && t->precision == 0 \
		&& t->p_yes == 1 && !(t->precision < 0))
			di_null(t);
		else
			print_u(t);
	}
	if (*t->spec == 'p')
	{
		t->data_p = va_arg(*ap, unsigned long);
		t->sixteen = pf_itoa_base(t->data_p, 16);
		if (t->data_p == 0 && t->precision == 0 && t->p_yes == 1)
			pp_null(t);
		else
			print_p(t);
	}
	return (ft_strchr(format, *t->spec));
}

char		*pf_parcespec_di(const char *format, t_t *t, va_list *ap)
{
	char	*s;

	if (*t->spec == 'd' || *t->spec == 'i')
	{
		t->original = va_arg(*ap, int);
		if (t->original < 0)
			t->di_unsigned = -t->original;
		else
			t->di_unsigned = t->original;
		s = ft_itoa(t->di_unsigned);
		t->len_data_u = ft_strlen(s);
		free(s);
		if (t->original == 0 && t->precision == 0 \
		&& t->p_yes == 1 && !(t->precision < 0))
			di_null(t);
		else
			print_di(t);
	}
	return (ft_strchr(format, *t->spec));
}
