/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:15:30 by vwinfred          #+#    #+#             */
/*   Updated: 2020/11/01 17:15:31 by vwinfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*new;
	size_t			s1len;
	size_t			s2len;
	size_t			i;

	if (s1 && s2)
	{
		s1len = ft_strlen(s1);
		s2len = ft_strlen(s2);
	}
	else
		return (NULL);
	new = malloc(s1len + s2len + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (s1len--)
	{
		new[i] = s1[i];
		i++;
	}
	while (s2len--)
		new[i++] = *s2++;
	new[i] = '\0';
	return (new);
}
