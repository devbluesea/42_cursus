/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:06:32 by seobaek           #+#    #+#             */
/*   Updated: 2021/01/13 21:06:33 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	tmp_c;

	if (b == 0)
		return (0);
	ptr = (unsigned char*)b;
	tmp_c = (unsigned char)c;
	while (len--)
		*ptr++ = tmp_c;
	return (b);
}
