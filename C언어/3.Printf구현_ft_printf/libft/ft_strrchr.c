/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 14:29:07 by seobaek           #+#    #+#             */
/*   Updated: 2020/04/18 16:46:53 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;
	size_t	len;
	int		find;

	i = 0;
	j = 0;
	find = 0;
	len = ft_strlen(s) + 1;
	while (len--)
	{
		if (s[i] == (char)c)
		{
			j = i;
			find = 1;
		}
		i++;
	}
	if (j == 0 && !find)
		return (NULL);
	else
		return ((char *)(s + j));
}
