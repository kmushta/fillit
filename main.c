/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:26:59 by kmushta           #+#    #+#             */
/*   Updated: 2017/11/16 11:27:06 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

void	ft_print_result(char **arr)
{
	int i;

	i = 0;
	while (*(arr + i))
	{
		if (**(arr + i))
		{
			ft_putstr_fd(*(arr + i), 1);
			ft_putstr_fd("\n", 1);
		}
		i++;
	}
}

void	ft_print_usage(char *name)
{
	ft_putstr_fd("usage: ", 1);
	ft_putstr_fd(name, 1);
	ft_putstr_fd(" [file_name]\n", 1);
}

int		main(int argc, char **argv)
{
	char	***tetriminos;
	char	**result;
	int		*t;
	int		*sizes;

	if (argc != 2)
		ft_print_usage(*argv);
	else if (!ft_read_tetriminos(&tetriminos, *(argv + 1)))
	{
		ft_rabbin(tetriminos);
		t = ft_recode(tetriminos, &sizes);
		g_size = ft_sqrt(ft_getcount(t) * 4);
		ft_del_tetriminos(&tetriminos);
		ft_calculate_tetriminos(&result, t, sizes);
		ft_recode_out(&result);
		ft_print_result(result);
		ft_fclean(&result);
	}
	else
		ft_putstr_fd("error\n", 1);
	return (0);
}
