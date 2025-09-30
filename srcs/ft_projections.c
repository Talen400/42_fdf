/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projections.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:54:04 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/30 18:22:43 by tlavared         ###   ########.fr       */
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

t_vec2	ft_polar(t_vec3 p)
{
	t_vec2	result;
	float	r;
	float	phi;
	float	theta;

	r = sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
	phi = atan2(p.y, p.x);
	theta = acos(p.z / r);
	result.x = r * phi * cos(theta);
	result.y = r * phi * sin(theta);
	return (result);
}

t_vec2	ft_cilindric(t_vec3 p, float focal_lenght)
{
	t_vec2	result;
	float	r;
	float	theta;
	float	scale;

	r = sqrt(p.x * p.x + p.y * p.y);
	theta = atan2(p.y, p.x);
	scale = 1.0 + (p.z / focal_lenght);
	result.x = r * cos(theta) * scale;
	result.y = r * sin(theta) * scale;
	return (result);
}
