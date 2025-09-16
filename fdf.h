/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 23:37:12 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/16 14:25:05 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <fcntl.h>

# define WIDTH 1280
# define HEIGHT 800

typedef struct s_map
{
	int	width;
	int	height;
	int	**altitudes;
	int	min_alt;
	int	max_alt;
}	t_map;

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

typedef struct s_draw
{
	int	x;
	int	y;
	t_vec3	point3d;
	t_vec2	point2d;
	t_vec2	next2d;
}	t_draw;

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
	float		angle_x;
	float		angle_y;
	float		angle_z;
	float		scale;
	float		z_scale;
	int			offset_x;
	int			offset_y;
	t_map		map;
	t_bresenham	bre;
}	t_fdf;

void	ft_draw(t_fdf	*s);
void	ft_drawbuffer(mlx_image_t *img, int x, int y, uint32_t color);
void	ft_keyhook(mlx_key_data_t keydata, void *param);
int		ft_errorinit(mlx_t *mlx);
int		ft_errorimg(mlx_t *mlx, mlx_image_t *img);
void	ft_clearimg(t_fdf *s);
void	ft_scrollhook(double xd, double yd, void *param);
void	ft_bresenham_init(t_bresenham *bre, t_vec2 a, t_vec2 b);
void	ft_bresenham(t_fdf *f, t_vec2 a, t_vec2 b);

t_vec2	ft_iso(t_vec3 p);
void	ft_rotatex(t_vec3 *p, float angle);
void	ft_rotatey(t_vec3 *p, float angle);
void	ft_rotatez(t_vec3 *p, float angle);
void	ft_axes(t_fdf *s);

#endif
