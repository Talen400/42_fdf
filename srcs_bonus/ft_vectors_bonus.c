/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:26:36 by tlavared          #+#    #+#             */
/*   Updated: 2025/10/01 00:52:58 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

static t_vec2	ft_choose_proj(t_fdf *f, t_vec3 point3d)
{
	t_vec2	point2d;

	point2d.x = 0;
	point2d.y = 0;
	if (f->projection == PROJ_ISO)
		point2d = ft_iso(point3d, ft_degree_to_radian(30));
	else if (f->projection == PROJ_ORTHO)
		point2d = ft_ortho(point3d);
	else if (f->projection == PROJ_PERSPECTIVE)
		point2d = ft_perspective(point3d, f->focal_lenght);
	else if (f->projection == PROJ_POLAR)
		point2d = ft_polar(point3d);
	else if (f->projection == PROJ_POLAR)
		point2d = ft_polar(point3d);
	else if (f->projection == PROJ_CILINDRIC)
		point2d = ft_cilindric(point3d, f->focal_lenght);
	return (point2d);
}

t_vec2	ft_get2d(t_fdf *f, int x, int y)
{
	t_vec3	point3d;
	t_vec2	point2d;

	point3d.x = (float )(x - f->center_x);
	point3d.y = (float )(y - f->center_y);
	point3d.z = ((float )f->map.altitudes[y][x] - (float ) f->center_z)
		* f->z_scale;
	ft_rotatex(&point3d, ft_degree_to_radian(f->angle_x));
	ft_rotatey(&point3d, ft_degree_to_radian(f->angle_y));
	ft_rotatez(&point3d, ft_degree_to_radian(f->angle_z));
	point2d = ft_choose_proj(f, point3d);
	point2d.x = (int)(point2d.x * f->scale + (float )f->offset_x);
	point2d.y = (int)(point2d.y * f->scale + (float )f->offset_y);
	point2d.color = f->map.colors[y][x];
	return (point2d);
}
