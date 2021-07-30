/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:07:56 by seobaek           #+#    #+#             */
/*   Updated: 2021/01/13 21:07:57 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	if (n == 0)
		return (0);
	p1 = (unsigned char*)s1;
	p2 = (unsigned char*)s2;
	i = 0;
	while (p1[i] != '\0' && p2[i] != '\0' && i < n - 1
			&& p1[i] == p2[i])
		i++;
	return (p1[i] - p2[i]);
}
