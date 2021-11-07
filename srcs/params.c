/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 22:02:42 by dienasci          #+#    #+#             */
/*   Updated: 2021/11/07 11:30:45 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float	factor_fit_screen(t_mlx *mlx)
{
	float	x;
	float	y;
	float	factor;

	x = mlx->win_x / mlx->map->width_x;
	y = mlx->win_y / mlx->map->max_height_y;
	factor = min(x, y);
	if (factor < 4)
		factor = 2;
	else
		factor /= 2;
	return (factor);
}

void	init_params(t_mlx *mlx)
{
	mlx->params->projection = 0;
	mlx->params->roll = 0 * DEG_2_RAD;
	mlx->params->pitch = 0 * DEG_2_RAD;
	mlx->params->yaw = 0 * DEG_2_RAD;
	mlx->params->scale_factor = factor_fit_screen(mlx);
	mlx->params->trans_x = mlx->win_x / 2;
	mlx->params->trans_y = mlx->win_y / 2;
}
