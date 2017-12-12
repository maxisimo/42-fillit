/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:50:07 by maxisimo          #+#    #+#             */
/*   Updated: 2017/11/11 18:58:39 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*s1;
	const char	*s2;
	size_t		i;
	size_t		len;

	s1 = dst;
	s2 = src;
	i = size;
	while (*s1 && i-- != 0)
		s1++;
	len = s1 - dst;
	i = size - len;
	if (i == 0)
		return (len + ft_strlen(src));
	while (*s2)
	{
		if (i != 1)
		{
			*s1++ = *s2;
			i--;
		}
		s2++;
	}
	*s1 = '\0';
	return (len + (s2 - src));
}
