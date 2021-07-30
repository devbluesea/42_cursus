/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:06:07 by seobaek           #+#    #+#             */
/*   Updated: 2021/01/13 21:06:08 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	stop_c;
	unsigned int	i;
	char			*str_dst;
	char			*str_src;

	stop_c = (unsigned char)c;
	str_dst = (char*)dst;
	str_src = (char*)src;
	i = 0;
	while (i < n)
	{
		*(str_dst + i) = *(str_src + i);
		if ((unsigned char)*(str_src + i) == stop_c)
			return (dst + i + 1);
		i++;
	}
	return (0);
}
