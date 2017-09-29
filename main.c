#include "fillit.h"

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
	//if (!solve(board, size, tetriminos))
	//	return (put_error());
	//print_board(board);
	return (0);
}
