#include "main.h"

int     main(int argc, char **argv)
{
	int		fd;
	int		amount;
	t_tetro	tetrominoses[26];
	
	fd = open(argv[1], O_RDONLY);
	if ((amount = read_tetrominos(fd, tetrominoses)) == -1)
	{
		ft_putstr("Bad lines");
	}
	
	recursive_fill(tetrominoses, amount);
	
	return (0);
}