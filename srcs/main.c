/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 03:09:20 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/16 09:30:44 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static inline void	ft_put(uint32_t *pixels, int x, int y,
		uint32_t color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		pixels[y * WIDTH + x] = color;
}

void	ft_axes(t_fdf *s)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIDTH)
		s->pixels[(HEIGHT / 2) * WIDTH + x] = 0xFEFEFE;
	y = -1;
	while (++y < HEIGHT)
		s->pixels[y * WIDTH + (WIDTH / 2)] = 0xFEFEFE;
}

void	ft_bresenham_init(t_bresenham *bre, t_vec2 a, t_vec2 b)
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

void	ft_bresenham(t_fdf *f, t_vec2 a, t_vec2 b)
{
	ft_bresenham_init(&f->bre, a, b);
	while (1)
	{
		ft_put(f->pixels, a.x, a.y, 0xFEFEFE);
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

t_vec2	ft_iso(t_vec3 p)
{
	t_vec2	result;

	result.x = (int) ((p.x - p.y) * cos(0.523599));
	result.y = (int) ((p.x + p.y) * sin(0.523599) - p.z);
	return (result);
}

void	ft_rotatex(t_vec3 *p, float angle)
{
	float	y;
	float	z;

	y = p->y;
	z = p->z;
	p->y = y * cosf(angle) - z * sinf(angle);
	p->z = y * sinf(angle) + z * cosf(angle);
}

void	ft_rotatey(t_vec3 *p, float angle)
{
	float	x;
	float	z;

	x = p->x;
	z = p->z;
	p->x = x * cosf(angle) + z * sinf(angle);
	p->z = -x * sinf(angle) + z * cosf(angle);
}

void	ft_rotatez(t_vec3 *p, float angle)
{
	float	x;
	float	y;

	x = p->x;
	y = p->y;
	p->x = x * cosf(angle) - y * sinf(angle);
	p->y = x * sinf(angle) + y * cosf(angle);
}

static void	ft_drawloop(t_fdf *f)
{
	t_vec3	cube[8] = {
		{-1, -1, -1}, {1, -1, -1}, {1, 1, -1}, {-1, 1, -1},
		{-1, -1,  1}, {1, -1,  1}, {1, 1,  1}, {-1, 1,  1}
	};
	int edges[12][2] = {
		{0,1}, {1,2}, {2,3}, {3,0},
		{4,5}, {5,6}, {6,7}, {7,4},
		{0,4}, {1,5}, {2,6}, {3,7}
	};
	t_vec2	projected[8];

	for (int i = 0; i < 8; i++)
	{
		t_vec3 p = cube[i];
		// rotacionar
		ft_rotatex(&p, f->angle_x);
		ft_rotatey(&p, f->angle_y);
		ft_rotatez(&p, f->angle_z);
		// escalar (para caber na tela)
		p.x *= 100;
		p.y *= 100;
		p.z *= 100;
		// projetar
		projected[i] = ft_iso(p);
		// centralizar na tela
		projected[i].x += WIDTH / 2;
		projected[i].y += HEIGHT / 2;
	}
	for (int i = 0; i < 12; i++)
		ft_bresenham(f, projected[edges[i][0]], projected[edges[i][1]]);
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
	f.angle_x = 0.0f;
	f.angle_y = 0.0f;
	f.angle_z = 0.0f;
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
