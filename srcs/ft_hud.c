/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hud.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 23:49:45 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/27 02:15:51 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static char	*ft_put_float(float	num)
{
	char	*integer;
	char	*decimal;
	char	*temp;
	char	*result;

	integer = ft_itoa((int ) num);
	num -= (int) num;
	decimal = ft_itoa((int ) (num * 1000));
	temp = ft_strjoin(integer, ".");
	result = ft_strjoin(temp, decimal);
	free(integer);
	free(decimal);
	free(temp);
	return (result);
}


void	ft_hud(t_fdf *f)
{
	t_hud	*hud;

	hud = &f->hud;
	hud->angle_x = mlx_put_string(f->mlx, ft_put_float(f->angle_x), 30, 30);
	hud->angle_y = mlx_put_string(f->mlx, ft_put_float(f->angle_y), 30, 45);
	hud->angle_z = mlx_put_string(f->mlx, ft_put_float(f->angle_z), 30, 60);
}

void	ft_clear_hud(t_fdf *f)
{
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

