/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 23:08:58 by tlavared          #+#    #+#             */
/*   Updated: 2025/10/01 00:52:14 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

float	ft_degree_to_radian(int degree)
{
	float	radian;

	radian = (M_PI / 180.0f) * degree;
	return (radian);
}
