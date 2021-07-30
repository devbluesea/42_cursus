/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 22:04:46 by seobaek           #+#    #+#             */
/*   Updated: 2020/04/16 21:21:41 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	unsigned int	i;
	size_t			len;

	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	ptr = (char *)ft_calloc(len + 1, sizeof(char));
	i = 0;
	if (ptr)
	{
		while (s[i])
		{
			ptr[i] = f(i, s[i]);
			i++;
		}
	}
	return (ptr);
}
