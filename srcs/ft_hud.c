/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hud.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 23:56:25 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/28 00:15:58 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_mlx_char_to_int(t_fdf *f,mlx_image_t **img, const char *input,
	int integer, int x, int y)
{
	char	*str;
	char	*ptr;
	char	*joined;

	str = ft_itoa(integer);
	if (!str)
	{
		free(str);
		str = NULL;
	}
	ptr = (char *) input;
	joined = ft_strjoin(ptr, str);
	*img = mlx_put_string(f->mlx, joined, x, y);
	free(str);
	free(joined);
}

void	ft_hud(t_fdf *f)
{
	ft_mlx_char_to_int(f, &f->hud.offset_x, "offset_x: ", f->offset_x, 30, 30);
	ft_mlx_char_to_int(f, &f->hud.offset_y, "offset_y: ", f->offset_y, 30, 45);
	ft_mlx_char_to_int(f, &f->hud.angle_x, "angle_x: ", f->angle_x, 30, 60);
	ft_mlx_char_to_int(f, &f->hud.angle_y, "offset_x: ", f->angle_y, 30, 75);
	ft_mlx_char_to_int(f, &f->hud.angle_z, "offset_x: ", f->angle_z, 30, 90);
}

void	ft_clear_hud(t_fdf *f)
{
	if (f->hud.offset_x)
	{
		mlx_delete_image(f->mlx, f->hud.offset_x);
		f->hud.offset_x = NULL;
	}
	if (f->hud.offset_y)
	{
		mlx_delete_image(f->mlx, f->hud.offset_y);
		f->hud.offset_y = NULL;
	}
	if (f->hud.angle_x)
	{
		mlx_delete_image(f->mlx, f->hud.angle_x);
		f->hud.angle_x = NULL;
	}
	if (f->hud.angle_y)
	{
		mlx_delete_image(f->mlx, f->hud.angle_y);
		f->hud.angle_y = NULL;
	}
	if (f->hud.angle_z)
	{
		mlx_delete_image(f->mlx, f->hud.angle_z);
		f->hud.angle_z = NULL;
	}
}

