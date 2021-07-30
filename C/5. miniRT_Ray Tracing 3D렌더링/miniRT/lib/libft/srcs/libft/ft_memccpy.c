/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:36:15 by seobaek           #+#    #+#             */
/*   Updated: 2020/11/10 14:36:19 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*s;
	unsigned char		*d;

	s = (unsigned char*)src;
	d = (unsigned char*)dst;
	while (n-- > 0)
	{
		*d++ = *s++;
		if (*(s - 1) == (unsigned char)c)
			return ((void*)d);
	}
	return (NULL);
}
