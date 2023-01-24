/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:08:06 by mdorr             #+#    #+#             */
/*   Updated: 2023/01/24 19:11:35 by mdorr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parsing(char *map_file)
{
	int fd;

	fd = open(map_file, O_RDONLY);
	while (get_next_line(fd))
	{
		
	}
}

int	check_arg(int argc, char **argv)
{
	char *particule;

	printf("argc is %d\n", argc);
	if (argc != 2)
		return (1);
	particule = cpy_part(particule, argv[1]);
	if (ft_strcmp(".ber", particule) != 0)
		return (1);
	if (parsing(argv[1]) == 1)
		return (1);
	return (0);
}
