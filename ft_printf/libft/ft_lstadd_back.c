/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 18:32:01 by seobaek           #+#    #+#             */
/*   Updated: 2020/04/16 21:20:39 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*l_ptr;

	l_ptr = *lst;
	if (l_ptr && new && lst)
	{
		while (l_ptr->next)
			l_ptr = l_ptr->next;
		l_ptr->next = new;
	}
	else if (lst && new && !l_ptr)
		*lst = new;
}
