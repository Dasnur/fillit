/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:04:43 by atote             #+#    #+#             */
/*   Updated: 2019/10/19 15:29:52 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		amount;
	t_tetro	tetrominoses[26];

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if ((amount = read_tetrominos(fd, tetrominoses)) == -1)
	{
		ft_putstr_fd("error\n", 1);
		return (0);
	}
	recursive_fill(tetrominoses, ++amount);
	return (0);
}
