/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:55:55 by atote             #+#    #+#             */
/*   Updated: 2019/10/26 15:33:12 by atote            ###   ########.fr       */
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

char		**new_map(int s)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	map = (char **)malloc(sizeof(char *) * s);
	while (i < s)
	{
		map[i] = (char *)malloc(sizeof(char) * (s + 1));
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

t_options	fill_tetros(t_tetro *t, t_options *m, int k)
{
	int		i;

	i = 0;
	if (set_cond(t, m, &k))
		return (fill_tetros(t, m, k));
	while (i < 4)
	{
		m->sq[t[k].si + t[k].pt[i][0]][t[k].sj + t[k].pt[i][1]] = m->ch;
		i++;
	}
	if (k < m->amount - 1)
	{
		k = k + 1;
		t[k].sj = 0;
		t[k].si = 0;
		m->ch = m->ch + 1;
		return (fill_tetros(t, m, k));
	}
	return (*m);
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
	map.s = 2;
	map.sq = new_map(map.s);
	map.ch = 'A';
	res = fill_tetros(tetros, &map, k);
	while (i < map.s)
	{
		ft_putstr(map.sq[i]);
		ft_putstr("\n");
		i++;
	}
	return (0);
}
