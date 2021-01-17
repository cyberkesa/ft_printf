/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ucpr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 06:37:04 by vwinfred          #+#    #+#             */
/*   Updated: 2021/01/16 06:37:05 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		u_null(t_t *t)
{
	pf_print('0', 1);
	pf_ret(1, 0);
}

void		print_c(t_t *t)
{
	t->nspace = t->wight - 1;
	t->nspace = (t->nspace < 0) ? 0 : t->nspace;
	if (t->minus == 0)
		pf_print(' ', t->nspace);
	if (t->data_c == 0)
		pf_print(0, 1);
	write(1, &t->data_c, 1);
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
	ft_putstr_fd(t->data_s, 1);
	if (t->minus == 1)
		pf_print(' ', t->nspace);
	pf_ret(t->nspace + t->sign + t->len_data_u + t->nnull, 0);
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
