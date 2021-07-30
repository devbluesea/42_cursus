/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:38:44 by seobaek           #+#    #+#             */
/*   Updated: 2020/11/10 14:38:45 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] && dstsize > 1)
	{
		dst[i] = src[i];
		dstsize--;
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}
