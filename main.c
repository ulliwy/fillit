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
		printf("\n");
		tet = tet->next;
	}
}

int		main(int argc, char **argv)
{
	//char	board[104][104];
	t_list	*tetriminos;
	int		fd;
	int		size;

	if (argc != 2)
		return (put_usage());
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		return (put_error());
	tetriminos = create_list(fd);
	if (!tetriminos)
		return (put_error());
	size = get_size(tetriminos);
	print_list(tetriminos);
	ft_lstdel(&tetriminos, &ft_lstdelone);
	//if (!solve(board, size, tetriminos))
	//	return (put_error());
	//print_board(board);
	return (0);
}
