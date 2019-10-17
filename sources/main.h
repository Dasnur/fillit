//
// Created by dasnur on 11.10.2019.
//

#ifndef FILLIT_MAIN_H
#define FILLIT_MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"

typedef struct s_tetro
{
	int	point[4][2];
	int starti;
	int startj;
}				t_tetro;

typedef struct s_options
{
	int 	ib;
	int 	jb;
	int 	s;
	char	**squad;
	int 	amount;
	char	ch;
}				t_options;

int     read_tetrominos(int fd, t_tetro *tetrominoses);
int		validate_tetrominos(char **map);
int		check_sharps_line(char ** map, int i, int *count);
int 	check_chars_in_line(char *line);
void	get_tetrominos(char **map, t_tetro *tetrominoses);
void	free_last_tetro(char **map, int size, char ch);
char	**new_map(int s);
t_options	fill_tetros(t_tetro *tetro, t_options *map, int k);
int		recursive_fill(t_tetro *tetros, int amount);

#endif //FILLIT_MAIN_H
