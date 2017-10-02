/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 13:52:51 by iprokofy          #+#    #+#             */
/*   Updated: 2017/10/02 15:05:56 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** created by: iprokofy, mvann
*/

#include "fillit.h"

int		calc_conn(char *str, int pos)
{
	int		con;

	con = 0;
	if (pos % 5 > 0 && str[pos - 1] == '#')
		con++;
	if (pos % 5 < 4 && str[pos + 1] == '#')
		con++;
	if (pos / 5 > 0 && str[pos - 5] == '#')
		con++;
	if (pos / 5 < 4 && str[pos + 5] == '#')
		con++;
	return (con);
}

t_tet	*get_tet(char *str, int top, int left, int count)
{
	t_tet	*tet;
	int		i;
	int		j;
	char	*alpha;

	alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	tet = (t_tet *)malloc(sizeof(t_tet));
	tet->row = top;
	tet->col = left;
	tet->letter = alpha[count];
	i = 0;
	j = 0;
	while (i < 20)
	{
		if (!(i != 0 && i % 5 == 4))
			tet->shape[i / 5][i % 5] = str[i];
		i++;
	}
	return (tet);
}

void	init_p(t_piece *p)
{
	p->num = 0;
	p->con = 0;
	p->left = 4;
	p->top = 4;
}

void	set_p(t_piece *p, char *str, int i, int j)
{
	if (i % 5 < p->left)
		p->left = i % 5;
	if (j < p->top)
		p->top = j;
	p->con += calc_conn(str, i);
	p->num++;
}

t_tet	*create_tet(char *str, int count)
{
	int		i;
	int		j;
	t_piece	p;

	init_p(&p);
	i = 0;
	j = 0;
	while (i < 20)
	{
		if (i % 5 == 4)
		{
			if (str[i] != '\n')
				return (NULL);
			j++;
		}
		else if (!(str[i] == '#' || (str[i] == '.')))
			return (NULL);
		else if (str[i] == '#')
			set_p(&p, str, i, j);
		i++;
	}
	if (p.num == 4 && (p.con == 6 || p.con == 8))
		return (get_tet(str, p.top, p.left, count));
	return (NULL);
}
