/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:34:06 by kmushta           #+#    #+#             */
/*   Updated: 2017/11/16 11:34:07 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_arr_fill(int *arr, int c, int size)
{
	int i;

	i = 0;
	while (i < size)
		arr[i++] = c;
}

void	ft_del_tetriminos(char ****tetriminos)
{
	int i;
	int j;

	i = 0;
	while ((*tetriminos)[i])
	{
		j = 0;
		while ((*tetriminos)[i][j])
		{
			free((*tetriminos)[i][j]);
			(*tetriminos)[i][j] = 0;
			j++;
		}
		free((*tetriminos)[i]);
		(*tetriminos)[i] = 0;
		i++;
	}
	free(*tetriminos);
	*tetriminos = 0;
}

void	ft_fclean(char ***arr)
{
	int i;

	i = 0;
	while ((*arr)[i])
	{
		free((*arr)[i]);
		(*arr)[i] = 0;
		i++;
	}
	free(*arr);
	*arr = 0;
}

void	ft_fill(char ***arr, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			(*arr)[i][j] = 0;
			j++;
		}
		i++;
	}
}

char	**ft_make_arr2(int size)
{
	char	**arr;
	int		i;
	int		j;

	arr = (char **)malloc(sizeof(char *) * (size + 1));
	if (!arr)
		return (0);
	i = -1;
	while (++i <= size)
		arr[i] = 0;
	i = -1;
	while (++i < size)
	{
		arr[i] = (char *)malloc(sizeof(char) * (size + 1));
		if (!arr[i])
		{
			ft_fclean(&arr);
			return (0);
		}
		j = -1;
		while (++j <= size)
			arr[i][j] = 0;
	}
	return (arr);
}
