/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:32:04 by kmushta           #+#    #+#             */
/*   Updated: 2017/11/16 11:32:05 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

void	ft_mini_rabbin(char **arr)
{
	int k;
	int j;
	int x;

	k = 0;
	j = 4;
	while (arr[0][k] != '\0' && arr[1][k] != '\0' && arr[2][k] != '\0'
		&& arr[3][k] != '\0')
	{
		if (arr[0][k] == '.' && arr[1][k] == '.' && arr[2][k] == '.'
			&& arr[3][k] == '.')
		{
			x = k - 1;
			while (++x < 4)
			{
				arr[0][x] = arr[0][x + 1];
				arr[1][x] = arr[1][x + 1];
				arr[2][x] = arr[2][x + 1];
				arr[3][x] = arr[3][x + 1];
			}
			k--;
			j--;
		}
		k++;
	}
}

void	ft_rabbin(char ***chr)
{
	int i;
	int j;
	int k;
	int x;

	i = -1;
	while (chr[++i] != NULL)
	{
		ft_mini_rabbin(chr[i]);
		j = -1;
		while (chr[i][++j])
		{
			k = 0;
			while (chr[i][j][k] && chr[i][j][k] != '#')
				k++;
			if (!chr[i][j][k])
			{
				free(chr[i][j--]);
				x = j;
				while (chr[i][++x + 1])
					chr[i][x] = chr[i][x + 1];
				chr[i][x] = 0;
			}
		}
	}
}

void	ft_recode_out(char ***arr)
{
	int i;
	int j;

	i = 0;
	while (i < g_size)
	{
		j = 0;
		while (j < g_size)
		{
			if ((*arr)[i][j])
				(*arr)[i][j] += 64;
			else
				(*arr)[i][j] = 46;
			j++;
		}
		i++;
	}
}

int		*ft_recode(char ***tetriminos, int **sizes)
{
	int		*arr;
	int		tab[4];

	arr = (int *)malloc(sizeof(int) * (209));
	(*sizes) = (int *)malloc(sizeof(int) * (52));
	ft_arr_fill(arr, -1, 209);
	ft_arr_fill((*sizes), 0, 52);
	(*tab) = -1;
	while (tetriminos[++(*tab)] && ((*(tab + 1)) = -1))
	{
		(*(tab + 3)) = 0;
		while (tetriminos[(*tab)][++(*(tab + 1))] && ((*(tab + 2)) = -1))
			while (tetriminos[(*tab)][(*(tab + 1))][++(*(tab + 2))])
				if (tetriminos[(*tab)][(*(tab + 1))][(*(tab + 2))] == '#')
				{
					arr[(*tab) * 8 + (*(tab + 3))++] = (*(tab + 1));
					arr[(*tab) * 8 + (*(tab + 3))++] = (*(tab + 2));
				}
		(*sizes)[((*tab) << 1)] = (*(tab + 1));
		(*sizes)[((*tab) << 1) + 1] = (*(tab + 2));
	}
	return (arr);
}
