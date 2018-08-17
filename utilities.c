/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:36:32 by kmushta           #+#    #+#             */
/*   Updated: 2017/11/16 11:36:34 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}

int		ft_sqrt(int n)
{
	int q;

	q = 0;
	while (q * q < n)
		q++;
	return (q);
}

int		ft_getcount(int *tetriminos)
{
	int i;

	i = 0;
	while (tetriminos[i] > -1)
		i += 8;
	return ((i >> 3));
}
