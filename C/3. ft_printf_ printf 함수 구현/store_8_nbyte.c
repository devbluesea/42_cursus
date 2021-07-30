/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_8_nbyte.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 19:11:36 by seobaek           #+#    #+#             */
/*   Updated: 2020/08/10 20:11:52 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	store_nbyte_hh(va_list ap, t_tag *tag)
{
	signed char *ptr;

	ptr = (signed char *)va_arg(ap, int *);
	*ptr = tag->nbyte;
}

static void	store_nbyte_h(va_list ap, t_tag *tag)
{
	short int *ptr;

	ptr = (short int *)va_arg(ap, int *);
	*ptr = tag->nbyte;
}

static void	store_nbyte_l(va_list ap, t_tag *tag)
{
	long *ptr;

	ptr = (long *)va_arg(ap, long *);
	*ptr = tag->nbyte;
}

static void	store_nbyte_ll(va_list ap, t_tag *tag)
{
	long long *ptr;

	ptr = (long long *)va_arg(ap, long long *);
	*ptr = tag->nbyte;
}

int			store_nbyte(va_list ap, t_tag *tag)
{
	int *ptr;

	if (tag->len_mod == DISABLED)
	{
		ptr = (int *)va_arg(ap, int *);
		*ptr = tag->nbyte;
	}
	else if (tag->len_mod == 'h' + 'h')
		store_nbyte_hh(ap, tag);
	else if (tag->len_mod == 'h')
		store_nbyte_h(ap, tag);
	else if (tag->len_mod == 'l')
		store_nbyte_l(ap, tag);
	else if (tag->len_mod == 'l' + 'l')
		store_nbyte_ll(ap, tag);
	else
		return (ERROR);
	return (0);
}
