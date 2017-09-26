#ifndef FILLIT_H
# define FILLIT_H

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

typedef struct			s_tet
{
	int					row;
	int					col;
	char				**shape;
}						t_tet;

t_list	create_list(int fd);
t_tet	create_tet(int fd);






#endif