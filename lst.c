/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:25:29 by iprokofy          #+#    #+#             */
/*   Updated: 2017/10/02 14:55:08 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** created by: iprokofy, mvann
*/

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

void	ft_lstdel(t_list **alst)
{
	t_list	*temp;

	if (!*alst)
		return ;
	while (*alst)
	{
		temp = *alst;
		*alst = (*alst)->next;
		free((*alst)->content);
		free((*alst));
		(*alst) = NULL;
	}
}

t_list	*ft_lstback(t_list *current, t_list **lst, t_tet *tet)
{
	if (!current)
	{
		current = ft_lstnew(tet);
		*lst = current;
	}
	else
	{
		current->next = ft_lstnew(tet);
		current = current->next;
	}
	return (current);
}

t_list	*create_list(int fd, char *buf)
{
	t_tet	*tet;
	t_list	*lst;
	t_list	*current;
	int		count;
	int		is_empty;

	count = 0;
	current = NULL;
	is_empty = 0;
	while (!is_empty)
	{
		if (read(fd, buf, 20) != 20)
			return (NULL);
		if ((tet = create_tet(buf, count)))
			current = ft_lstback(current, &lst, tet);
		else
			return (NULL);
		if (!read(fd, buf, 1))
			is_empty = 1;
		count++;
	}
	return (lst);
}
