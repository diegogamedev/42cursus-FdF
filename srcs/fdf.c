/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 12:17:24 by dienasci          #+#    #+#             */
/*   Updated: 2021/10/23 12:43:47 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void	free_map(t_map *map, int height)
{
	while (height)
	{
		free(map->coords[height]);
		height--;
	}
	free(map->coords);
	free(map);
}

void	fdf_init(int fd)
{
	t_map	*map;

	map = init_map(list_params(fd));
	if (!map)
		write(1, "Bad format or allocation error\n", 32);
	else
	{
		init_mlx(map);
		free_map(map, map->length_z);
	}
}

int	main(int argc, char **argv)
{
	int		fd;

	if (argc == 1)
		write(1, "Wrong usage: ./fdf [relative file path]", 40);
	else
	{
		if (!ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])))
			write(1, "Unexpected file", 16);
		else
		{
			fd = open(argv[1], O_RDONLY);
			if (fd <= 0)
				write(1, "Failed to open file", 20);
			else
				fdf_init(fd);
		}
	}
	close(fd);
	return (1);
}
