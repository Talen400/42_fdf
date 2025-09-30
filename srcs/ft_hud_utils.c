/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hud_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 23:32:49 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/30 18:05:46 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/*
 * PARSE FLOAT
 *
 */
static char	*ft_ftoa(float num)
{
	char	*int_part;
	char	*dec_part;
	char	*temp;
	char	*result;
	int		decimal;

	int_part = ft_itoa((int ) num);
	if (!int_part)
		return (NULL);
	decimal = (int)((num - (int)num) * 100);
	if (decimal < 0)
		decimal = -decimal;
	dec_part = ft_itoa(decimal);
	if (!dec_part)
		return (free(int_part), NULL);
	temp = ft_strjoin(int_part, ".");
	if (!temp)
		return (free(int_part), free(dec_part), NULL);
	result = ft_strjoin(temp, dec_part);
	return (free(int_part), free(dec_part), free(temp), result);
}

char	*ft_create_label_float(const char *prefix, float value)
{
	char	*str;
	char	*joined;

	str = ft_ftoa(value);
	if (!str)
		return (NULL);
	joined = ft_strjoin(prefix, str);
	free(str);
	return (joined);
}

char	*ft_create_label(const char *prefix, int value)
{
	char	*str;
	char	*joined;

	str = ft_itoa(value);
	if (!str)
		return (NULL);
	joined = ft_strjoin(prefix, str);
	free(str);
	return (joined);
}

void	ft_clear_img(t_fdf *f, mlx_image_t **img)
{
	if (*img)
	{
		mlx_delete_image(f->mlx, *img);
		*img = NULL;
	}
}

char	*ft_get_projection_name(t_projection proj)
{
	if (proj == PROJ_ISO)
		return ("ISOMETRIC");
	else if (proj == PROJ_ORTHO)
		return ("ORTO");
	else if (proj == PROJ_PERSPECTIVE)
		return ("PERSPECTIVE(CONIC)");
	else if (proj == PROJ_POLAR)
		return ("POLAR");
	else if (proj == PROJ_CILINDRIC)
		return ("CILINDRIC (z focal)");
	return ("UNKNOW");
}
