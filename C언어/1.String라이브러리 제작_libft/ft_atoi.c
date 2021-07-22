/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 15:45:12 by seobaek           #+#    #+#             */
/*   Updated: 2020/04/14 21:07:13 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int res;
	int negative;

	negative = 1;
	res = 0;
	while (*str && (*str == ' ' || *str == '\t' || *str == '\n' ||
					*str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = 10 * res + (*str - '0');
		str++;
	}
	return (negative * res);
}
