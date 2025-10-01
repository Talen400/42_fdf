/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 00:25:38 by tlavared          #+#    #+#             */
/*   Updated: 2025/10/01 00:51:22 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

t_color	ft_init_color(uint32_t color)
{
	t_color	result;

	result.r = (color >> 24) & 0xFF;
	result.g = (color >> 16) & 0xFF;
	result.b = (color >> 8) & 0xFF;
	result.a = color & 0xFF;
	return (result);
}

uint32_t	ft_color_to_int32(t_color color)
{
	return ((color.r << 24) | (color.g << 16) | (color.b << 8) | color.a);
}

uint32_t	ft_interpolate(uint32_t start, uint32_t end, float ratio)
{
	t_color	color_start;
	t_color	color_end;
	t_color	result;

	color_start = ft_init_color(start);
	color_end = ft_init_color(end);
	result.r = color_start.r + (color_end.r - color_start.r) * ratio;
	result.g = color_start.g + (color_end.g - color_start.g) * ratio;
	result.b = color_start.b + (color_end.b - color_start.b) * ratio;
	result.a = 0xFF;
	return (ft_color_to_int32(result));
}
