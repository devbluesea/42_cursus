/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 15:45:12 by seobaek           #+#    #+#             */
/*   Updated: 2020/08/10 22:06:45 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_set(char c, char *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int				ft_atoi(char *str)
{
	int atoi;
	int sign;

	sign = 1;
	while (*str == '-' || *str == '+')
	{
		sign = (*str == '-') ? -sign : sign;
		str++;
	}
	atoi = 0;
	if (!is_set(*str, DIGIT))
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		atoi = atoi * 10 + (*str - '0');
		str++;
	}
	return (atoi * sign);
}
