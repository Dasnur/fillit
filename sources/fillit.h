/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:06:16 by atote             #+#    #+#             */
/*   Updated: 2019/10/26 16:37:25 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

# define DIFF t[*k].sj + t[*k].pt[i][1] >= m->s
# define D1 m->sq[t[*k].si + t[*k].pt[i][0]][t[*k].sj + t[*k].pt[i][1]] != '.'

typedef struct	s_tetro
{
	int	pt[4][2];
	int	si;
	int	sj;
}				t_tetro;

typedef struct	s_options
{
	int		ib;
	int		jb;
	int		s;
	char	**sq;
	int		amount;
	char	ch;
}				t_options;

int				new_recursive_fill(t_tetro *t, t_options *m, int *k);
int				set_cond(t_tetro *tetro, t_options *map, int *k);
int				read_tetrominos(int fd, t_tetro *tetrominoses);
int				validate_tetrominos(char **map);
int				check_sharps_line(char **map, int i, int *count);
int				check_chars_in_line(char *line);
void			get_tetrominos(char **map, t_tetro *tetrominoses);
void			free_last_tetro(char **map, int size, char ch);
char			**new_map(int s);
t_options		fill_tetros(t_tetro *tetro, t_options *map, int *k);
int				recursive_fill(t_tetro *tetros, int amount);
int				mem_clear(char ***map, int i, int flag);

#endif
