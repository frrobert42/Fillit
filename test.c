/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:03:22 by cdelahay          #+#    #+#             */
/*   Updated: 2018/11/27 14:34:02 by frrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_read(int fd, t_etris *tetris)
{
	char	buf[22];
	char	letter;
	int		count;
	int		i;

	i = 0;
	letter = 'A' -1;
	while ((count = read(fd, buf, 21)) >= 20)
	{
		if (check_count(buf, count) != 0)
			return (0);
		tetris[i] = get_pieces(buf, ++letter);
		printf("Test : %c\n", letter);
	}
	return (0);
}

void		min_max(char *m, char *buf)
{
	int		i;

	i = 0;
	m[0] = 3;
	m[1] = 0;
	m[2] = 3;
	m[3] = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			if (i % 5 < m[0])
				m[0] = i % 5;
			if (i % 5 > m[1])
				m[1] = i % 5;
			if (i / 5 < m[2])
				m[2] = i / 5;
			if (i / 5 > m[3])
				m[3] = i / 5;
		}
		i++;
	}
}

t_etris		get_pieces(char *buf, char letter)
{
	t_etris tetris;
	char	m[4];
	int		x;
	int		y;

	min_max(m, buf);
	tetris.width = m[1] - m[0] + 1;
	tetris.height = m[3] - m[2] + 1;
	tetris.letter = letter;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (buf[x + y * 5] == '#')
			{
				tetris.coord_x[x] = '0' + x - m[0];
				tetris.coord_y[y] = '0' + y - m[2];
				printf("x: %d, y: %d\n", (x - m[0]), y - m[2]);
			}
			x++;
		}
		y++;
	}
	printf("Coord X : %s\n", tetris.coord_x);
	printf("Coord Y : %s\n", tetris.coord_y);
	printf("Letter : %c\n", tetris.letter);
	return (tetris);
}

int			check_count(char *buf, int count)
{
	int i;
	int block;

	i = 0;
	block = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(buf[i] == '#' || buf[i] == '.'))
				return (1);
			if (buf[i] == '#' && ++block > 4)
				return (2);
		}
		else if (buf[i] != '\n')
			return (3);
		i++;
	}
	if (count == 21 && buf[i] != '\n')
		return (4);
	if (check_connection(buf) == 0)
		return (5);
	return (0);
}

int			check_connection(char *buf)
{
	int i;
	int touch;

	i = 0;
	touch = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			if ((i - 1) >= 0 && buf[i - 1] == '#')
				touch++;
			if ((i + 1) < 20 && buf[i + 1] == '#')
				touch++;
			if ((i - 5) >= 0 && buf[i - 5] == '#')
				touch++;
			if ((i + 5) < 20 && buf[i + 5] == '#')
				touch++;
		}
		i++;
	}
	printf("%d\n", touch);
	return (touch == 6 || touch == 8);
}
