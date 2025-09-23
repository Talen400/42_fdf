/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 21:35:03 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/23 19:44:43 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	ft_keyhook5(mlx_key_data_t *k, t_fdf *f)
{
	if (k->key == MLX_KEY_5)
	{
		f->angle_x = -M_PI / 6;
		f->angle_y = M_PI / 4;
		f->angle_z = 0;
	}
}

static void	ft_keyhook4(mlx_key_data_t *k, t_fdf *f)
{
	if (k->key == MLX_KEY_2)
	{
		f->angle_x = -M_PI / 2;
		f->angle_y = 0.0f;
		f->angle_z = 0.0f;
	}
	else if (k->key == MLX_KEY_2)
	{
		f->angle_x = -M_PI / 2; 		
		f->angle_y = 0.0f;
		f->angle_z = 0.0f;
	}
	else if (k->key == MLX_KEY_3)	
	{
		f->angle_x = 0.0f;
		f->angle_y = M_PI / 2;		
		f->angle_z = 0.0f;
	}
	else if (k->key == MLX_KEY_4)	
	{
		f->angle_x = -M_PI / 4;
		f->angle_y = 0.0f;
		f->angle_z = M_PI / 4;
	}
	else
		ft_keyhook5(k, f);
}

static void	ft_keyhook3(mlx_key_data_t *k, t_fdf *f)
{
	if (k->key == MLX_KEY_W)
		f->offset_y += MOVE;
	else if (k->key == MLX_KEY_S)
		f->offset_y -= MOVE;
	else if (k->key == MLX_KEY_D)
		f->offset_x -= MOVE;
	else if (k->key == MLX_KEY_A)
		f->offset_x += MOVE;
	else if (k->key == MLX_KEY_J)
		f->scale += ZOOM;
	else if (k->key == MLX_KEY_K)
		f->scale -= ZOOM;
	else if (k->key == MLX_KEY_1)
	{
		f->angle_x = 0.0f;
		f->angle_y = 0.0f;
		f->angle_z = 0.0f;
	}
	else
		ft_keyhook4(k, f);
}

static void	ft_keyhook2(mlx_key_data_t *k, t_fdf *f)
{
	if (k->key == MLX_KEY_LEFT)
		f->angle_y -= 0.1f;
	else if (k->key == MLX_KEY_RIGHT)
		f->angle_y += 0.1f;
	else if (k->key == MLX_KEY_UP)
		f->angle_x -= 0.1f;
	else if (k->key == MLX_KEY_DOWN)
		f->angle_x += 0.1f;
	else if (k->key == MLX_KEY_Q)
		f->angle_z -= 0.1f;
	else if (k->key == MLX_KEY_E)
		f->angle_z += 0.1f;
	else if (k->key == MLX_KEY_R)
	{
		f->angle_x = 0;
		f->angle_y = 0;
		f->angle_z = 0;
	}
	else
		ft_keyhook3(k, f);
}

void	ft_keyhook(mlx_key_data_t k, void *param)
{
	t_fdf	*f;

	f = (t_fdf *)param;
	if (k.action != MLX_PRESS && k.action != MLX_REPEAT)
		return ;
	else if (k.key == MLX_KEY_X)
		mlx_close_window(f->mlx);
	else
		ft_keyhook2(&k, f);
	ft_draw(f);
}

