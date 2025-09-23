/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:22:04 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/23 18:57:51 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static inline void	ft_put(uint32_t *pixels, int x, int y,
		uint32_t color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		pixels[y * WIDTH + x] = color;
}

static void	ft_bresenham_init(t_bresenham *bre, t_vec2 a, t_vec2 b)
{
	bre->dx = fabs(b.x - a.x);
	bre->dy = fabs(b.y - a.y);
	if (a.x < b.x)
		bre->sx = 1;
	else
		bre->sx = -1;
	if (a.y < b.y)
		bre->sy = 1;
	else
		bre->sy = -1;
	bre->err = bre->dx - bre->dy;
	bre->e2 = 0;
}

static float	ft_ratio(step, dist)
{
	if (dist != 0.0f)
		return ((float ) step / dist);
	return (0.0f);
}

void	ft_bresenham(t_fdf *f, t_vec2 a, t_vec2 b)
{
	int			step;
	float		dist;
	int			x0;
	int			y0;
	float		ratio;
	uint32_t	color;

	ft_bresenham_init(&f->bre, a, b);
	x0 = (int ) a.x;
	y0 = (int ) a.y;
	step = 0;
	dist = sqrtf((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
	while (1)
	{
		ratio = ft_ratio(step, dist);
		color = ft_interpolate(a.color, b.color, ratio);
		ft_put(f->pixels, x0, y0, color);
		if (x0 == (int) b.x && y0 == (int) b.y)
			break ;
		f->bre.e2 = 2 * f->bre.err;
		if (f->bre.e2 > -f->bre.dy)
		{
			f->bre.err -= f->bre.dy;
			x0 += f->bre.sx;
		}
		if (f->bre.e2 < f->bre.dx)
		{
			f->bre.err += f->bre.dx;
			y0 += f->bre.sy;
		}
		step++;
	}
}
