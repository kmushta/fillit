/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:28:37 by kmushta           #+#    #+#             */
/*   Updated: 2017/11/16 11:28:39 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "fillit.h"

int		ft_read_tetrimino_line(char **line, int fd)
{
	int		i;
	int		q;
	char	c;

	*line = (char *)malloc(sizeof(char) * (TETRIMINO_SIZE + 1));
	if (!*line)
		return (-1);
	i = 0;
	while (i <= TETRIMINO_SIZE)
		(*line)[i++] = 0;
	i = 0;
	q = read(fd, &(*line)[i], 1);
	while (q && ((*line)[i] == '.' || (*line)[i] == '#'))
		q = read(fd, &(*line)[++i], 1);
	c = (*line)[TETRIMINO_SIZE];
	(*line)[TETRIMINO_SIZE] = 0;
	if ((c != '\n' && c) || i != 4)
		return (-1);
	return (0);
}

int		ft_read_tetrimino(char ***tetrimino, int fd)
{
	int		i;

	*tetrimino = (char **)malloc(sizeof(char *) * (TETRIMINO_SIZE + 1));
	if (!*tetrimino)
		return (-1);
	i = 0;
	while (i <= TETRIMINO_SIZE)
		(*tetrimino)[i++] = 0;
	i = 0;
	while (i < TETRIMINO_SIZE)
		if (ft_read_tetrimino_line(&((*tetrimino)[i++]), fd))
			return (-1);
	return (0);
}

int		ft_delall(char ****tetriminos)
{
	ft_del_tetriminos(tetriminos);
	return (-1);
}

int		ft_read(char ****tetriminos, int fd)
{
	int		i;
	char	buff;
	int		q;

	i = -1;
	while (++i < BUFFER_SIZE)
	{
		if (ft_read_tetrimino(&((*tetriminos)[i]), fd))
			return (ft_delall(tetriminos));
		if (ft_validate_tetrimino((*tetriminos)[i]))
			return (ft_delall(tetriminos));
		q = read(fd, &buff, 1);
		if (q < 1)
			break ;
		if (buff != '\n')
			return (ft_delall(tetriminos));
	}
	return (0);
}

int		ft_read_tetriminos(char ****tetriminos, char *file_name)
{
	int		i;
	int		fd;

	*tetriminos = (char ***)malloc(sizeof(char **) * (BUFFER_SIZE + 1));
	if (!*tetriminos)
		return (-1);
	i = 0;
	while (i <= BUFFER_SIZE)
		(*tetriminos)[i++] = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	if (ft_read(tetriminos, fd))
		return (-1);
	close(fd);
	return (0);
}
