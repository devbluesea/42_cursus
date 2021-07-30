/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:07:05 by seobaek           #+#    #+#             */
/*   Updated: 2021/01/13 21:07:05 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return
** not found c  : NULL
** if c is '\0' : '\0'
*/

char	*ft_strchr(const char *s, int c)
{
	char	*ret;

	ret = (char*)s;
	while (*ret != c)
	{
		if (*ret == '\0')
			return (0);
		ret++;
	}
	return (ret);
}
