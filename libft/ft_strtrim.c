/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:40:15 by maxisimo          #+#    #+#             */
/*   Updated: 2017/11/14 19:48:03 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	start;
	size_t	end;
	size_t	len;
	char	*s2;

	i = 0;
	start = 0;
	if (!s)
		return (NULL);
	end = ft_strlen((char *)s) - 1;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t') && start < end)
		end--;
	len = end - start + 1;
	if (!(s2 = (char *)malloc(sizeof(*s2) * (len + 1))))
		return (NULL);
	s2 = ft_strsub((char *)s, start, len);
	s2[len + 1] = '\0';
	return (s2);
}
