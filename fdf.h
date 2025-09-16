/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 23:37:12 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/16 00:21:27 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <math.h>

# include <math.h>

# define WIDTH 1280
# define HEIGHT 800

typedef struct s_dda
{
	int			x_diff;
	int			y_diff;
	int			steps;
	double		x_inc;
	double		y_inc;
}	t_dda;

typedef struct s_fdf
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	uint32_t	*pixels;
	int			mode;
	double		a;
	double		b;
	double		c;
	double		d;
	t_dda		dda;
}	t_fdf;

void	ft_draw(t_fdf	*s);
void	ft_drawbuffer(mlx_image_t *img, int x, int y, uint32_t color);
void	ft_keyhook(mlx_key_data_t keydata, void *param);
int		ft_errorinit(mlx_t *mlx);
int		ft_errorimg(mlx_t *mlx, mlx_image_t *img);
void	ft_clearimg(t_fdf *s);
void	ft_scrollhook(double xd, double yd, void *param);
#endif
