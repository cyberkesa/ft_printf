/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 06:36:33 by vwinfred          #+#    #+#             */
/*   Updated: 2021/01/16 06:36:35 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*pf_itoa_base(unsigned long nbr, int base)
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

char		*pf_itoa_base_big(unsigned long nbr, int base)
{
	static char		buf[50];
	register int	len;
	char			c;

	len = ft_intlen_base(nbr, base);
	buf[len--] = '\0';
	while (len >= 0)
	{
		c = (char)(nbr % base);
		buf[len--] = c + ((c > 9) ? '7' : '0');
		nbr /= base;
	}
	return (buf);
}

char		*ft_itoa_long(long n)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	if (n > 4294967295)
		return (str = ft_strdup("4294967295"));
	if (n < 0)
	{
		str[0] = '-';
		str[1] = '\0';
		str = ft_strjoin(str, ft_itoa_long(-n));
	}
	else if (n >= 10)
		str = ft_strjoin(ft_itoa_long(n / 10), ft_itoa_long(n % 10));
	else if (n < 10 && n >= 0)
	{
		str[0] = n + '0';
		str[1] = '\0';
	}
	return (str);
}

int			ft_intlen_base(unsigned long nbr, int base)
{
	int		i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= base;
		i++;
	}
	return (i);
}
