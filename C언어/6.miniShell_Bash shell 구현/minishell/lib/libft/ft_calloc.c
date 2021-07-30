/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:05:26 by seobaek           #+#    #+#             */
/*   Updated: 2021/01/13 21:05:27 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;

	if (!(ptr = (unsigned char*)malloc(size * count)))
		return (0);
	ft_memset(ptr, 0, size * count);
	return ((void*)ptr);
}
