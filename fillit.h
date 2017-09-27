#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
#include "libft.h"

//typedef struct			s_list
//{
//	void				*content;
//	size_t				content_size;
//	struct s_list		*next;
//}						t_list;

typedef struct			s_tet
{
	int					row;
	int					col;
	char				shape[4][4];
}						t_tet;

t_list	*create_list(int fd);
t_tet	*create_tet(char *str);
int		get_size(t_list *tetriminos);
int		get_size(t_list *begin_list);






#endif
