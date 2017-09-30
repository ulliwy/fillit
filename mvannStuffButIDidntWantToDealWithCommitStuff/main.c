#include "fillit.h"
#include <stdio.h>

int		put_error()
{
	ft_putstr("error\n");
	return (0);
}

int		put_usage()
{
	ft_putstr("usage: fillit file_name\n");
	return (0);
}

void	print_list(t_list *tet)
{
	int		i;
	int		j;

	while (tet)
	{
		i = 0;
		while(i < 4)
		{
			j = 0;
			while (j < 4)
			{
				printf("%c", (((t_tet *)tet->content)->shape)[i][j]);
				j++;
			}
			printf("\n");
			i++;
		}
		tet = tet->next;
	}
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

void print_board(char board[104][104], int size)
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
	t_list	*tetriminos;
	int		fd;
	int		size;

	if (argc != 2)
		return (put_usage());
	initialize_board(board);
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		return (put_error());
	tetriminos = create_list(fd);
	if (!tetriminos)
		return (put_error());
	size = get_size(tetriminos);
	size = get_nearest_square(size);
	print_list(tetriminos);
	if (!solve(board, &size, tetriminos))
		return (put_error());
	print_board(board, size);
	return (0);
}
