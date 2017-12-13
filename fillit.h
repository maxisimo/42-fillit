/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 17:19:23 by maxisimo          #+#    #+#             */
/*   Updated: 2017/12/13 13:12:18 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"

typedef struct	s_map
{
	int			size;
	char		**array;
}				t_map;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_etris
{
	char		**pos;
	int			width;
	int			height;
	char		value;
}				t_etris;

void			min_max(char *str, t_point *min, t_point *max);
void			free_map(t_map *map);
void			print_map(t_map *map);
void			set_piece(t_etris *tetri, t_map *map, t_point *point, char c);
void			free_tetris(t_etris *tetri);

t_etris			*get_piece(char *str, char value);
t_etris			*new_tetri(char **pos, int width, int height, char value);
t_list			*read_tetri(int fd);
t_list			*free_list(t_list *list);
t_map			*new_map(int size);
t_map			*solve(t_list *list);
t_point			*new_point(int x, int y);

int				check_connection(char *str);
int				main(int argc, char **argv);
int				counts(char *str, int count);
int				place(t_etris *tetri, t_map *map, int x, int y);
int				solve_map(t_map *map, t_list *list);
int				ft_sqrt(int n);

#endif
