/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 15:21:54 by iprokofy          #+#    #+#             */
/*   Updated: 2017/09/29 14:19:28 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		list->content = content;
	}
	list->next = NULL;
	return (list);
}
