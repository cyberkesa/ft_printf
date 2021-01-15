#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

void		print_s(t_flag *flag)
{
	int		nspace;

	nspace = 0;
	flag->len_s = ft_strlen(flag->data_s);
	if (flag->precision > 0 && flag->precision < flag->len_s)
	{
		nspace = flag->wight - flag->precision;
		pf_ret(flag->precision, 0);
	}
	else if (flag->precision <= 0 || flag->precision > flag->len_s)
		nspace = flag->wight - flag->len_s;
	if (flag->precision > flag->len_s)
		pf_ret(flag->len_s, 0);
	if (nspace < 0)
		nspace = 0;
	if (flag->minus == 0 && nspace)
		pf_print(' ', nspace);
	if (flag->wight < 0)
		flag->wight = -flag->wight;
	if (flag->precision < 0 || flag->p_yes == 0)
	{
		ft_putstr_fd(flag->data_s, 1);
		pf_ret(flag->len_s, 0);
	}
	if (flag->precision > 0 && flag->precision <= flag->len_s)
		pf_print_char(flag->data_s, flag->precision);
	if (flag->precision > 0 && flag->precision > flag->len_s)
		pf_print_char(flag->data_s, flag->len_s);
	if (flag->minus == 1 && nspace)
		pf_print(' ', nspace);
	pf_ret(nspace, 0);
}
