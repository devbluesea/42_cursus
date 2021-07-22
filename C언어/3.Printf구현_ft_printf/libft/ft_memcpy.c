/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 22:28:59 by seobaek           #+#    #+#             */
/*   Updated: 2020/04/15 14:34:45 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*ptr;
	const unsigned char *str;

	ptr = (unsigned char*)dst;
	str = (unsigned char*)src;
	while (n > 0)
	{
		*ptr = *str;
		ptr++;
		str++;
		n--;
	}
	return (dst);
}
