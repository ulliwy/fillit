#include "fillit.h"
#include <stdio.h>

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

t_tet	*get_tet(char *str, int top, int left)
{
	t_tet	*tet;
	int		i;
	int		j;

	tet = (t_tet *)malloc(sizeof(t_tet));
	tet->row = top;
	tet->col = left;
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

t_tet	*create_tet(char *str)
{
	int		i;
	int		j;
	int		left;
	int		top;
	int 	num;
	int		con;

	i = 0;
	j = 0;
	num = 0;
	con = 0;
	top = 4;
	left = 4;
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
		{
			if (i % 5 < left)
				left = i % 5;
			if (j < top)
				top = j;
			con += calc_conn(str, i);
			num++;
		}
		i++;
	}
	//printf("con %d\n", con);
	//printf("num %d\n", num);
	//printf("left: %d, top: %d\n\n", left, top);
	if (num == 4 && (con == 6 || con == 8))
	{
		//printf("here\n");
		return (get_tet(str, top, left));
	}
	return (NULL);
}
