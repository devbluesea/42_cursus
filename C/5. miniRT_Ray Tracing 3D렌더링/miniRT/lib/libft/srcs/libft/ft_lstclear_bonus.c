/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:35:31 by seobaek           #+#    #+#             */
/*   Updated: 2020/11/10 14:35:33 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_link;
	t_list	*link;

	link = *lst;
	while (link)
	{
		next_link = link->next;
		(*del)(link->content);
		free(link);
		link = next_link;
	}
	*lst = NULL;
}
