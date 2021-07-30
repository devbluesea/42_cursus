/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:38:16 by seobaek           #+#    #+#             */
/*   Updated: 2020/11/10 14:38:18 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char *dup;

	if (!(dup = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	ft_strcpy(dup, s1);
	return (dup);
}
