/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 02:41:00 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/15 23:30:21 by tlavared         ###   ########.fr       */
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

void	ft_clearimg(t_fdf *s)
{
	ft_memset(s->img->pixels, 255, s->img->width * s->img->height * sizeof(uint32_t));
}
