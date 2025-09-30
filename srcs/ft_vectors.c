/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:26:36 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/30 00:23:51 by tlavared         ###   ########.fr       */
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

void	ft_rotatex(t_vec3 *p, float angle)
{
	float	y;
	float	z;

	y = p->y;
	z = p->z;
	p->y = y * cosf(angle) - z * sinf(angle);
	p->z = y * sinf(angle) + z * cosf(angle);
}

void	ft_rotatey(t_vec3 *p, float angle)
{
	float	x;
	float	z;

	x = p->x;
	z = p->z;
	p->x = x * cosf(angle) + z * sinf(angle);
	p->z = -x * sinf(angle) + z * cosf(angle);
}

void	ft_rotatez(t_vec3 *p, float angle)
{
	float	x;
	float	y;

	x = p->x;
	y = p->y;
	p->x = x * cosf(angle) - y * sinf(angle);
	p->y = x * sinf(angle) + y * cosf(angle);
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
	point2d = ft_iso(point3d, ft_degree_to_radian(30));
	point2d.x = (int)(point2d.x * f->scale + (float )f->offset_x);
	point2d.y = (int)(point2d.y * f->scale + (float )f->offset_y);
	point2d.color = f->map.colors[y][x];
	return (point2d);
}
