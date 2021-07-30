/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 18:39:00 by seobaek           #+#    #+#             */
/*   Updated: 2020/04/16 19:01:28 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*l_ptr;

	if (lst)
	{
		while (*lst)
		{
			l_ptr = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = l_ptr;
		}
	}
}
