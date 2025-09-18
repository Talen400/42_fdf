/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 19:01:02 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/18 19:07:30 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int			ft_hex_to_int(char *hex)
{
	int	value;
	int	i;

	value = 0;
	if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X'))
		i = 2;
	else
		i = 0;
	while (hex[i])
	{
		value *= 16;
		if (hex[i] >= '0' && hex[i] <= '9')
			value += hex[i] - '0';
		else if (hex[i] >= 'a' && hex[i] <= 'f')
			value += hex[i] - 'a' + 10;
		else if (hex[i] >= 'A' && hex[i] <= 'F')
			value += hex[i] - 'A' + 10;
		i++;
	}
	return (value);
}
