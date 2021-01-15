#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stddef.h>
#include "Libft/libft.h"

typedef struct		s_flags
{
	int				minus;
	int				null;
	int				wight;
	int				precision;
	char			*data_s;
	int				len_s;
	char			data_c;
	int				p_yes;
	int				original;
	int				di_unsigned;
	int				data_p;
	int				sign;
	int				len_data_o;
	int				len_data_u;
	long			data_x;
	long			data_X;
	unsigned int	data_u;
	char			*spec;
	char			*parce;
}					t_flag;

int			ft_printf(const char *format, ...);
char		*pf_loop(const char *format, t_flag *flag, va_list *ap);
char		*pf_widht(const char *format, t_flag *flag, va_list *ap);
char		*pf_parcespec(const char *format, t_flag *flag, va_list *ap);
void		print_percentum(t_flag *flag);
int			precision(const char *precision_format, va_list *ap, t_flag *flag);
void		print_di(t_flag *flag);
void		print_u(t_flag *flag);
void		print_c(t_flag *flag);
void		print_s(t_flag *flag);
void		s_null(t_flag *flag);
void		di_null(t_flag *flag);
void		pf_print_char(char *s, int n);
void		pf_print(int c, size_t n);
char		*ft_strchr_time(const char *s, int c);
char		*super_ft_strchr(const char *s, int c);


#endif
