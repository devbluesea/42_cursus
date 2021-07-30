/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:07:26 by seobaek           #+#    #+#             */
/*   Updated: 2021/01/13 21:07:27 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	char	*cpy_ret;

	if (!s1 && !s2)
		return (0);
	ret = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ret)
		return (0);
	cpy_ret = ret;
	if (s1)
		while (*s1 != '\0')
			*cpy_ret++ = *s1++;
	if (s2)
		while (*s2 != '\0')
			*cpy_ret++ = *s2++;
	*cpy_ret = '\0';
	return (ret);
}
