#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;

	if (argc == 1 || argc > 2)
	{
		ft_putstr("usage: fillit source_sample_text");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	if (valid_format(fd) == -1)
		printf("ERROR");
	return (0);
}
