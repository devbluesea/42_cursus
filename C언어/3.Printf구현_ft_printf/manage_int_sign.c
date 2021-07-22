/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_in_sign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:50:53 by seobaek           #+#    #+#             */
/*   Updated: 2020/08/10 18:52:00 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*prepare_sign(t_tag *tag, char *s)
{
	if (s[0] == '-')
	{
		tag->sign = '-';
		s++;
	}
	else if (tag->plus == ENABLED)
		tag->sign = '+';
	else if (tag->space == ENABLED)
		tag->sign = ' ';
	return (s);
}

char	*process_sign(t_tag *tag, char *box, int s_len)
{
	if (tag->sign == '\0')
		return (box);
	if ((tag->zero_fill == ENABLED && tag->prcs == DISABLED)
			|| tag->left_aligned == ENABLED)
		box[0] = tag->sign;
	else
		box[tag->width - s_len - 1] = tag->sign;
	return (box);
}
