/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 03:09:20 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/22 23:04:18 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdio.h>

static int	ft_init(t_fdf *f)
{
	f->angle_x = 0.0f;
	f->angle_y = 0.0f;
	f->angle_z = 0.0f;
	f->scale = 20.0f;
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

void	ft_print_map(t_fdf *f)
{
	int	x;
	int	y;

	printf("== Mapa de Altitudes e Cores ==\n");
	for (y = 0; y < f->map.height; y++)
	{
		for (x = 0; x < f->map.width; x++)
		{
			//printf("[%3d, %#08x] ", f->map.altitudes[y][x], f->map.colors[y][x]);
			printf("%3d", f->map.altitudes[y][x]);
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
