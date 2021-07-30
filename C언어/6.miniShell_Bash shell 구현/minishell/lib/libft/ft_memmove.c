/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:06:27 by seobaek           #+#    #+#             */
/*   Updated: 2021/01/13 21:22:37 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*pd;
	unsigned char	*ps;
	unsigned int	i;

	pd = (unsigned char*)dst;
	ps = (unsigned char*)src;
	i = 0;
	if (ps < pd)
		while (len-- > 0)
			pd[len] = ps[len];
	else
		while (i < len)
		{
			pd[i] = ps[i];
			i++;
		}
	return (dst);
}
