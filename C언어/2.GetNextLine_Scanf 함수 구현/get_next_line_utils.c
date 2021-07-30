/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 11:32:34 by seobaek           #+#    #+#             */
/*   Updated: 2020/07/15 17:10:37 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	size_t i;

	if (s == NULL)
		return (0);
	i = 0;
	if (c == 0)
		return ((char *)s + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}

size_t	ft_strlen(char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dst, char *src, size_t n)
{
	size_t i;

	if (dst == NULL && src == NULL)
		return (dst);
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

char	*ft_strndup(char *s1, size_t size)
{
	char	*dup;

	dup = (char *)malloc(sizeof(char) * (size + 1));
	if (dup == NULL)
		return (NULL);
	ft_strcpy(dup, s1, size);
	dup[size] = 0;
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_s;
	size_t	len1;
	size_t	len2;

	if (s1 == NULL && s2 == NULL)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_s = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (new_s == NULL)
		return (NULL);
	ft_strcpy(new_s, s1, len1);
	ft_strcpy(new_s + len1, s2, len2);
	new_s[len1 + len2] = 0;
	return (new_s);
}
