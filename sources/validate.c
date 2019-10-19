/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:48:08 by atote             #+#    #+#             */
/*   Updated: 2019/10/19 16:25:42 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

int		check_chars_in_line(char *line)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(line))
	{
		if (line[i] != '#' && line[i] != '.')
			return (1);
		i++;
	}
	return (0);
}

int		check_sharps_line(char **map, int i, int *count)
{
	int flag;
	int j;

	j = 0;
	flag = 0;
	while (j < 4)
	{
		while (map[i][j] == '#')
		{
			if (i != 3)
			{
				if (map[i + 1][j] == '#')
					flag = 1;
			}
			if (flag != 1)
				flag = 2;
			*count = *count + 1;
			j++;
		}
		if (flag == 1 || flag == 2)
			return (flag);
		j++;
	}
	return (flag);
}

int		validate_tetrominos(char **map)
{
	int i;
	int count;
	int	flag;

	count = 0;
	i = 0;
	while (i < 4)
	{
		if ((flag = check_sharps_line(map, i, &count)) == 2)
			break ;
		i++;
	}
	if (count == 4)
		return (0);
	return (1);
}

int		read_tetrominos(int fd, t_tetro *tetrominoses)
{
	int		i;
	char	*line;
	char	**map;
	int		amount;

	amount = 0;
	i = 0;
	map = (char **)malloc(sizeof(char *) * 4);
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == '\0' && i == 4)
		{
			ft_free_array(map, 4);
			free(map);
			map = (char **)malloc(sizeof(char *) * 4);
			i = 0;
			if (get_next_line(fd, &line) == 0)
				return (-1);
		}
		if (line[0] == '\0' && i != 4)
			return (-1);
		map[i++] = line;
		if (ft_strlen(line) != 4 || check_chars_in_line(line) || i > 4)
			return (-1);
		if (i == 4)
		{
			if (validate_tetrominos(map) == 0)
				get_tetrominos(map, &tetrominoses[amount++]);
			else
				return (-1);
		}
	}
	if (i != 4)
		return (-1);
	return (amount);
}
