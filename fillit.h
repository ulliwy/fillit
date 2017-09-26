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
	char				shape[4][4];
}						t_tet;

t_list	generate_list(int fd);
t_tet	*create_tet(char *str);
int		get_size(t_list *tetriminos);






#endif
