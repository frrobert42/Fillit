/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:09:30 by frrobert          #+#    #+#             */
/*   Updated: 2018/11/27 13:11:03 by frrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int			fd;
	t_etris		tetris[27];

	fd = open(argv[1], O_RDONLY);
	ft_bzero(tetris, sizeof(t_etris) * 27);
	if (argc == 1 || argc > 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (0);
	}
	ft_read(fd, tetris);
	return (0);
}
