/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:09:06 by dienasci          #+#    #+#             */
/*   Updated: 2021/11/03 21:28:25 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_mlx(t_mlx *mlx)
{
	free_map(mlx->map, mlx->map->length_z);
	mlx_destroy_image(mlx->mlx_ptr, mlx->i->img);
	free(mlx->i);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win);
	mlx_destroy_display(mlx->mlx_ptr);
	write(1, "FdF terminated, have a nice day!\n", 34);
	exit(0);
}

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
