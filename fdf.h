/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 23:37:12 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/16 07:49:45 by tlavared         ###   ########.fr       */
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

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef struct s_vec2
{
	int	x;
	int	y;
}	t_vec2;

typedef struct s_bresenham
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			e2;
}	t_bresenham;

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
	float		angle_x;
	float		angle_y;
	float		angle_z;
	t_bresenham	bre;
}	t_fdf;

void	ft_draw(t_fdf	*s);
void	ft_drawbuffer(mlx_image_t *img, int x, int y, uint32_t color);
void	ft_keyhook(mlx_key_data_t keydata, void *param);
int		ft_errorinit(mlx_t *mlx);
int		ft_errorimg(mlx_t *mlx, mlx_image_t *img);
void	ft_clearimg(t_fdf *s);
void	ft_scrollhook(double xd, double yd, void *param);
#endif
