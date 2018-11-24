#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include "./libft/libft.h"

# define BUFF_SIZE 1

typedef struct		matrix matrix;
struct matrix
{
	int		x;
	int		y;
};

typedef struct		piece piece;
struct piece
{
	char	letter;
	matrix	coords[4];
};

int   check_input(char *argv);
int   valid_format(int fd);
int		check_number_tetri(char *line, int i);
int		valid_tetri_form(char *fourlines, int len);
int		get_next_line(const int fd, char **line);
int		valid_format(int fd);
int		check_carac_length(char *line, int len, int nb_lines);

#endif

