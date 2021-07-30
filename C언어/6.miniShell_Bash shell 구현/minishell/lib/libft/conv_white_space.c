/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_white_space.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:05:07 by seobaek           #+#    #+#             */
/*   Updated: 2021/01/13 21:22:43 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	conv_white_space(char c)
{
	if (c == ' ')
		return (' ');
	else if (c == 't')
		return ('\t');
	else if (c == 'n')
		return ('\n');
	else if (c == 'r')
		return ('\r');
	else if (c == 'v')
		return ('\v');
	return (c);
}
