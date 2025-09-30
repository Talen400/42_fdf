/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_axis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 02:48:23 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/30 02:38:10 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	ft_draw_colored_line(t_fdf *f, t_vec2 start, t_vec2 end,
	uint32_t color)
{
	t_vec2	line_start;
	t_vec2	line_end;

	line_start.x = (int)(start.x + 0.5f);
	line_start.y = (int)(start.y + 0.5f);
	line_start.color = color;
	line_end.x = (int)(end.x + 0.5f);
	line_end.y = (int)(end.y + 0.5f);
	line_end.color = color;
	if (line_start.x == line_end.x && line_start.y == line_end.y)
		return ;
	ft_bresenham(f, line_start, line_end);
}

static t_vec2	ft_project_axis(t_vec3 axis, int origin_x, int origin_y,
	int length)
{
	t_vec2	result;
	double	cos_val;
	double	sin_val;

	cos_val = 0.866025403784;
	sin_val = 0.5;
	result.x = (axis.x - axis.y) * cos_val * length + origin_x;
	result.y = (axis.x + axis.y) * sin_val * length - axis.z * length
		+ origin_y;
	return (result);
}

static void	ft_draw_arrow_tips(t_fdf *f, t_vec2 end, double angle,
	uint32_t color)
{
	t_vec2	arrow_tip1;
	t_vec2	arrow_tip2;
	double	arrow_angle1;
	double	arrow_angle2;
	int		arrow_length;

	arrow_length = AXIS_LENGHT / 8;
	arrow_angle1 = angle + 2.35619449019;
	arrow_tip1.x = end.x + arrow_length * cos(arrow_angle1);
	arrow_tip1.y = end.y + arrow_length * sin(arrow_angle1);
	arrow_angle2 = angle - 2.35619449019;
	arrow_tip2.x = end.x + arrow_length * cos(arrow_angle2);
	arrow_tip2.y = end.y + arrow_length * sin(arrow_angle2);
	ft_draw_colored_line(f, end, arrow_tip1, color);
	ft_draw_colored_line(f, end, arrow_tip2, color);
}

static void	ft_draw_arrow(t_fdf *f, t_vec2 origin, t_vec2 end, uint32_t color)
{
	double	angle;

	ft_draw_colored_line(f, origin, end, color);
	angle = atan2(end.y - origin.y, end.x - origin.x);
	ft_draw_arrow_tips(f, end, angle, color);
}

void	ft_draw_orientation_arrows(t_fdf *f)
{
	t_vec3	axis[3];
	t_vec2	origin;
	t_vec2	end[3];
	int		arrow_length;

	arrow_length = AXIS_LENGHT;
	ft_init_axis_vectors(&axis[0], &axis[1], &axis[2]);
	ft_setup_origin(&origin);
	axis[0] = ft_rotate_axis_vector(f, axis[0]);
	axis[1] = ft_rotate_axis_vector(f, axis[1]);
	axis[2] = ft_rotate_axis_vector(f, axis[2]);
	end[0] = ft_project_axis(axis[0], origin.x, origin.y, arrow_length);
	end[1] = ft_project_axis(axis[1], origin.x, origin.y, arrow_length);
	end[2] = ft_project_axis(axis[2], origin.x, origin.y, arrow_length);
	ft_draw_arrow(f, origin, end[0], 0x0000FFFF);
	ft_draw_arrow(f, origin, end[1], 0x00FF00FF);
	ft_draw_arrow(f, origin, end[2], 0xFF0000FF);
}
