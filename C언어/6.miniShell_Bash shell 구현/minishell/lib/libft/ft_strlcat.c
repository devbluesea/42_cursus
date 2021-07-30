/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:07:31 by seobaek           #+#    #+#             */
/*   Updated: 2021/01/13 21:23:05 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	x;

	i = 0;
	j = 0;
	x = 0;
	while (dst[i] != 0)
		i++;
	while (src && src[j] != 0)
		j++;
	if (i < dstsize)
		j = i + j;
	else
		j = j + dstsize;
	while (src && src[x] != '\0' && i + 1 < dstsize)
		dst[i++] = src[x++];
	dst[i] = '\0';
	return (j);
}
