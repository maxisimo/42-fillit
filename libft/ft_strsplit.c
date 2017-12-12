/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:07:27 by maxisimo          #+#    #+#             */
/*   Updated: 2017/11/24 17:46:44 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nb_words(char const *str, char c)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] != c)
		{
			i++;
			j = 1;
		}
		if (str[i] == c || str[i] == '\0')
		{
			if (j == 1)
				count += 1;
		}
		j = 0;
		(str[i] == '\0') ? 0 : i++;
	}
	return (count);
}

static int		ft_nb_char(char const *str, int deb, char c)
{
	while (str[deb] && str[deb] != c)
		deb++;
	return (deb);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!s || !(tab = (char**)malloc(sizeof(char*) * (ft_nb_words(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			k = 0;
			if (!(tab[j] = (char*)malloc(sizeof(char) * ft_nb_char(s, i, c))))
				return (0);
			while (s[i] && s[i] != c)
				tab[j][k++] = s[i++];
			tab[j++][k] = '\0';
		}
	}
	tab[j] = NULL;
	return (tab);
}
