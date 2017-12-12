/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:46:04 by maxisimo          #+#    #+#             */
/*   Updated: 2017/11/26 18:20:48 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	long	nb;
	long	negative;

	i = 0;
	nb = 0;
	negative = 0;
	while (str[i] == '\n' || str[i] == '\v' || str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		negative = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += ((long)str[i] - '0');
		i++;
	}
	if (negative == 1)
		return (-nb);
	else
		return (nb);
}
