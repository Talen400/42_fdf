/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calibrate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 23:50:46 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/27 23:51:09 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	ft_calculate_min_max(t_fdf *f)
{
	int	x;
	int	y;

	f->map.min_alt = f->map.altitudes[0][0];
	f->map.max_alt = f->map.altitudes[0][0];
	y = 0;
	while (y < f->map.height)
	{
		x = 0;
		while (x < f->map.width)
		{
			if (f->map.altitudes[y][x] < f->map.min_alt)
				f->map.min_alt = f->map.altitudes[y][x];
			if (f->map.altitudes[y][x] > f->map.max_alt)
				f->map.max_alt = f->map.altitudes[y][x];
			x++;
		}
		y++;
	}
}

void	ft_auto_calibrate(t_fdf *f)
{
	float	margin;
	int		max_dimension;
	int		z_range;

	f->center_x = (f->map.width - 1) / 2.0f;
	f->center_y = (f->map.height - 1) / 2.0f;
	f->center_z = (f->map.max_alt + f->map.min_alt) / 2.0f;
	ft_calculate_min_max(f);
	max_dimension = fmax(f->map.width, f->map.height);
	margin = MARGIN;
	z_range = f->map.max_alt - f->map.min_alt;
	f->scale = fmaxf(
			(WIDTH * (1 - margin) / (max_dimension * 1.5 + z_range * 0.5f)),
			(HEIGHT * (1 - margin) / (max_dimension * 1.5f + z_range * 0.5f)));
	if (f->scale < 2.0f)
		f->scale = 2.0f;
	ft_printf("Auto-calibrated: scale=%f\n", f->scale);
}
