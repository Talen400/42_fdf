/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 03:09:20 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/16 17:53:13 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_freesplit(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_count(t_fdf *f, int fd)
{
	char	*line;
	char	**values;
	int		x;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		values = ft_split(line, ' ');
		if (f->map.height == 0)
		{
			x = 0;
			while (values[x])
				x++;
			f->map.width = x;
		}
		f->map.height++;
		free(line);
		ft_freesplit(values);
	}
}

void	ft_altitudes(t_fdf *f)
{
	int	i;

	f->map.altitudes = (int **) malloc(sizeof(int *) * f->map.height);
	i = 0;
	while (i < f->map.height)
	{
		f->map.altitudes[i] = (int *) malloc(sizeof(int) * f->map.width);
		i++;
	}
}

void	ft_reading(t_fdf *f, int fd)
{
	int		x;
	int		y;
	char	*line;
	char	**values;

	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		values = ft_split(line, ' ');
		x = 0;
		while (values[x] && x < f->map.width)
		{
			f->map.altitudes[y][x] = ft_atoi(values[x]);
			x++;
		}
		y++;
		free(line);
		ft_freesplit(values);
	}
}

void	ft_read(t_fdf *f, char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return ;
	f->map.height = 0;
	f->map.width = 0;
	ft_count(f, fd);
	close(fd);
	ft_altitudes(f);
	fd = open(filename, O_RDONLY);
	ft_reading(f, fd);
	close(fd);
}

void	ft_top(t_fdf *f, t_vec2 *point2d, int x, int y)
{
	t_vec2	next2d;
	if (x < f->map.width - 1)
	{
		next2d = ft_iso((t_vec3){x + 1, y, f->map.altitudes[y][x + 1]});
		next2d.x = next2d.x * f->scale + f->offset_x;
		next2d.y = next2d.y * f->scale + f->offset_y;
		ft_bresenham(f, *point2d, next2d);
	}
}

void	ft_bottom(t_fdf *f, t_vec2 *point2d, int x, int y)
{
	t_vec2	next2d;

	if (y < f->map.height - 1)
	{
		next2d = ft_iso((t_vec3){x, y + 1, f->map.altitudes[y + 1][x]});
		next2d.x = next2d.x * f->scale + f->offset_x;
		next2d.y = next2d.y * f->scale + f->offset_y;
		ft_bresenham(f, *point2d, next2d);
	}
}

static void	ft_map(t_fdf *f)
{
	int 	x;
	int		y;
	t_vec3	point3d;
	t_vec2	point2d;

	y = 0;
	while (y < f->map.height)
	{
		x = 0;
		while (x < f->map.width)
		{
			point3d = (t_vec3){x, y, f->map.altitudes[y][x]};
			ft_rotatex(&point3d, f->angle_x);
			ft_rotatey(&point3d, f->angle_y);
			ft_rotatez(&point3d, f->angle_z);
			point2d = ft_iso(point3d);
			point2d.x = point2d.x * f->scale + f->offset_x;
			point2d.y = point2d.y * f->scale + f->offset_y;
			ft_top(f, &point2d, x, y);
			ft_bottom(f, &point2d, x, y);
			x++;
		}
		y++;
	}
}

void	ft_draw(t_fdf *f)
{
	ft_clearimg(f);
	ft_axes(f);
	ft_map(f);
}

static int	ft_init(t_fdf *f)
{
	f->angle_x = 0.0f;
	f->angle_y = 0.0f;
	f->angle_z = 0.0f;
	f->scale = 20.0f;
	f->z_scale = 1.0f;
	f->offset_x = WIDTH / 2;
	f->offset_y = HEIGHT / 2;
	f->mlx = mlx_init(WIDTH, HEIGHT, "fdf", true);
	if (!f->mlx)
		return (ft_errorinit(f->mlx));
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img)
		return (ft_errorinit(f->mlx));
	f->pixels = (uint32_t *) f->img->pixels;
	return (0);
}

void	ft_freemap(t_fdf *f)
{
	int	i;

	i = 0;
	while (i < f->map.height)
	{
		free(f->map.altitudes[i]);
		i++;
	}
	free(f->map.altitudes);
}

int	main(int argc, char *argv[])
{
	t_fdf	f;

	if (argc != 2)
		return (1);
	if (ft_init(&f) != 0)
		return (1);
	ft_read(&f, argv[1]);
	ft_draw(&f);
	if (mlx_image_to_window(f.mlx, f.img, 0, 0) == -1)
		return (ft_errorimg(f.mlx, f.img));
	mlx_scroll_hook(f.mlx, &ft_scrollhook, &f);
	mlx_key_hook(f.mlx, &ft_keyhook, &f);
	ft_printf("y = A * sin(B * x + C) + D\n");
	ft_printf("1-4: modo A,B,D,D | Scroll: alterar | R: reset\n", 1);
	mlx_loop(f.mlx);
	mlx_terminate(f.mlx);
	ft_freemap(&f);
	return (0);
}
