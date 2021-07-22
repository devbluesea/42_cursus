/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 23:27:20 by seobaek           #+#    #+#             */
/*   Updated: 2020/04/18 16:00:23 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				index;
	unsigned char		*s_ptr;
	unsigned char		*d_ptr;
	unsigned char		flag;

	s_ptr = (void *)src;
	d_ptr = dst;
	index = 0;
	flag = 1;
	while (index < n && flag)
	{
		if (*s_ptr == c)
			flag = 0;
		*d_ptr = *s_ptr;
		d_ptr++;
		s_ptr++;
		index++;
	}
	if (!flag)
		return (dst + index);
	else
		return (NULL);
}
