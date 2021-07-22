/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 23:42:04 by seobaek           #+#    #+#             */
/*   Updated: 2020/04/18 16:47:23 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned int	flag;
	size_t			i;
	size_t			j;

	ptr = (void *)s;
	flag = 1;
	i = 0;
	while (i < n && flag)
	{
		if (*ptr == (unsigned char)c)
		{
			j = i;
			flag = 0;
		}
		ptr++;
		i++;
	}
	if (!flag)
		return ((void *)s + j);
	else
		return (NULL);
}
