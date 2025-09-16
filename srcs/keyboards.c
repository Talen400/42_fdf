/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboards.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 21:35:03 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/16 12:06:53 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_keyhook(mlx_key_data_t k, void *param)
{
	t_fdf	*f;

	f = (t_fdf *)param;
	if (k.action != MLX_PRESS && k.action != MLX_REPEAT)
		return ;
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
	else if (k.key == MLX_KEY_R)
	{
		f->angle_x = 0;
		f->angle_y = 0;
		f->angle_z = 0;
	}
	ft_draw(f);
}

void	ft_scrollhook(double xd, double yd, void *param)
{
	(void ) yd;
	(void ) xd;
	(void ) param;
}
