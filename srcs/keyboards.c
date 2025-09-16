/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboards.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 21:35:03 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/15 23:58:04 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_keyhook(mlx_key_data_t k, void *param)
{
	t_fdf	*f;

	f = (t_fdf *)param;
	if (k.action == MLX_PRESS)
	{
		if (k.key == MLX_KEY_ESCAPE)
			mlx_close_window(f->mlx);
		else if (k.key >= MLX_KEY_1 && k.key <= MLX_KEY_4)
        {
            f->mode = k.key - MLX_KEY_1;
            ft_draw(f);
		}
		else if (k.key == MLX_KEY_R)
		{
			f->a = 1.0;
			f->b = 1.0;
			f->c = 0.0;
			f->d = 0.0;
			ft_draw(f);
		}
	}
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
