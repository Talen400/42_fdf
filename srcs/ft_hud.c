/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hud.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 23:56:25 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/30 03:48:37 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/*
 FLOAT
*/

static void	ft_display_float(t_fdf *f, mlx_image_t **img,
	const char *label, float value)
{
	char	*text;
	t_vec2	pos;

	pos.x = 30;
	pos.y = 30;
	text = ft_create_label_float(label, value);
	if (!text)
		return ;
	*img = mlx_put_string(f->mlx, text, (int) pos.x, (int) pos.y);
	free(text);
}

/*
 INTEGER
*/

static void	ft_display_int(t_fdf *f, mlx_image_t **img,
	const char *label, int value)
{
	char	*text;
	t_vec2	pos;

	pos.x = 30;
	pos.y = 30;
	text = ft_create_label(label, value);
	if (!text)
		return ;
	*img = mlx_put_string(f->mlx, text, (int ) pos.x, (int) pos.y);
	free(text);
}

static void	ft_hud_2(t_fdf *f, int y)
{
	char	*proj_text;

	ft_display_int(f, &f->hud.focal, "focal: ", f->focal_lenght);
	if (f->hud.focal)
		f->hud.focal->instances[0].y = y + 120;
	proj_text = ft_get_projection_name(f->projection);
	f->hud.projection = mlx_put_string(f->mlx, (char *)proj_text, 30, y + 135);
	if (f->hud.projection)
		f->hud.projection->instances[0].y = y + 135;
}

void	ft_hud(t_fdf *f)
{
	int	y;

	y = 30;
	ft_display_int(f, &f->hud.offset_x, "offset_x: ", f->offset_x);
	if (f->hud.offset_x)
		f->hud.offset_x->instances[0].y = y + 15;
	ft_display_int(f, &f->hud.offset_y, "offset_y: ", f->offset_y);
	if (f->hud.offset_y)
		f->hud.offset_y->instances[0].y = y + 30;
	ft_display_int(f, &f->hud.angle_x, "angle_x: ", f->angle_x);
	if (f->hud.angle_x)
		f->hud.angle_x->instances[0].y = y + 45;
	ft_display_int(f, &f->hud.angle_y, "angle_y: ", f->angle_y);
	if (f->hud.angle_y)
		f->hud.angle_y->instances[0].y = y + 60;
	ft_display_int(f, &f->hud.angle_z, "angle_z: ", f->angle_z);
	if (f->hud.angle_z)
		f->hud.angle_z->instances[0].y = y + 75;
	ft_display_float(f, &f->hud.scale, "scale: ", f->scale);
	if (f->hud.scale)
		f->hud.scale->instances[0].y = y + 90;
	ft_display_float(f, &f->hud.z_scale, "z_scale: ", f->z_scale);
	if (f->hud.z_scale)
		f->hud.z_scale->instances[0].y = y + 105;
	ft_hud_2(f, y);
}

void	ft_clear_hud(t_fdf *f)
{
	ft_clear_img(f, &f->hud.offset_x);
	ft_clear_img(f, &f->hud.offset_y);
	ft_clear_img(f, &f->hud.angle_x);
	ft_clear_img(f, &f->hud.angle_y);
	ft_clear_img(f, &f->hud.angle_z);
	ft_clear_img(f, &f->hud.scale);
	ft_clear_img(f, &f->hud.z_scale);
	ft_clear_img(f, &f->hud.focal);
	ft_clear_img(f, &f->hud.projection);
}
