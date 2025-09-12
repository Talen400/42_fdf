/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:05:04 by tlavared          #+#    #+#             */
/*   Updated: 2025/09/09 00:49:57 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	c_chr;
	char			*str;

	if (!s)
		return (NULL);
	str = (char *) s;
	c_chr = (unsigned char) c;
	while (*str)
	{
		if ((unsigned char ) *str == c_chr)
			return (str);
		str++;
	}
	if (c_chr == '\0')
		return (str);
	return ((void *) 0);
}
