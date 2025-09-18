/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 23:46:51 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/18 02:39:11 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	ft_free_split(char **split)
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

static void	ft_count(t_fdf *f, int fd)
{
	char	*line;
	char	**values;
	int		x;

	line = get_next_line(fd);
	while (1)
	{
		if (!line)
			break ;
		if (ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		values = ft_split(line, ' ');
		x = 0;
		while (values[x])
			x++;
		if (x > f->map.width)
			f->map.width = x;
		f->map.height++;
		free(line);
		ft_free_split(values);
		line = get_next_line(fd);
	}
}

static void	ft_alloc(t_fdf	*f)
{
	int	i;

	f->map.altitudes = (int **) malloc(sizeof(int *) * f->map.height);
	i = 0;
	while (i < f->map.height)
	{
		f->map.altitudes[i] = (int *) malloc(sizeof(int) * f->map.width);
		i++;
	}
	f->map.colors = (int **) malloc(sizeof(int *) * f->map.height);
	i = 0;
	while (i < f->map.height)
	{
		f->map.colors[i] = (int *) malloc(sizeof(int) * f->map.width);
		i++;
	}
}

static void	ft_process_cell(t_fdf *f, char *cell_str, int x, int y)
{
	char	**parts;

	parts = ft_split(cell_str, ',');
	if (!parts)
		return ;
	f->map.altitudes[y][x] = ft_atoi(parts[0]);
	if (parts[1])
	{
		f->map.colors[y][x] = ft_hex_to_int(parts[1]);
	}
	else
	{
		f->map.colors[x][y] = -1;
	}
	ft_free_split(parts);
}

static void	ft_reading(t_fdf *f, int fd)
{
	int		x;
	int		y;
	char	*line;
	char	**values;

	y = 0;
	line = get_next_line(fd);
	while (line != NULL && y < f->map.height)
	{
		if (ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		values = ft_split(line, ' ');
		x = 0;
		while (values[x] && x < f->map.width)
		{
			ft_process_cell(f, values[x], x, y);
			x++;
		}
		y++;
		free(line);
		ft_free_split(values);
		line = get_next_line(fd);
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
	ft_alloc(f);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return ;
	ft_reading(f, fd);
	close(fd);
	ft_printf("Map(%d, %d)\n", f->map.width, f->map.height);
}
