/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:35:11 by kmushta           #+#    #+#             */
/*   Updated: 2017/11/16 11:35:12 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

int		ft_issafe(char ***arr, int *tetrimino, int *tab, char c)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		if (*(*(*arr + *tab + *(tetrimino + i))
			+ *(tab + 1) + *(tetrimino + i + 1)))
			return (0);
		i += 2;
	}
	i = 0;
	while (i < 8)
	{
		*(*(*arr + *tab + *(tetrimino + i))
			+ *(tab + 1) + *(tetrimino + i + 1)) = c + 1;
		i += 2;
	}
	return (1);
}

void	ft_rem(char ***arr, int *tetrimino, int *tab)
{
	int i;

	i = 0;
	while (i < 8)
	{
		*(*(*arr + *tab + *(tetrimino + i))
			+ *(tab + 1) + *(tetrimino + i + 1)) = 0;
		i += 2;
	}
}

int		ft_calculate(char ***arr, int *tetriminos, int *sizes, int n)
{
	int tab[4];
	int max_i;
	int max_j;

	if (*tetriminos < 0)
		return (1);
	max_i = g_size - *sizes + 1;
	max_j = g_size - *(sizes + 1) + 1;
	*tab = 0;
	while (*tab < max_i)
	{
		*(tab + 1) = 0;
		while (*(tab + 1) < max_j)
		{
			if (ft_issafe(arr, tetriminos, tab, n))
			{
				if (ft_calculate(arr, tetriminos + 8, sizes + 2, n + 1))
					return (1);
				ft_rem(arr, tetriminos, tab);
			}
			(*(tab + 1))++;
		}
		(*tab)++;
	}
	return (0);
}

int		ft_calculate_tetriminos(char ***arr, int *tetriminos, int *sizes)
{
	char	**result;

	result = ft_make_arr2(MAX_SIZE);
	if (!result)
		return (0);
	g_size = ft_sqrt(ft_getcount(tetriminos) * 4);
	while (g_size < MAX_SIZE)
	{
		ft_fill(&result, g_size);
		if (ft_calculate(&result, tetriminos, sizes, 0))
		{
			*arr = result;
			return (g_size);
		}
		g_size++;
	}
	return (0);
}
