/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:25:29 by iprokofy          #+#    #+#             */
/*   Updated: 2017/10/02 12:28:12 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int		count;
	int 	is_empty;

	count = 0;
	current = NULL;
	is_empty = 0;
	while (!is_empty)
	{
		if (read(fd, buf, 20) != 20)
			return (NULL);
		if ((tet = create_tet(buf, count)))
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
		if (!read(fd, buf, 1))
			is_empty = 1;
		count++;
	}
	return (lst);
}
