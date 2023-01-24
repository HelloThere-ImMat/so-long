/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:55:30 by mdorr             #+#    #+#             */
/*   Updated: 2023/01/24 18:57:59 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char *cpy_part(char *dest, char *src)
{
	int	i;
	int	dot_pos;

	dest = malloc(sizeof(char) * 4);
	i = ft_strlen(src);
	dot_pos = i - 1 - 3;
	i = 0;
	while (src[i + dot_pos])
	{
		dest[i] = src[i + dot_pos];
		i++;
	}
	return (dest);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	e;

	e = 0;
	while (s1[e] != '\0' && s2[e] != '\0')
	{
		if (s1[e] != s2[e])
		{
			return (s1[e] - s2[e]);
		}
		e++;
	}
	return (s1[e] - s2[e]);
}