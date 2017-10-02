#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

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
	char				letter;
	char				shape[4][4];
}						t_tet;

t_list	*ft_lstnew(void *content);
int		get_size(t_list *begin_list);
void	ft_lstdel(t_list **alst, void (*del)(t_list *));
void	ft_lstdelone(t_list *alst);

t_tet	*create_tet(char *str, int count);
t_list	*create_list(int fd);

int		solve(char board[104][104], int *size, t_list *tetriminos);
void 	print_board(char board[104][104], int size);

void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif
