/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:39:48 by seobaek           #+#    #+#             */
/*   Updated: 2020/11/10 14:39:51 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_charset(const char *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && is_charset(set, s1[i]))
		i++;
	len = ft_strlen(s1);
	j = 0;
	while (is_charset(set, s1[len - 1 - j]))
		j++;
	len = ((i == len) ? 0 : len - i - j);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	j = 0;
	while (len-- > 0)
		str[j++] = s1[i++];
	str[j] = '\0';
	return (str);
}
