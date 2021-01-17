/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 06:37:16 by vwinfred          #+#    #+#             */
/*   Updated: 2021/01/16 06:37:17 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*pf_find(const char *s, int c)
{
	size_t		i;

	i = 0;
	while (ft_strchr(".*-1234567890", s[i]))
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	if (c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

char			*findsymbol(const char *s, int c)
{
	size_t		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)(s + i - 1));
		i++;
	}
	if (c == '\0')
		return ((char *)(s + i - 1));
	return (NULL);
}

int				pf_ret(int i, int s)
{
	static int	ret;

	if (s)
		ret = 0;
	ret += i;
	return (ret);
}

void			pf_print(int c, size_t n)
{
	if (n && c)
		while (n != 0)
		{
			write(1, &c, 1);
			n--;
		}
}

void			pf_print_char(char *s, int n)
{
	if (n && s)
		while (n--)
		{
			write(1, s, 1);
			s++;
		}
}
