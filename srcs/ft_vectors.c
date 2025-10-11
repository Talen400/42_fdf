/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:26:36 by tlavared          #+#    #+#             */
/*   Updated: 2025/10/11 00:55:39 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_vec2	ft_iso(t_vec3 p)
{
	t_vec2	result;

	result.x = (p.x - p.y) * cosf(0.523599);
	result.y = (p.x + p.y) * sinf(0.523599) - p.z;
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
	point2d = ft_iso(point3d);
	point2d.x = (int)(point2d.x * f->scale + (float )f->offset_x);
	point2d.y = (int)(point2d.y * f->scale + (float )f->offset_y);
	point2d.color = (uint32_t) f->map.colors[y][x];
	return (point2d);
}
