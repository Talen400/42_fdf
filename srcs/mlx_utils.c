/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 02:41:00 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/16 12:34:22 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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
	ft_memset(f->img->pixels, 0xF8F9FA, f->img->width * f->img->height 
			*sizeof(uint32_t));
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
