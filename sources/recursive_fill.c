/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:55:55 by atote             #+#    #+#             */
/*   Updated: 2019/10/19 15:19:34 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		free_last_tetro(char **map, int size, char ch)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (map[i][j] == ch)
				map[i][j] = '.';
			j++;
		}
		i++;
	}
}

void		swap_tetros(t_tetro *tetros, int amount)
{
	t_tetro	tmp;
	int		i;

	i = 0;
	while (i < amount)
	{
		tmp = tetros[i];
		tetros[i] = tetros[i + 1];
		tetros[i + 1] = tetros[i];
		i++;
	}
}

char		**new_map(int s)
{
	char	**map;
	int		i;
	int		j;

	j = 0;
	i = 0;
	map = (char **)malloc(sizeof(char *) * s);
	while (i < s)
	{
		map[i] = (char *)malloc(sizeof(char) * s + 1);
		i++;
	}
	i = 0;
	while (i < s)
	{
		j = 0;
		while (j < s)
		{
			map[i][j] = '.';
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	return (map);
}

t_options	fill_tetros(t_tetro *tetro, t_options *map, int k)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if ((tetro[k].starti + tetro[k].point[i][0] >= map->s) || (tetro[k].startj + tetro[k].point[i][1] >= map->s))
		{
			if (tetro[k].startj < map->s - 1)
				tetro[k].startj = tetro[k].startj + 1;
			else
			{
				tetro[k].startj = 0;
				tetro[k].starti = tetro[k].starti + 1;
			}
			if (tetro[k].starti == map->s)
			{
				tetro[k].startj = 0;
				tetro[k].starti = 0;
				if (k == 0)
				{
					ft_free_array(map->squad, map->s);
					map->s = map->s + 1;
					map->squad = new_map(map->s);
					return (fill_tetros(tetro, map, k));
				}
				k = k - 1;
				tetro[k].startj = tetro[k].startj + 1;
				map->ch = map->ch - 1;
				free_last_tetro(map->squad, map->s, map->ch);
			}
			return (fill_tetros(tetro, map, k));
		}
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (map->squad[tetro[k].starti + tetro[k].point[i][0]][tetro[k].startj + tetro[k].point[i][1]] != '.')
		{
			tetro[k].startj = tetro[k].startj + 1;
			return (fill_tetros(tetro, map, k));
		}
		i++;
	}
	i = 0;
	while (i < 4)
	{
		map->squad[tetro[k].starti + tetro[k].point[i][0]][tetro[k].startj + tetro[k].point[i][1]] = map->ch;
		i++;
	}
	if (k < map->amount - 1)
	{
		k = k + 1;
		tetro[k].startj = 0;
		tetro[k].starti = 0;
		map->ch = map->ch + 1;
		return (fill_tetros(tetro, map, k));
	}
	return (*map);
}

int			recursive_fill(t_tetro *tetros, int amount)
{
	t_options	map;
	int			k;
	t_options	res;
	int			i;

	i = 0;
	k = 0;
	map.amount = amount;
	map.ib = 0;
	map.jb = 0;
	map.s = 4;
	map.squad = new_map(map.s);
	map.ch = 'A';
	res = fill_tetros(tetros, &map, k);
	while (i < map.s)
	{
		ft_putstr(map.squad[i]);
		ft_putstr("\n");
		i++;
	}
	return (0);
}
