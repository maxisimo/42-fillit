/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 14:46:02 by maxisimo          #+#    #+#             */
/*   Updated: 2017/12/10 15:15:30 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		solve_map(t_map *map, t_list *list)
{
	int		x;
	int		y;
	t_etris	*tetri;

	if (list == NULL)
		return (1);
	y = 0;
	tetri = (t_etris *)(list->content);
	while (y < map->size - tetri->height + 1)
	{
		x = 0;
		while (x < map->size - tetri->width + 1)
		{
			if (placement(tetri, map, x, y))
			{
				if (solve_map(map, list->next))
					return (1);
				else
					set_piece(tetri, map, new_point(x, y), '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}

int		ft_sqrt(int n)
{
	int size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

t_map	*solve(t_list *list)
{
	t_map	*map;
	int		size;

	size = ft_sqrt(ft_lstcount(list) * 4);
	map = new_map(size);
	while (!solve_map(map, list))
	{
		size++;
		free_map(map);
		map = new_map(size);
	}
	return (map);
}
