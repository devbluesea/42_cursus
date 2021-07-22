/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 20:16:08 by seobaek           #+#    #+#             */
/*   Updated: 2020/04/18 19:33:59 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_check_digit(int n)
{
	size_t			i;
	unsigned int	tmp_n;

	i = 0;
	if (n == 0)
		i = 1;
	if (n < 0)
	{
		tmp_n = -n;
		i++;
	}
	else
		tmp_n = n;
	while (tmp_n)
	{
		i++;
		tmp_n /= 10;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char			*ptr;
	char			*decimal;
	size_t			len;
	unsigned int	temp;
	unsigned int	i;

	decimal = "0123456789";
	len = ft_check_digit(n);
	ptr = (char *)ft_calloc(len + 1, sizeof(char));
	i = 0;
	if (ptr)
	{
		temp = n < 0 ? -n : n;
		ptr[0] = '-';
		if (n < 0)
			i = 1;
		ptr[len] = '\0';
		while (len-- > i)
		{
			ptr[len] = decimal[temp % 10];
			temp /= 10;
		}
	}
	return (ptr);
}
