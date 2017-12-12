/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:50:51 by maxisimo          #+#    #+#             */
/*   Updated: 2017/11/12 16:58:35 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*c1;

	c1 = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			c1 = (char *)s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return (c1);
}
