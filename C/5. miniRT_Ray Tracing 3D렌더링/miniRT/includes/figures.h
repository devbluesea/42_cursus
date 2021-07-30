/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:10:28 by seobaek           #+#    #+#             */
/*   Updated: 2020/11/10 14:10:34 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIGURES_H
# define FIGURES_H

# include "minirt.h"

typedef struct	s_sphere
{
	t_p3	c; // center
	double	r; // radius
	int		inside; // 카메라가 구 안쪽인지 바깥쪽인지
}				t_sphere;

typedef struct	s_plane
{
	t_p3	p; // point
}				t_plane;

typedef struct	s_square
{
	t_p3	c; // center
	double	side; // 한 변

}				t_square;

typedef struct	s_cylinder
{
	t_p3	c; // center
	t_p3	nv; // 법선벡터
	double	r; // radius
	double	h; // height
	double	dist1; // ray가 도달하는 한 점
	double	dist2; // 다른 점
}				t_cylinder;

typedef struct	s_triangle
{
	t_p3	p1;
	t_p3	p2;
	t_p3	p3;
}				t_triangle;

union			u_figures
{
	t_sphere	sp; // sphere
	t_plane		pl; // plane
	t_square	sq; // square
	t_cylinder	cy; // cylinder
	t_triangle	tr; // triangle
};

#endif
