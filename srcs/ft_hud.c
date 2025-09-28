/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hud.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 23:56:25 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/28 02:06:15 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_mlx_char_to_int(t_fdf *f, mlx_image_t **img, const char *input,
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
	ft_mlx_char_to_int(f, &f->hud.angle_y, "angle_y ", f->angle_y, 30, 75);
	ft_mlx_char_to_int(f, &f->hud.angle_z, "angle_z: ", f->angle_z, 30, 90);
	ft_mlx_char_to_int(f, &f->hud.scale, "scale: ", f->scale, 30, 105);
}

static void	ft_clear_img(t_fdf *f, mlx_image_t **img)
{
	if (*img)
	{
		mlx_delete_image(f->mlx, *img);
		*img = NULL;
	}
}

void	ft_clear_hud(t_fdf *f)
{
	ft_clear_img(f, &f->hud.offset_x);
	ft_clear_img(f, &f->hud.offset_y);
	ft_clear_img(f, &f->hud.angle_x);
	ft_clear_img(f, &f->hud.angle_y);
	ft_clear_img(f, &f->hud.angle_z);
	ft_clear_img(f, &f->hud.scale);
}

