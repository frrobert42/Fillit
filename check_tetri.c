/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:03:20 by cdelahay          #+#    #+#             */
/*   Updated: 2018/11/25 19:43:51 by towelie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_input(char *argv)
{
	int		fd;
	int		nb_tetri;

	if (((fd = open(argv, O_RDONLY)) == -1))
		return (-1);
	if ((nb_tetri = valid_format(fd)) == -1)
		return (-1);
	close(fd);
	if (nb_tetri <= 26)
		return (1);
	return (-1);
}

int		valid_format(int fd)
{
	int		nb_lines;
	int		i;
	char	*line;

	nb_lines = 1;
	while (get_next_line(fd, &line))
	{
		i = -1;
		if (check_carac_length(line, ft_strlen(line), nb_lines) == -1)
			return (-1);
		if (check_number_tetri(line, i) == -1)
			return (-1);
		nb_lines++;
	}
	if (get_next_line(fd, &line) == 0 && ft_strlen(line) == 0)
		return (-1);
	return (nb_lines / 5);
}

int		check_carac_length(char *line, int len, int nb_lines)
{
	int i;

	i = 0;
	if (nb_lines % 5 == 0)
	{
		if (len == 0)
			return (1);
		else
			return (-1);
	}
	if (len != 4)
		return (-1);
	while (i < len)
	{
		if (line[i] == '.' || line[i] == '#')
			i++;
		else
			return (-1);
	}
	return (1);
}

int		valid_tetri_form(char *form, int len)
{
	int i;
	int carac;

	i = 0;
	carac = 1;
	while (i < len)
	{
		if (form[i] == '#' && carac < 4)
		{
			if (form[i + 1] != '#' && form[i + 4] != '#' && form[i - 1] != '#')
				return (-1);
			if (form[i + 1] == '#')
				carac++;
			if (form[i + 4] == '#')
				carac++;
		}
		i++;
		if (carac == 4)
			return (1);
	}
	return (-1);
}

int		check_number_tetri(char *line, int i)
{
	char			*temp;
	static char		*fourlines;
	int				len;
	int				nb_carac;

	nb_carac = 0;
	if (fourlines == NULL)
		fourlines = ft_strnew(1);
	temp = ft_strjoin(fourlines, line);
	free(fourlines);
	fourlines = temp;
	if ((len = (ft_strlen(fourlines))) == 16)
	{
		while (++i < len)
		{
			if (fourlines[i] == '#')
				nb_carac++;
		}
		if (nb_carac != 4 )
			return (-1);
		if (valid_tetri_form(fourlines, len) == -1)
			return (-1);
		ft_strdel(&fourlines);
	}
	return (1);
}
