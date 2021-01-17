/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 23:58:50 by vwinfred          #+#    #+#             */
/*   Updated: 2021/01/15 23:58:51 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_s(t_t *t)
{
	if (t->wight < 0)
		t->wight = -t->wight;
	t->len_s = ft_strlen(t->data_s);
	if (t->precision > 0 && t->precision < t->len_s)
	{
		t->nspace = t->wight - t->precision;
		pf_ret(t->precision, 0);
	}
	if (t->precision == 0 && t->p_yes == 1)
		t->nspace = t->wight;
	if (t->precision == 0 && t->p_yes == 0)
		t->nspace = t->wight - t->len_s;
	if (t->precision < 0 || t->precision >= t->len_s)
		t->nspace = t->wight - t->len_s;
	if (t->precision >= t->len_s)
		pf_ret(t->len_s, 0);
	t->nspace = (t->nspace < 0) ? 0 : t->nspace;
	post_print_s(t);
}

void		post_print_s(t_t *t)
{
	if (t->minus == 0 && t->nspace && !t->null)
		pf_print(' ', t->nspace);
	if (t->null == 1 && t->nspace)
		pf_print('0', t->nspace);
	if (t->precision < 0 || t->p_yes == 0)
	{
		ft_putstr_fd(t->data_s, 1);
		pf_ret(t->len_s, 0);
	}
	if (t->precision > 0 && t->precision <= t->len_s)
		pf_print_char(t->data_s, t->precision);
	if (t->precision > 0 && t->precision > t->len_s)
		pf_print_char(t->data_s, t->len_s);
	if (t->minus == 1 && t->nspace)
		pf_print(' ', t->nspace);
	pf_ret(t->nspace, 0);
}

void		s_null(t_t *t)
{
	char	*null;

	null = "(null)";
	t->data_s = null;
	if (t->wight < 0)
		t->wight = -t->wight;
	if (t->precision >= 6 || t->p_yes == 0)
	{
		t->nspace = t->wight - 6;
		pf_ret(6, 0);
	}
	if (t->precision > 0 && t->precision < 6)
	{
		t->nspace = t->wight - t->precision;
		pf_ret(t->precision, 0);
	}
	if (t->precision == 0 && t->p_yes == 1)
		t->nspace = t->wight;
	t->nspace = (t->nspace < 0) ? 0 : t->nspace;
	s_null_print(t, null);
}

void		s_null_print(t_t *t, char *null)
{
	if (t->null == 1 && t->nspace)
		pf_print('0', t->nspace);
	if (t->minus == 0 && t->nspace && t->null == 0)
		pf_print(' ', t->nspace);
	if (t->precision > 0 && t->precision < 6)
		pf_print_char(null, t->precision);
	if (t->precision >= 6 || (t->precision == 0 && t->p_yes == 0))
		ft_putstr_fd(null, 1);
	if (t->precision < 0 && t->p_yes == 1)
		ft_putstr_fd(null, 1);
	if (t->minus == 1 && t->nspace)
		pf_print(' ', t->nspace);
	pf_ret(t->nspace, 0);
}
