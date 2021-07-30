/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_adjust.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 21:09:31 by seobaek           #+#    #+#             */
/*   Updated: 2020/11/10 23:14:57 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	cam_origin_adjust(t_minilibx mlx)
{
	t_camera	*temp_mlx;

	temp_mlx = mlx.cam;
	while (mlx.cam)
	{
		mlx.cam->o.x = -1 * mlx.cam->o.x;
		mlx.cam->nv.y = -1 * mlx.cam->nv.y;
		mlx.cam = mlx.cam->next;
	}
	mlx.cam = temp_mlx;
}

static void	cylinder_nv_adjust(t_figures *lst)
{
	t_figures	*temp_lst;

	temp_lst = lst;
	while (lst)
	{
		if (lst->flag != SQ)
			lst->fig.cy.nv.x = -1 * lst->fig.cy.nv.x;
		lst = lst->next;
	}
	lst = temp_lst;
}

static void	light_origin_adjust(t_scene *data)
{
	t_light		*temp_light;

	temp_light = data->l;
	while (data->l)
	{
		data->l->o.x = -1 * data->l->o.x;
		data->l = data->l->next;
	}
	data->l = temp_light;
}

void		cam_adjust(t_minilibx mlx, t_figures *lst, t_scene *data)
{
	cam_origin_adjust(mlx);
	cylinder_nv_adjust(lst);
	light_origin_adjust(data);
}
