/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_epur_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:48:35 by maxisimo          #+#    #+#             */
/*   Updated: 2017/11/22 13:42:19 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_epur_str(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\t' || str[i] == '\n' || str[i] == ' ')
		{
			if (str[i - 1] != '\t' && str[i - 1] != '\n' && str[i - 1] != ' ')
			{
				str[j] = ' ';
				j++;
			}
			i++;
		}
		while (str[i] && str[i] != '\t' && str[i] != '\n' && str[i] != ' ')
		{
			str[j] = str[i];
			i++;
			j++;
		}
	}
	str[j] = '\0';
	return (str);
}
