/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 19:01:02 by tlavared          #+#    #+#             */
/*   Updated: 2025/10/01 00:51:37 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

int	ft_hex_to_int(char *hex)
{
	uint32_t	value;
	int			i;
	char		c;

	value = 0;
	i = 0;
	if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X'))
		i = 2;
	while (hex[i])
	{
		c = hex[i];
		value *= 16;
		if (c >= '0' && c <= '9')
			value += c - '0';
		else if (c >= 'a' && c <= 'f')
			value += c - 'a' + 10;
		else if (c >= 'A' && c <= 'F')
			value += c - 'A' + 10;
		else
			break ;
		i++;
	}
	return (value);
}
