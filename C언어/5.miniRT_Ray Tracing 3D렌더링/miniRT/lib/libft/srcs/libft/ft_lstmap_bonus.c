/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:35:56 by seobaek           #+#    #+#             */
/*   Updated: 2020/11/10 14:35:57 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin_list;
	t_list	*list;

	if (!lst)
		return (NULL);
	if (!(list = ft_lstnew((*f)(lst->content))))
		return (NULL);
	begin_list = list;
	while (lst->next)
	{
		lst = lst->next;
		if (!(list->next = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&begin_list, del);
			return (NULL);
		}
		list = list->next;
	}
	return (begin_list);
}
