/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 03:09:20 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/12 17:06:51 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
/**
static inline void	ft_put(uint32_t *pixels, int x, int y,
		uint32_t color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y <= HEIGHT)
		pixels[y * WIDTH + x] = color;
}
**/

void	ft_draw(t_sine	*s)
{
	int		x;
	int		y;
	double	math_x;
	double	math_y;

	ft_clearimg(s);
	x = -1;
	while (++x < WIDTH)
		s->pixels[HALF_HEIGHT * WIDTH + x] = 0x404040FF;
	y = -1;
	while (++y < HEIGHT)
		s->pixels[y * WIDTH + HALF_WIDTH] = 0x404040FF;
	x = -1;
	while (++x < WIDTH)
	{
		math_x = (x - HALF_WIDTH) * 3 / 100.0;
		math_y = s->a * sin(s->b * math_x + s->c);
		y = HALF_HEIGHT - (int)(math_y * 50.0);
		if (y >= 0 && y < HEIGHT)
		{
			s->pixels[y * WIDTH + x] = 0x00FF00FF;
			if (y > 0)
				s->pixels[(y - 1) * WIDTH + x] = 0x00FF00FF;
			if (y < HEIGHT - 1)
				s->pixels[(y + 1) * WIDTH + x] = 0x00FF00FF;
		}
	}
}

int	main(void)
{
	t_sine	s;

	s.a = 1.0;
	s.b = 1.0;
	s.c = 0.0;
	s.d = 0.0;
	s.mode = 0;
	s.mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (!s.mlx)
		return (ft_errorinit(s.mlx));
	s.img = mlx_new_image(s.mlx, WIDTH, HEIGHT);
	if (!s.img)
			return (ft_errorinit(s.mlx));
	s.pixels = (uint32_t *) s.img->pixels;
	ft_draw(&s);
	// fractal..
	if (mlx_image_to_window(s.mlx, s.img, 0, 0) == -1)
		return (ft_errorimg(s.mlx, s.img));
	mlx_scroll_hook(s.mlx, &ft_scrollhook, &s);
	mlx_key_hook(s.mlx, &ft_keyhook, &s);
	ft_printf("y = A * sin(B * x + C) + D\n");
	ft_printf("1-4: modo A,B,D,D | Scroll: alterar | R: reset\n", 1);
	mlx_loop(s.mlx);
	mlx_terminate(s.mlx);
	return (0);
}
