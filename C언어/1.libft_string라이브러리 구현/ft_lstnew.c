/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 22:13:07 by seobaek           #+#    #+#             */
/*   Updated: 2020/04/16 19:02:55 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*l_ptr;

	l_ptr = (t_list *)ft_calloc(1, sizeof(t_list));
	if (l_ptr)
	{
		l_ptr->content = content;
		l_ptr->next = NULL;
	}
	return (l_ptr);
}
