/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 03:09:20 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/16 05:12:10 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static inline void	ft_put(uint32_t *pixels, int x, int y,
		uint32_t color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y <= HEIGHT)
		pixels[y * WIDTH + x] = color;
}

void	ft_axes(t_fdf *s)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIDTH)
		s->pixels[(HEIGHT / 2) * WIDTH + x] = 0x404040FF;
	y = -1;
	while (++y < HEIGHT)
		s->pixels[y * WIDTH + (WIDTH / 2)] = 0x404040FF;
}

void	ft_bresenham_init(t_bresenham *bre, t_point a, t_point b)
{
	bre->dx = abs(b.x - a.x);
	bre->dy = abs(b.y - a.y);
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

void	ft_bresenham(t_fdf *f, t_point a, t_point b)
{
	ft_bresenham_init(&f->bre, a, b);
	while (1)
	{
		ft_put(f->pixels, a.x, a.y, 0x404040FF);
		if (a.x == b.x && a.y == b.y)
			break;
		f->bre.e2 = 2 * f->bre.err;
		if (f->bre.e2 > -f->bre.dy)
		{
			f->bre.err -= f->bre.dy;
			a.x += f->bre.sx;
		}
		if (f->bre.e2 < f->bre.dx)
		{
			f->bre.err += f->bre.dx;
			a.y += f->bre.sy;
		}
	}
}

static t_point	ft_calc(t_fdf *f, int x)
{
	t_point	p;
	double	math_x;
	double	math_y;

	math_x = (x - (WIDTH / 2)) * 3 / 100.0;
	math_y = f->a * sin(f->b * math_x + f->c) + f->d;	
	p.x = x;
	p.y = (HEIGHT / 2) - (int)(math_y * WIDTH / 6);
	return (p);	
}

static void	ft_drawloop(t_fdf *f)
{
	int		x;
	t_point	prev;
	t_point	curr;

	x = 0;
	prev = ft_calc(f, x);
	while (x < WIDTH)
	{
		curr = ft_calc(f, x);
		ft_bresenham(f, prev, curr);
		prev = curr;
		x++;
	}
}

void	ft_draw(t_fdf *f)
{
	ft_clearimg(f);
	ft_axes(f);
	ft_drawloop(f);
}

int	main(void)
{
	t_fdf	f;

	f.a = 1.0;
	f.b = 1.0;
	f.c = 0.0;
	f.d = 0.0;
	f.mode = 0;
	f.mlx = mlx_init(WIDTH, HEIGHT, "fdf", true);
	if (!f.mlx)
		return (ft_errorinit(f.mlx));
	f.img = mlx_new_image(f.mlx, WIDTH, HEIGHT);
	if (!f.img)
		return (ft_errorinit(f.mlx));
	f.pixels = (uint32_t *) f.img->pixels;
	ft_draw(&f);
	if (mlx_image_to_window(f.mlx, f.img, 0, 0) == -1)
		return (ft_errorimg(f.mlx, f.img));
	mlx_scroll_hook(f.mlx, &ft_scrollhook, &f);
	mlx_key_hook(f.mlx, &ft_keyhook, &f);
	ft_printf("y = A * sin(B * x + C) + D\n");
	ft_printf("1-4: modo A,B,D,D | Scroll: alterar | R: reset\n", 1);
	mlx_loop(f.mlx);
	mlx_terminate(f.mlx);
	return (0);
}
