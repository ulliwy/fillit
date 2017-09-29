/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:25:29 by iprokofy          #+#    #+#             */
/*   Updated: 2017/09/29 14:25:30 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

void	ft_lstdelone(t_list *alst)
{
	free(alst->content);
	free(alst);
	alst = NULL;
}

void	ft_lstdel(t_list **alst, void (*del)(t_list *))
{
	t_list	*temp;
	t_list	*current;

	if (!*alst)
		return ;
	current = *alst;
	while (current)
	{
		temp = current;
		current = current->next;
		del(temp);
	}
	*alst = NULL;
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
				current = ft_lstnew(tet);
				lst = current;
			}
			else
			{
				current->next = ft_lstnew(tet);
				current = current->next;
			}
		}
		else
			return (NULL);
		read(fd, buf, 1);
	}
	return (lst);
}
