/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sample.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 11:22:44 by maxisimo          #+#    #+#             */
/*   Updated: 2017/12/13 15:58:35 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	min_max(char *str, t_point *min, t_point *max)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i / 5 < min->y)
				min->y = i / 5;
			if (i / 5 > max->y)
				max->y = i / 5;
			if (i % 5 < min->x)
				min->x = i % 5;
			if (i % 5 > max->x)
				max->x = i % 5;
		}
		i++;
	}
}

t_etris	*get_piece(char *str, char value)
{
	char	**pos;
	int		i;
	t_point	*min;
	t_point	*max;
	t_etris	*tetri;

	min = new_point(3, 3);
	max = new_point(0, 0);
	min_max(str, min, max);
	pos = ft_memalloc(sizeof(char *) * (max->y - min->y + 1));
	i = 0;
	while (i < max->y - min->y + 1)
	{
		pos[i] = ft_strnew(max->x - min->x + 1);
		ft_strncpy(pos[i], str + (min->x) + (i + min->y) * 5,
				max->x - min->x + 1);
		i++;
	}
	tetri = new_tetri(pos, max->x - min->x + 1, max->y - min->y + 1, value);
	ft_memdel((void **)&min);
	ft_memdel((void **)&max);
	return (tetri);
}

int		check_connection(char *str)
{
	int connections;
	int i;

	connections = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				connections++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				connections++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				connections++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				connections++;
		}
		i++;
	}
	return (connections == 6 || connections == 8);
}

int		counts(char *str, int count)
{
	int i;
	int blocs;

	blocs = 0;
	i = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(str[i] == '#' || str[i] == '.'))
				return (1);
			if (str[i] == '#' && ++blocs > 4)
				return (1);
		}
		else if (str[i] != '\n')
			return (1);
		i++;
	}
	if (count == 21 && str[20] != '\n')
		return (1);
	if (!check_connection(str))
		return (1);
	return (0);
}

t_list	*read_tetri(int fd, char *buf, char lettre)
{
	int		count[2];
	t_list	*list;
	t_etris	*tetris;

	list = NULL;
	count[1] = -1;
	while ((count[0] = read(fd, buf, 21)) >= 20)
	{
		tetris = get_piece(buf, lettre++);
		if (counts(buf, count[0]) != 0 || (tetris == NULL))
		{
			ft_memdel((void **)&buf);
			return (free_list(list));
		}
		ft_lstadd(&list, ft_lstnew(tetris, sizeof(t_etris)));
		ft_memdel((void **)&tetris);
	}
	ft_memdel((void *)&buf);
	if (count[1] == 21)
		return (NULL);
	if (count[0] != 0)
		return (free_list(list));
	ft_lstrev(&list);
	return (list);
}
