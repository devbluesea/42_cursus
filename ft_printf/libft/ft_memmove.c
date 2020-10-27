/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 22:35:35 by seobaek           #+#    #+#             */
/*   Updated: 2020/04/15 14:37:20 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				index;
	unsigned char		*ptr;
	const unsigned char	*str;

	index = 0;
	ptr = (unsigned char *)dst;
	str = (unsigned char *)src;
	if (ptr > str)
		while (++index <= len)
			ptr[len - index] = str[len - index];
	else
		while (len-- > 0)
			*(ptr++) = *(str++);
	return (dst);
}
