/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 12:47:47 by mvann             #+#    #+#             */
/*   Updated: 2017/10/02 16:59:08 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** created by: iprokofy, mvann
*/

#include "fillit.h"

int		delete_tet(t_board *brd, int row, int col, t_tet *tet)
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
				(brd->board)[row + i][col + j] = 0;
			j++;
		}
		i++;
	}
	return (1);
}

int		add_tet(t_board *brd, int row, int col, t_tet *tet)
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
				(brd->board)[row + i][col + j] = tet->letter;
			j++;
		}
		i++;
	}
	return (1);
}

int		fits(t_board *brd, t_tet *tet, int row, int col)
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
				if (col + j >= brd->size || row + i >= brd->size
					|| (brd->board)[row + i][col + j])
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		next_tet(t_board *brd, t_list *tetriminos)
{
	int row;
	int col;

	if (!tetriminos)
		return (1);
	row = 0;
	while (row < brd->size)
	{
		col = 0;
		while (col < brd->size)
		{
			if (fits(brd, tetriminos->content, row, col))
			{
				add_tet(brd, row, col, tetriminos->content);
				if (next_tet(brd, tetriminos->next))
					return (1);
				else
					delete_tet(brd, row, col, tetriminos->content);
			}
			col++;
		}
		row++;
	}
	return (0);
}

int		solve(t_board *brd, t_list *tetriminos)
{
	while (!next_tet(brd, tetriminos))
	{
		(brd->size)++;
	}
	return (1);
}
