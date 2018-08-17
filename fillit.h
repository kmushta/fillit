/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:37:39 by kmushta           #+#    #+#             */
/*   Updated: 2017/11/16 11:37:47 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFFER_SIZE 26
# define TETRIMINO_SIZE 4
# define MAX_SIZE 20

int			g_size;

char		**ft_make_arr2(int size);
void		ft_arr_fill(int *arr, int c, int size);
void		ft_mini_rabbin(char **arr);
void		ft_rabbin(char ***chr);
void		ft_putstr_fd(char *str, int fd);
int			ft_sqrt(int n);
void		ft_del_tetriminos(char ****tetriminos);
int			ft_read_tetrimino_line(char **line, int fd);
int			ft_read_tetrimino(char ***tetrimino, int fd);
int			ft_ret_cols(char **tetrimino, int x, int y);
int			ft_validate_tetrimino(char **tetrimino);
int			ft_read(char ****tetriminos, int fd);
int			ft_read_tetriminos(char ****tetriminos, char *file_name);
void		ft_fclean(char ***arr);
int			ft_getcount(int *tetriminos);
int			ft_issafe(char ***arr, int *tetrimino, int *tab, char c);
void		ft_rem(char ***arr, int *tetrimino, int *tab);
void		ft_recode_out(char ***arr);
int			ft_calculate(char ***arr, int *tetriminos, int *sizes, int n);
void		ft_fill(char ***arr, int size);
int			ft_calculate_tetriminos(char ***arr, int *tetriminos, int *sizes);
int			*ft_recode(char ***tetriminos, int **sizes);

#endif
