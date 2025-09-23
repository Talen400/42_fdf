/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 02:41:00 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/22 22:38:23 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static inline void	ft_put(uint32_t *pixels, int x, int y,
		uint32_t color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		pixels[y * WIDTH + x] = color;
}

int	ft_errorinit(mlx_t *mlx)
{
	if (mlx)
		mlx_terminate(mlx);
	ft_printf("%s", mlx_strerror(mlx_errno));
	return (1);
}

int	ft_errorimg(mlx_t *mlx, mlx_image_t *img)
{
	if (img)
		mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (1);
}

void	ft_clearimg(t_fdf *f)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_put(f->pixels, x, y, 0x00000000);
			x++;
		}
		y++;
	}
}
