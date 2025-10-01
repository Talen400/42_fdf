/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 23:37:12 by tlavared          #+#    #+#             */
/*   Updated: 2025/10/01 01:48:15 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <fcntl.h>

# define WIDTH 1200
# define HEIGHT 800
# define MARGIN 0.15f

typedef struct s_map
{
	int	width;
	int	height;
	int	**altitudes;
	int	**colors;
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
	float	x;
	float	y;
	float	color;
}	t_vec2;

typedef struct s_draw
{
	int		x;
	int		y;
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
	int			step;
	float		ratio;
}	t_bresenham;

typedef struct s_fdf
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	uint8_t			*pixels;
	float			scale;
	float			z_scale;
	int				offset_x;
	int				offset_y;
	int				center_x;
	int				center_y;
	int				center_z;
	t_map			map;
	t_bresenham		bre;
}	t_fdf;

typedef struct s_color
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;
}	t_color;

// utils of reads
void		ft_free_split(char **split);

// hex parse
int			ft_hex_to_int(char *hex);

// MLX42
void		ft_keyhook(mlx_key_data_t keydata, void *param);

// read
int			ft_read(t_fdf *f, char *filename);

// main of draw
void		ft_draw(t_fdf *f);

// algebra functions
t_vec2		ft_get2d(t_fdf *f, int x, int y);

// MLX42
void		ft_keyhook(mlx_key_data_t keydata, void *param);
int			ft_errorinit(mlx_t *mlx);
int			ft_errorimg(mlx_t *mlx, mlx_image_t *img);
void		ft_clearimg(t_fdf *s);

// bresenham
void		ft_bresenham(t_fdf *f, t_vec2 a, t_vec2 b);

// auto-calibrate
void		ft_auto_calibrate(t_fdf *f);

// colors
t_color		ft_init_color(uint32_t color);
uint32_t	ft_color_to_int32(t_color color);
uint32_t	ft_interpolate(uint32_t start, uint32_t end, float ratio);

// math
float		ft_degree_to_radian(int degree);

#endif
