/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:44:46 by seobaek           #+#    #+#             */
/*   Updated: 2020/11/10 16:28:29 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		define_color(double r, double g, double b, double color[3])
{
	color[0] = r;
	color[1] = g;
	color[2] = b;
}

int				rainbow(t_inter *inter)
{
	double	color[3];
	double	w;

	w = 540 - (inter->normal.y * 160);
	if (w >= 380 && w < 440)
		define_color(-(w - 440.) / (440. - 380.), 0.0, 1.0, color);
	else if (w >= 440 && w < 490)
		define_color(0.0, (w - 440.) / (490. - 440.), 1.0, color);
	else if (w >= 490 && w < 510)
		define_color(0.0, 1.0, -(w - 510.) / (510. - 490.), color);
	else if (w >= 510 && w < 540)
		define_color((w - 510.) / (540. - 510.), 1.0, 0.0, color);
	else if (w >= 540 && w < 645)
		define_color(1.0, -(w - 645.) / (645. - 540.), 0.0, color);
	else if (w >= 645 && w <= 700)
		define_color(1.0, 0.0, 0.0, color);
	else
		define_color(0.0, 0.0, 0.0, color);
	color[0] *= 255;
	color[1] *= 255;
	color[2] *= 255;
	return (((int)color[0] << 16) | ((int)color[1] << 8) | (int)color[2]);
}
