/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetrominos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:59:26 by atote             #+#    #+#             */
/*   Updated: 2019/10/19 15:04:14 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	norm_coord_tetro(t_tetro *tetrominoses, int t)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (i < 4)
	{
		while (i < 4)
		{
			if (tetrominoses->point[i][t] == 0)
				flag = 1;
			i++;
		}
		if (flag == 0)
		{
			i = 0;
			while (i < 4)
			{
				tetrominoses->point[i][t] = tetrominoses->point[i][t] - 1;
				i++;
			}
			i = -1;
		}
		i++;
	}
}

void	get_tetrominos(char **map, t_tetro *tetrominoses)
{
	int i;
	int j;
	int k;

	k = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (map[i][j] == '#')
			{
				tetrominoses->point[k][0] = i;
				tetrominoses->point[k][1] = j;
				k++;
			}
			j++;
		}
		i++;
	}
	tetrominoses->starti = 0;
	tetrominoses->startj = 0;
	norm_coord_tetro(tetrominoses, 0);
	norm_coord_tetro(tetrominoses, 1);
}
