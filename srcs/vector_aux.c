/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:49:06 by dienasci          #+#    #+#             */
/*   Updated: 2021/10/25 13:36:43 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	scale(t_mlx *mlx_data, t_vec2 *start, t_vec2 *end)
{
	float	x;
	float	y;
	float	factor;

	x = mlx_data->win_x / mlx_data->map->width_x;
	y = mlx_data->win_y / mlx_data->map->length_z;
	factor = min(x, y);
	if (factor < 4)
		factor = 2;
	else
		factor /= 2;
	start->x *= factor;
	start->y *= factor;
	end->x *= factor;
	end->y *= factor;
}

void	translate(t_vec2 *s, t_vec2 *e, float mv_x, float mv_y)
{
	s->x += mv_x;
	s->y += mv_y;
	e->x += mv_x;
	e->y += mv_y;
}
