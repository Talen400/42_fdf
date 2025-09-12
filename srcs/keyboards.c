/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboards.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 21:35:03 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/12 17:07:00 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_keyhook(mlx_key_data_t k, void *param)
{
	t_sine	*s;

	s = (t_sine *)param;
	if (k.action == MLX_PRESS)
	{
		if (k.key == MLX_KEY_ESCAPE)
			mlx_close_window(s->mlx);
		else if (k.key >= MLX_KEY_1 && k.key <= MLX_KEY_4)
        {
            s->mode = k.key - MLX_KEY_1;
            ft_draw(s);
		}
		else if (k.key == MLX_KEY_R)
		{
			s->a = 1.0;
			s->b = 1.0;
			s->c = 0.0;
			s->d = 0.0;
			ft_draw(s);
		}
	}
}

void	ft_scrollhook(double xd, double yd, void *param)
{
	t_sine	*s;
	double	delta;

	s = (t_sine *)param;
	delta = yd * 0.1;
	if (s->mode == 0)
		s->a += delta;
	else if (s->mode == 1)
		s->b += delta;
	else if (s->mode == 2)
		s->c += delta;
	else if (s->mode == 3)
		s->d += delta;
	ft_draw(s);
	(void ) xd;
}
