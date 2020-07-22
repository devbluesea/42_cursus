/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 17:17:01 by seobaek           #+#    #+#             */
/*   Updated: 2020/04/18 18:06:06 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	i;
	int				i_len;

	if (!s)
		return ((char *)s);
	i_len = (int)len;
	ptr = (char *)ft_calloc(i_len + 1, sizeof(char));
	i = 0;
	if (ptr)
	{
		if ((unsigned int)ft_strlen(s) > start)
		{
			while (i_len-- > 0 && s[start])
			{
				ptr[i] = s[start];
				start++;
				i++;
			}
		}
		ptr[i] = '\0';
	}
	return (ptr);
}
