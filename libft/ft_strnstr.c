/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:45:46 by maxisimo          #+#    #+#             */
/*   Updated: 2017/11/14 16:09:17 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len2;

	len2 = ft_strlen(needle);
	if (!*needle)
		return ((char *)haystack);
	while ((*haystack) && (len-- >= len2))
	{
		if ((*haystack == *needle) && (ft_memcmp(haystack, needle, len2) == 0))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
