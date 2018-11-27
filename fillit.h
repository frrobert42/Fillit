/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:48:41 by frrobert          #+#    #+#             */
/*   Updated: 2018/11/27 14:32:45 by frrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"

# define BUFF_SIZE 1

typedef struct s_etris	t_etris;
struct	s_etris
{
	unsigned char	letter;
	unsigned char	x;
	unsigned char	y;
	unsigned char	width;
	unsigned char	height;
	unsigned char	coord_x[4];
	unsigned char	coord_y[4];
};

int		ft_read(int fd, t_etris *tetris);
void	min_max(char *m, char *buf);
t_etris	get_pieces(char *buf, char letter);
int		check_count(char *buf, int count);
int		check_connection(char *buf);

#endif
