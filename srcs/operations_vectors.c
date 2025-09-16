/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_vectors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:26:36 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/16 11:37:13 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_vec2	ft_iso(t_vec3 p)
{
	t_vec2	result;

	result.x = (int )((p.x - p.y) * cos(0.523599));
	result.y = (int )((p.x + p.y) * sin(0.523599) - p.z);
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
