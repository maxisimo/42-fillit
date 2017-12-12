/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 13:25:31 by maxisimo          #+#    #+#             */
/*   Updated: 2017/11/22 13:36:43 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putbase(unsigned int n, int base)
{
	int		tab[100];
	int		j;

	j = 0;
	while (n != 0)
	{
		tab[j] = n % base;
		n = n / base;
		j++;
	}
	while (j > 0)
	{
		j--;
		if (tab[j] <= 9 && tab[j] >= 0)
			ft_putchar(tab[j] + '0');
		if (tab[j] >= 10 && tab[j] <= 15)
			ft_putchar(tab[j] + 55);
	}
}
