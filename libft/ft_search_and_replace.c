/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_and_replace.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 13:16:47 by maxisimo          #+#    #+#             */
/*   Updated: 2017/11/22 13:19:52 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_search_and_replace(char *str, char a, char b)
{
	int		i;

	i = -1;
	while (str[++i] != '\0')
		if (str[i] == a)
			str[i] = b;
	return (str);
}
