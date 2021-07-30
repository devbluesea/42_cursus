/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 21:21:14 by seobaek           #+#    #+#             */
/*   Updated: 2020/04/18 19:06:26 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int		len_s1;
	unsigned int		len_s2;
	unsigned int		i;
	char				*new;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(new = malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (NULL);
	i = 0;
	while (i < (len_s1 + len_s2))
	{
		if (i < len_s1)
			new[i] = s1[i];
		if (i >= len_s1 && i < (len_s1 + len_s2))
			new[i] = s2[i - len_s1];
		i++;
	}
	new[i] = '\0';
	return (new);
}
