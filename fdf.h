/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 23:37:12 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/30 02:36:31 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <fcntl.h>

# define M_PI 3.14159265358979323846
# define WIDTH 1200
# define HEIGHT 800
# define MARGIN 0.15f
# define MOVE 10
# define ZOOM 1
# define VEL_ROTATION_ANGLE 5
# define AXIS_POS 80
# define AXIS_LENGHT 40

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
	int			step;
	float		ratio;
}	t_bresenham;

typedef struct s_hud
{
	mlx_image_t	*angle_x;
	mlx_image_t	*angle_y;
	mlx_image_t	*angle_z;
	mlx_image_t	*offset_x;
	mlx_image_t	*offset_y;
	mlx_image_t	*scale;
	mlx_image_t	*z_scale;
}	t_hud;

typedef struct s_fdf
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_hud		hud;
	uint8_t		*pixels;
	int			angle_x;
	int			angle_y;
	int			angle_z;
	float		scale;
	float		z_scale;
	int			offset_x;
	int			offset_y;
	int			center_x;
	int			center_y;
	int			center_z;
	t_map		map;
	t_bresenham	bre;
}	t_fdf;

typedef struct s_color
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;
}	t_color;

// utils of reads
void	ft_free_split(char **split);

// hex parse
int			ft_hex_to_int(char *hex);

// read
int		ft_read(t_fdf *f, char *filename);

// main of draw
void	ft_draw(t_fdf *f);

// MLX42
void	ft_keyhook(mlx_key_data_t keydata, void *param);
int		ft_errorinit(mlx_t *mlx);
int		ft_errorimg(mlx_t *mlx, mlx_image_t *img);
void	ft_clearimg(t_fdf *s);
void	ft_scrollhook(double xd, double yd, void *param);

// bresenham
void	ft_bresenham(t_fdf *f, t_vec2 a, t_vec2 b);

// algebra functions
t_vec2	ft_get2d(t_fdf *f, int x, int y);
void	ft_rotatex(t_vec3 *p, float angle);
void	ft_rotatey(t_vec3 *p, float angle);
void	ft_rotatez(t_vec3 *p, float angle);
t_vec2	ft_iso(t_vec3 p, float angle);

// auto-calibrate
void	ft_auto_calibrate(t_fdf *f);

// colors
t_color	ft_init_color(uint32_t color);
uint32_t	ft_color_to_int32(t_color color);
uint32_t	ft_interpolate(uint32_t start, uint32_t end, float ratio);

// math
float	ft_degree_to_radian(int degree);

// hud
void	ft_hud(t_fdf *f);
void	ft_clear_hud(t_fdf *f);

// hud utils
char	*ft_create_label_float(const char *prefix, float value);
char	*ft_create_label(const char *prefix, int value);
void	ft_clear_img(t_fdf *f, mlx_image_t **img);

// axis
void	ft_draw_orientation_arrows(t_fdf *f);

// axis utils
void	ft_init_axis_vectors(t_vec3 *axis_x, t_vec3 *axis_y, t_vec3 *axis_z);
void	ft_setup_origin(t_vec2 *origin);
t_vec3	ft_rotate_axis_vector(t_fdf *f, t_vec3 axis);

#endif
