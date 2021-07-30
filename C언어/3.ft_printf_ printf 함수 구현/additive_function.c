/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additive_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:46:35 by seobaek           #+#    #+#             */
/*   Updated: 2020/08/10 20:59:18 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_set(char c, char *set)
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

int		get_atouni_width(wchar_t wc)
{
	if (wc < 0x80)
		return (1);
	else if (wc < 0x800)
		return (2);
	else if (wc < 0x10000)
		return (3);
	else
		return (4);
}
