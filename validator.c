/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:30:50 by kmushta           #+#    #+#             */
/*   Updated: 2017/11/16 11:30:51 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_ret_cols(char **tetrimino, int x, int y)
{
	int q;
	int c;

	q = 0;
	c = x - 1;
	if (c >= 0 && c < TETRIMINO_SIZE && tetrimino[c][y] == '#')
		q++;
	c = y + 1;
	if (c >= 0 && c < TETRIMINO_SIZE && tetrimino[x][c] == '#')
		q++;
	c = x + 1;
	if (c >= 0 && c < TETRIMINO_SIZE && tetrimino[c][y] == '#')
		q++;
	c = y - 1;
	if (c >= 0 && c < TETRIMINO_SIZE && tetrimino[x][c] == '#')
		q++;
	return (q);
}

int		ft_validate_tetrimino(char **tetrimino)
{
	int i;
	int j;
	int q;
	int c;

	c = 0;
	q = 0;
	i = -1;
	while (++i < TETRIMINO_SIZE)
	{
		j = -1;
		while (++j < TETRIMINO_SIZE)
		{
			if (tetrimino[i][j] == '#')
			{
				c += ft_ret_cols(tetrimino, i, j);
				q++;
			}
		}
	}
	if (q != 4)
		return (-1);
	if (!(c == 6 || c == 8))
		return (-1);
	return (0);
}
