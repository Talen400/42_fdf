/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:26:36 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/18 23:48:54 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_vec2	ft_iso(t_vec3 p)
{
	t_vec2	result;

	result.x = (int )((p.x - p.y) * cosf(0.523599));
	result.y = (int )((p.x + p.y) * sinf(0.523599) - p.z);
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

	point3d.x = x - f->center_x;
	point3d.y = y - f->center_y;
	point3d.z = (f->map.altitudes[y][x] - f->center_z);
	ft_rotatex(&point3d, f->angle_x);
	ft_rotatey(&point3d, f->angle_y);
	ft_rotatez(&point3d, f->angle_z);
	point2d = ft_iso(point3d);
	point2d.x = point2d.x * f->scale + f->offset_x;
	point2d.y = point2d.y * f->scale + f->offset_y;
	return (point2d);
}
