/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 00:45:04 by vwinfred          #+#    #+#             */
/*   Updated: 2021/01/17 00:45:09 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include "Libft/libft.h"

typedef struct		s_flags
{
	int				minus;
	int				null;
	int				wight;
	int				precision;
	char			*data_s;
	int				len_s;
	int				nnull;
	int				nspace;
	unsigned char	data_c;
	int				p_yes;
	int				original;
	int				di_unsigned;
	unsigned long	data_p;
	int				len_p;
	char			*sixteen;
	int				sign;
	int				len_data_o;
	int				len_data_u;
	long			data_x;
	unsigned long	data_u;
	char			*s;
	char			*spec;
	char			*parce;
}					t_t;

int					ft_printf(const char *format, ...);
char				*pf_loop(const char *format, t_t *t, va_list *ap);
char				*pf_widht(const char *format, t_t *t, va_list *ap);
char				*pf_widht_next(const char *format, t_t *t,
					va_list *ap, char *s);
char				*pf_parcespec(const char *format, t_t *t, va_list *ap);
char				*pf_parcespec_di(const char *format, t_t *t, va_list *ap);
char				*pf_parcespec_pu(const char *format, t_t *t, va_list *ap);
char				*pf_parcespec_sc(const char *format, t_t *t, va_list *ap);
char				*pf_parcespec_x(const char *format, t_t *t, va_list *ap);
int					precision(const char *precision_format,
					va_list *ap, t_t *t);
void				print_percentum(t_t *t);
void				print_di(t_t *t);
void				print_u(t_t *t);
void				print_c(t_t *t);
void				print_s(t_t *t);
void				print_x_big(t_t *t);
void				print_x(t_t *t);
void				print_p(t_t *t);
void				pp_null(t_t *t);
void				s_null(t_t *t);
void				s_null_print(t_t *t, char *null);
void				u_null(t_t *t);
void				di_null(t_t *t);
void				post_print_s(t_t *t);
int					pf_ret(int	i, int	s);
void				pf_print_char(char *s, int n);
void				pf_print(int c, size_t n);
char				*findsymbol(const char *s, int c);
char				*pf_find(const char *s, int c);
int					ft_intlen_base(unsigned long nbr, int base);
char				*pf_itoa_base(unsigned long nbr, int base);
char				*pf_itoa_base_big(unsigned long nbr, int base);
char				*ft_itoa_long(long n);

#endif
