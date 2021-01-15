#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include "Libft/libft.h"

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
	char			data_c;
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
	long			data_X;
	unsigned int	data_u;
	char			*spec;
	char			*parce;
}					t_t;

int			ft_printf(const char *format, ...);
char		*pf_loop(const char *format, t_t *t, va_list *ap);
char		*pf_widht(const char *format, t_t *t, va_list *ap);
char		*pf_parcespec(const char *format, t_t *t, va_list *ap);
void		print_percentum(t_t *t);
int			precision(const char *precision_format, va_list *ap, t_t *t);
void		print_di(t_t *t);
void		print_u(t_t *t);
void		print_c(t_t *t);
void		print_s(t_t *t);
void		post_print_s(t_t *t);
int			pf_ret(int	i, int	s);
void		s_null(t_t *t);
void		di_null(t_t *t);
void		pf_print_char(char *s, int n);
void		pf_print(int c, size_t n);
char		*ft_strchr_time(const char *s, int c);
char		*super_ft_strchr(const char *s, int c);
int			ft_intlen_base(unsigned int nbr, int base);
char		*pf_itoa_base(unsigned int nbr, int base);


#endif
