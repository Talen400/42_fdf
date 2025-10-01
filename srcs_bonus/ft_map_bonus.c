/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 22:44:09 by tlavared          #+#    #+#             */
/*   Updated: 2025/10/01 00:52:07 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

static void	ft_right(t_fdf *f, t_vec2 point2d, int x, int y)
{
	t_vec2	right;

	if (x < f->map.width - 1)
	{
		right = ft_get2d(f, x + 1, y);
		if (point2d.x != right.x || point2d.y != right.y)
		{
			ft_bresenham(f, point2d, right);
		}
	}
}

static void	ft_down(t_fdf *f, t_vec2 point2d, int x, int y)
{
	t_vec2	down;

	if (y < f->map.height - 1)
	{
		down = ft_get2d(f, x, y + 1);
		if (point2d.x != down.x || point2d.y != down.y)
		{
			ft_bresenham(f, point2d, down);
		}
	}
}

static void	ft_map(t_fdf *f)
{
	int		x;
	int		y;
	t_vec2	point2d;

	y = 0;
	while (y < f->map.height)
	{
		x = 0;
		while (x < f->map.width)
		{
			point2d = ft_get2d(f, x, y);
			ft_right(f, point2d, x, y);
			ft_down(f, point2d, x, y);
			x++;
		}
		y++;
	}
}

void	ft_draw(t_fdf *f)
{
	ft_clearimg(f);
	ft_clear_hud(f);
	ft_map(f);
	ft_draw_orientation_arrows(f);
	ft_hud(f);
}
