/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 13:27:46 by iprokofy          #+#    #+#             */
/*   Updated: 2017/10/02 14:57:00 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** created by: iprokofy, mvann
*/

#include "fillit.h"

int		put_msg(int type)
{
	if (type)
		ft_putstr("usage: fillit file_name\n");
	else
		ft_putstr("error\n");
	return (0);
}

void	initialize_board(char board[104][104])
{
	int i;
	int j;

	i = 0;
	while (i < 104)
	{
		j = 0;
		while (j < 104)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
}

int		get_nearest_square(int size)
{
	int n;

	n = 2;
	while (size * 4 < n * n)
		n++;
	return (n);
}

void	print_board(char board[104][104], int size)
{
	int row;
	int col;

	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			ft_putchar(board[row][col] ? board[row][col] : '.');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}

int		main(int argc, char **argv)
{
	char	board[104][104];
	char	buf[20];
	t_list	*tetriminos;
	int		fd;
	int		size;

	if (argc != 2)
		return (put_msg(1));
	initialize_board(board);
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		return (put_msg(0));
	tetriminos = create_list(fd, buf);
	if (!tetriminos)
		return (put_msg(0));
	size = get_size(tetriminos);
	size = get_nearest_square(size);
	if (!solve(board, &size, tetriminos))
		return (put_msg(0));
	print_board(board, size);
	return (0);
}
