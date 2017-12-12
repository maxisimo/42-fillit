/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 18:44:52 by maxisimo          #+#    #+#             */
/*   Updated: 2017/11/12 18:51:36 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	nb;
	int		tab[100];
	int		i;

	i = 0;
	if (n == 0)
		ft_putchar('0');
	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	while (nb != 0)
	{
		tab[i] = nb % 10;
		nb = nb / 10;
		i++;
	}
	while (i > 0)
	{
		i--;
		ft_putchar(tab[i] + '0');
	}
}
