/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:07:50 by seobaek           #+#    #+#             */
/*   Updated: 2021/01/13 21:07:50 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*ret;

	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	if (!(ret = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	ret[len] = '\0';
	i = 0;
	while (i < len)
	{
		ret[i] = f(i, *s++);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
