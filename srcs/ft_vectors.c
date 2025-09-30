/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:26:36 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/30 03:36:50 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_vec2	ft_iso(t_vec3 p, float angle)
{
	t_vec2	result;

	result.x = (p.x - p.y) * cosf(angle);
	result.y = (p.x + p.y) * sinf(angle) - p.z;
	return (result);
}

t_vec2	ft_ortho(t_vec3 p)
{
	t_vec2	result;

	result.x = p.x;
	result.y = p.y - p.z;
	return (result);
}

t_vec2	ft_perspective(t_vec3 p, float focal_lenght)
{
	t_vec2	result;
	float	z;

	z = p.z + focal_lenght;
	if (z < 1.0f)
		z = 1.0f;
	result.x = (p.x * focal_lenght) / z;
	result.y = (p.y * focal_lenght) / z;
	return (result);
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
	if (f->projection == PROJ_ISO)
		point2d = ft_iso(point3d, ft_degree_to_radian(30));
	else if (f->projection == PROJ_ORTHO)
		point2d = ft_ortho(point3d);
	else if (f->projection == PROJ_PERSPECTIVE)
		point2d = ft_perspective(point3d, f->focal_lenght);
	point2d.x = (int)(point2d.x * f->scale + (float )f->offset_x);
	point2d.y = (int)(point2d.y * f->scale + (float )f->offset_y);
	point2d.color = f->map.colors[y][x];
	return (point2d);
}
