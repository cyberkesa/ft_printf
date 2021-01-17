/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_px.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 06:36:54 by vwinfred          #+#    #+#             */
/*   Updated: 2021/01/16 06:36:55 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_p(t_t *t)
{
	t->null = (t->precision > 1 || t->sign == 1) ? 0 : t->null;
	t->len_p = ft_strlen(t->sixteen);
	t->nnull = t->precision - t->len_p;
	t->nnull = (t->nnull < 0) ? 0 : t->nnull;
	t->nspace = t->wight - (t->len_p + 2 + t->nnull);
	t->nspace = (t->nspace < 0) ? 0 : t->nspace;
	if (t->minus == 0 && t->null == 0)
		pf_print(' ', t->nspace);
	if (t->sixteen != 0)
		pf_print_char("0x", 2);
	if (t->minus == 0 && t->null == 1)
		pf_print(' ', t->nspace);
	if (t->precision > t->len_p)
		pf_print('0', t->nnull);
	ft_putstr_fd(t->sixteen, 1);
	if (t->minus == 1)
		pf_print(' ', t->nspace);
	pf_ret(t->nspace + t->len_p + 2 + t->nnull, 0);
}

void		pp_null(t_t *t)
{
	t->nspace = t->wight - 2;
	t->nspace = (t->nspace < 0) ? 0 : t->nspace;
	if (t->minus == 0 && t->null == 0)
		pf_print(' ', t->nspace);
	if (t->minus == 0 && t->null == 1)
		pf_print('0', t->nspace);
	ft_putstr_fd("0x", 1);
	if (t->minus == 1)
		pf_print(' ', t->nspace);
	pf_ret(t->nspace + 2, 0);
}

void		print_x(t_t *t)
{
	t->null = (t->precision > 1 || t->sign == 1) ? 0 : t->null;
	t->len_p = ft_strlen(t->sixteen);
	t->nnull = t->precision - t->len_p;
	t->nnull = (t->nnull < 0) ? 0 : t->nnull;
	t->nspace = t->wight - (t->len_p + t->nnull);
	t->nspace = (t->nspace < 0) ? 0 : t->nspace;
	if (t->minus == 0 && t->null == 0)
		pf_print(' ', t->nspace);
	if (t->minus == 0 && t->null == 1)
		pf_print('0', t->nspace);
	if (t->precision > t->len_p)
		pf_print('0', t->nnull);
	ft_putstr_fd(t->sixteen, 1);
	if (t->minus == 1)
		pf_print(' ', t->nspace);
	pf_ret(t->nspace + t->len_p + t->nnull, 0);
}

void		print_x_big(t_t *t)
{
	t->null = (t->precision > 1 || t->sign == 1) ? 0 : t->null;
	t->len_p = ft_strlen(t->sixteen);
	t->nnull = t->precision - t->len_p;
	t->nnull = (t->nnull < 0) ? 0 : t->nnull;
	t->nspace = t->wight - (t->len_p + t->nnull);
	t->nspace = (t->nspace < 0) ? 0 : t->nspace;
	if (t->minus == 0 && t->null == 0)
		pf_print(' ', t->nspace);
	if (t->minus == 0 && t->null == 1)
		pf_print('0', t->nspace);
	if (t->precision > t->len_p)
		pf_print('0', t->nnull);
	ft_putstr_fd(t->sixteen, 1);
	if (t->minus == 1)
		pf_print(' ', t->nspace);
	pf_ret(t->nspace + t->len_p + t->nnull, 0);
}
