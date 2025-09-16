/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboards.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 21:35:03 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/16 07:53:22 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_keyhook(mlx_key_data_t k, void *param)
{

	t_fdf *f = (t_fdf *)param;

	if (k.action != MLX_PRESS && k.action != MLX_REPEAT)
		return;
	if (k.key == MLX_KEY_LEFT)
		f->angle_y -= 0.1f;
	else if (k.key == MLX_KEY_RIGHT)
		f->angle_y += 0.1f;
	else if (k.key == MLX_KEY_UP)
		f->angle_x -= 0.1f;
	else if (k.key == MLX_KEY_DOWN)
		f->angle_x += 0.1f;
	else if (k.key == MLX_KEY_Q)
		f->angle_z -= 0.1f;
	else if (k.key == MLX_KEY_E)
		f->angle_z += 0.1f;
	else if (k.key == MLX_KEY_R) // reset
	{
		f->angle_x = 0;
		f->angle_y = 0;
		f->angle_z = 0;
	}

	ft_draw(f); // redesenhar após input
}

void	ft_scrollhook(double xd, double yd, void *param)
{
	t_fdf	*f;
	double	delta;

	f = (t_fdf *)param;
	delta = yd * 0.1;
	if (f->mode == 0)
		f->a += delta;
	else if (f->mode == 1)
		f->b += delta;
	else if (f->mode == 2)
		f->c += delta;
	else if (f->mode == 3)
		f->d += delta;
	ft_draw(f);
	(void ) xd;
}
