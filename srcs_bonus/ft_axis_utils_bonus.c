/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_axis_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 02:34:47 by tlavared          #+#    #+#             */
/*   Updated: 2025/10/01 00:50:36 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

t_vec3	ft_rotate_axis_vector(t_fdf *f, t_vec3 axis)
{
	ft_rotatex(&axis, ft_degree_to_radian(f->angle_x));
	ft_rotatey(&axis, ft_degree_to_radian(f->angle_y));
	ft_rotatez(&axis, ft_degree_to_radian(f->angle_z));
	return (axis);
}

void	ft_init_axis_vectors(t_vec3 *axis_x, t_vec3 *axis_y, t_vec3 *axis_z)
{
	axis_x->x = 1;
	axis_x->y = 0;
	axis_x->z = 0;
	axis_y->x = 0;
	axis_y->y = 1;
	axis_y->z = 0;
	axis_z->x = 0;
	axis_z->y = 0;
	axis_z->z = 1;
}

void	ft_setup_origin(t_vec2 *origin)
{
	int	margin;

	margin = AXIS_POS;
	origin->x = WIDTH - margin;
	origin->y = HEIGHT - margin;
}
