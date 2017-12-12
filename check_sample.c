/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sample.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 11:22:44 by maxisimo          #+#    #+#             */
/*   Updated: 2017/12/12 14:01:23 by maxisimo         ###   ########.fr       */
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

int		counts(char *str)
{
	int		i[5];

	ft_bzero(i, sizeof(int) * 5);
	while (str[i[1]])
		i[1]++;
	i[1] = i[1] / 21;
	while (str[i[0]++])
	{
		i[2] = str[i[0]] == '.' ? i[2] + 1 : i[2];
		i[3] = str[i[0]] == '#' ? i[3] + 1 : i[3];
		i[4] = str[i[0]] == '\n' ? i[4] + 1 : i[4];
	}
	while (i[0] < i[1])
	{
		if (!((i[2] == 12 * i[1]) && (i[3] == 4 * i[1]) && (i[4] == 5 * i[1]) &&
					str[4 + i[0] * 21] == '\n' && str[9 + i[0] * 20] == '\n'
					&& str[14 + i[0] * 20] == '\n' && str[19 + i[0] * 20]
					== '\n' && str[20 + i[0] * 20] == '\n'))
			return (0);
		i[0]++;
	}
	return (1);
}

t_list	*read_tetri(int fd)
{
	int		count;
	char	buf[21];
	char	lettre;
	t_list	*list;
	t_etris	*tetris;

	list = NULL;
	lettre = 'A';
	while ((count = read(fd, buf, 21)) == 21)
	{
		tetris = get_piece(buf, lettre++);
		if (counts(buf) != 1 || (tetris == NULL))
		{
			ft_memdel((void **)&buf);
			return (free_list(list));
		}
		ft_lstadd(&list, ft_lstnew(tetris, sizeof(t_etris)));
		ft_memdel((void **)&tetris);
	}
	if (count != 0)
		return (free_list(list));
	ft_lstrev(&list);
	return (list);
}
