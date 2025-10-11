/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 01:20:59 by tlavared          #+#    #+#             */
/*   Updated: 2025/10/11 01:23:09 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

void	ft_free_map(t_fdf *f)
{
	int	i;

	i = 0;
	while (i < f->map.height)
	{
		free(f->map.altitudes[i]);
		free(f->map.colors[i]);
		i++;
	}
	free(f->map.altitudes);
	free(f->map.colors);
}
