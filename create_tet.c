#include "fillit.h"
#include <stdio.h>

int		calc_conn(char *str, int pos)
{
	int		con;

	con = 0;
	if (str[pos - 1] == '#')
		con++;
	if (str[pos + 1] == '#')
		con++;
	if (str[pos - 5] == '#')
		con++;
	if (str[pos + 5] == '#')
		con++;
	return (con);
}

t_tet	*create_tet(char *str)
{
	int		i;
	int		j;
	int		left;
	int		top;
	//t_tet	*tet;
	int		con;

	i = 0;
	con = 0;
	//j = 0;
	while (i < 20)
	{
		printf("%c", str[i]);
		i++;
	}
	while (i < 20)
	{
		if (i != 0 && i % 4 == 0)
		{
			if (str[i] != '\n')
			{
				//printf("here\n");
				return (NULL);
			}
			j = 0;
		}
		else if (!(str[i] == '#' || (str[i] == '.')))
		{
			//printf("--%d <%c>\n", i, str[i]);
			return (NULL);
		}
		else if (*str == '#')
		{
			if (i % 5 < top)
				top = i % 5;
			if (j < left)
				left = j;
			con += calc_conn(str, i);
		}
		i++;
	}
	printf("\n con %d\n", con);
	if (con != 6)
		return (NULL);
	//tet = get_tet(str, top, left);
	return (NULL);
}