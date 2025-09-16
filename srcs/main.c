/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 03:09:20 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/16 00:23:00 by tlavared         ###   ########.fr       */
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

void	ft_dda(t_fdf *f, int x0, int y0, int x1, int y1)
{
	t_dda	dda;
	int		i;

	dda = f->dda;
	dda.x_diff = x1 - x0;
	dda.y_diff = y1 - y0;
	dda.steps = abs(dda.x_diff);
	if (abs(dda.y_diff) > dda.steps)
		dda.steps = abs(dda.y_diff);
	if (dda.steps == 0)
	{
		ft_put(f->pixels, x0, y0, 0x404040FF);
		return;
	}
	dda.x_inc = dda.x_diff / (float ) dda.steps;
	dda.y_inc = dda.y_diff / (float ) dda.steps;
	i = 0;
	while (i <= dda.steps)
	{
		ft_put(f->pixels, (int )roundf(x0), (int )roundf(y0), 0x404040FF);
		x0 += dda.x_inc;
		y0 += dda.y_inc;
		i++;
	}
}

void	ft_draw(t_fdf	*f)
{
	int		x;
	int		y;
	double	math_x;
	double	math_y;
	int		prev_y;

	ft_clearimg(f);
	ft_axes(f);
	x = -1;
	math_x = (x - (WIDTH / 2)) * 3 / 100.0;
	math_y = f->a * sin(f->b * math_x + f->c) + f->d;
	y = (HEIGHT / 2) - (int)(math_y * WIDTH / 6);
	while (++x < WIDTH)
	{
		math_x = (x - (WIDTH / 2)) * 3 / 100.0;
		math_y = f->a * sin(f->b * math_x + f->c) + f->d;
		y = (HEIGHT / 2) - (int)(math_y * WIDTH / 6);
		ft_dda(f, x - 1, prev_y, x, y);
		prev_y = y;
	}
}

int	main(void)
{
	t_fdf	f;

	f.a = 1.0;
	f.b = 1.0;
	f.c = 0.0;
	f.d = 0.0;
	f.mode = 0;
	f.mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (!f.mlx)
		return (ft_errorinit(f.mlx));
	f.img = mlx_new_image(f.mlx, WIDTH, HEIGHT);
	if (!f.img)
		return (ft_errorinit(f.mlx));
	f.pixels = (uint32_t *) f.img->pixels;
	ft_draw(&f);
	// fractal..
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
