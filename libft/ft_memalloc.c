/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 18:57:20 by maxisimo          #+#    #+#             */
/*   Updated: 2017/11/12 19:05:52 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = ((char *)malloc(sizeof(char) * (size)));
	if (mem == NULL)
		return (NULL);
	ft_memset(mem, 0, size);
	return ((void *)mem);
}
