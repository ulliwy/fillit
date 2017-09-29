#include "fillit.h"
#include <stdio.h>

int		get_size(t_list *begin_list)
{
	int		count;

	count = 0;
	while (begin_list)
	{
		count++;
		begin_list = begin_list->next;
	}
	return (count);
}

t_list	*create_list(int fd)
{
	char	buf[20];
	t_tet	*tet;
	t_list	*lst;
	t_list	*current;

	current = NULL;
	while (read(fd, buf, 20) == 20)
	{
		if ((tet = create_tet(buf)))
		{
			if (!current)
			{
				current = ft_lstnew(tet, sizeof(tet));
				lst = current;
			}
			else
			{
				current->next = ft_lstnew(tet, sizeof(tet));
				current = current->next;
			}
		}
		//else
		//	return (NULL);
	}
	return (lst);
}
