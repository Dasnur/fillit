#include "../libft/libft.h"
#include "main.h"

int 	check_chars_in_line(char *line)
{
	int i;
	
	i = 0;
	while (i < ft_strlen(line))
	{
		if (line[i] != '#' && line[i] != '.')
			return (1);
		i++;
	}
	return (0);
}

int		check_sharps_line(char ** map, int i, int *count)
{
	int flag;
	int j;
	
	j = 0;
	flag = 0;
	while (j < 4)
	{
		if (map[i][j] == '#')
		{
			if (i != 3)
			{
				if (map[i + 1][j] == '#')
					flag = 1;
			}
			if (flag != 1)
				flag = 2;
			*count = *count + 1;
		}
		j++;
	}
	return (flag);
}

int		validate_tetrominos(char **map)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (i < 4)
	{
		if (check_sharps_line(map, i, &count) == 2)
			break;
		i++;
	}
	if (count == 4)
		return (0);
	return (1);
}

int     read_tetrominos(int fd, t_tetro *tetrominoses)
{
	int		i;
	char	*line;
	char	**map;
	int 	amount;
	
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
			get_next_line(fd, &line);
		}
		if (line[0] == '\n' && i != 4)
			return (-1);
		map[i] = line;
		if (ft_strlen(line) != 4)
			return (-1);
		if (check_chars_in_line(line))
			return (-1);
		i++;
		if (i > 4)
			return (-1);
		if (i == 4)
		{
			if (validate_tetrominos(map) == 0)
				get_tetrominos(map, &tetrominoses[amount++]);
			else
				return (-1);
		}
	}
	return (amount);
}
