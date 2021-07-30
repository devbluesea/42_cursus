/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:06:13 by seobaek           #+#    #+#             */
/*   Updated: 2021/01/13 21:22:38 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ps;
	unsigned int	i;

	ps = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (ps[i] == (unsigned char)c)
			return (ps + i);
		i++;
	}
	return (0);
}
