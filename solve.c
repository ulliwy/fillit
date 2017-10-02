/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 12:47:47 by mvann             #+#    #+#             */
/*   Updated: 2017/10/02 13:19:07 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		delete_tet(char board[104][104], int size, int row, int col, t_tet *tet)
{
	int i;
	int j;

	i = 0;
	while (i < 4 - tet->row)
	{
		j = 0;
		while (j < 4 - tet->col)
		{
			if (tet->shape[tet->row + i][tet->col + j] == '#')
			{
				if (col + j >= size || row + i >= size)
			 		return (0);
				board[row + i][col + j] = 0;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		add_tet(char board[104][104], int size, int row, int col, t_tet *tet)
{
	int i;
	int j;

	i = 0;
	while (i < 4 - tet->row)
	{
		j = 0;
		while (j < 4 - tet->col)
		{
			if (tet->shape[tet->row + i][tet->col + j] == '#')
			{
				size++;
				//if (col + j >= size || row + i >= size)
			 	//	return (0);
				board[row + i][col + j] = tet->letter;//tet->shape[tet->row + i][tet->col + j];
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		fits(char board[104][104], int size, t_tet *tet, int row, int col)
{
	int i;
	int j;

	i = 0;
	while (i < 4 - tet->row)
	{
		j = 0;
		while (j < 4 - tet->col)
		{
			if (tet->shape[tet->row + i][tet->col + j] == '#')
			{
				if (col + j >= size || row + i >= size
					|| board[row + i][col + j])
			 		return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		next_tet(char board[104][104], int size, t_list *tetriminos)
{
	int row;
	int col;

	if (!tetriminos) // MAKE SURE THIS MAKES SENSE HERE
		return (1);
	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			if (fits(board, size, tetriminos->content, row, col))
			{
				add_tet(board, size, row, col, tetriminos->content);
				if (next_tet(board, size, tetriminos->next))
					return (1);
				else
					delete_tet(board, size, row, col, tetriminos->content);
			}
			col++;
		}
		row++;
	}
	return (0);
}

int		solve(char board[104][104], int *size, t_list *tetriminos)
{
	while (!next_tet(board, *size, tetriminos))
	{
		(*size)++;
	}
	return (1);
}
