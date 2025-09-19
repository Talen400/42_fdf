/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 03:09:20 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/18 23:54:23 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
/*
uint32_t	ft_altitude_to_color(int altitude, int min_alt, int max_alt)
{
	float		normalized;
	uint32_t	low_color;
	uint32_t	high_color;

	low_color = 0x0066FFFF;
	high_color = 0xFF3300FF;
	if (max_alt == min_alt)
		return (0xFFFFFFFF);
	normalized = (float) ((altitude - min_alt) / (max_alt - min_alt));
	return (ft_interpolate(low_color, high_color, normalized));
}
*/
#include <stdio.h>

void	ft_right(t_fdf *f, t_vec2 point2d, int x, int y)
{
	t_vec2	right;

	if (x < f->map.width - 1)
	{
		right = ft_get2d(f, x + 1, y);
		if (point2d.x != right.x || point2d.y != right.y)
		{
			ft_bresenham(f, point2d, right, f->map.colors[y][x]);
		}
	}
}

void	ft_down(t_fdf *f, t_vec2 point2d, int x, int y)
{
	t_vec2	down;

	if (y < f->map.height - 1)
	{
		down = ft_get2d(f, x, y + 1);
		if (point2d.x != down.x || point2d.y != down.y)
		{
			ft_bresenham(f, point2d, down, f->map.colors[y][x]);
		}
	}
}

static void	ft_map(t_fdf *f)
{
	int 	x;
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
	ft_map(f);
}

static int	ft_init(t_fdf *f)
{
	
	f->angle_x = 0.0f;
	f->angle_y = 0.0f;
	f->angle_z = 0.0f;
	f->scale = 20.0f;
	f->z_scale = 1.0f;
	f->offset_x = WIDTH / 2;
	f->offset_y = HEIGHT / 2;
	f->mlx = mlx_init(WIDTH, HEIGHT, "fdf", true);
	if (!f->mlx)
		return (ft_errorinit(f->mlx));
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img)
		return (ft_errorinit(f->mlx));
	f->pixels = (uint32_t *) f->img->pixels;
	return (0);
}

void	ft_freemap(t_fdf *f)
{
	int	i;

	i = 0;
	while (i < f->map.height)
	{
		free(f->map.altitudes[i]);
		free(f->map.colors[i]);
		i++;
	}
	free(f->map.altitudes);
	free(f->map.colors);
}

#include <stdio.h>

void	ft_print_map(t_fdf *f)
{
	int	x, y;

	printf("== Mapa de Altitudes e Cores ==\n");
	for (y = 0; y < f->map.height; y++)
	{
		for (x = 0; x < f->map.width; x++)
		{
			printf("[%3d, %#08x] ", f->map.altitudes[y][x], f->map.colors[y][x]);
		}
		printf("\n");
	}
}

int	main(int argc, char *argv[])
{
	t_fdf	f;

	if (argc != 2)
		return (1);
	if (ft_init(&f) != 0)
		return (1);
	ft_read(&f, argv[1]);
	ft_auto_calibrate(&f);
	ft_print_map(&f);
	ft_draw(&f);
	if (mlx_image_to_window(f.mlx, f.img, 0, 0) == -1)
		return (ft_errorimg(f.mlx, f.img));
	mlx_scroll_hook(f.mlx, &ft_scrollhook, &f);
	mlx_key_hook(f.mlx, &ft_keyhook, &f);
	mlx_loop(f.mlx);
	mlx_terminate(f.mlx);
	ft_freemap(&f);
	return (0);
}
