/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:49:06 by dienasci          #+#    #+#             */
/*   Updated: 2021/11/05 20:45:29 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void	scale(t_mlx *mlx_data, t_vec2 *start, t_vec2 *end)
{
	float	x;
	float	y;
	float	factor;

	x = mlx_data->win_x / mlx_data->map->width_x;
	y = mlx_data->win_y / mlx_data->map->max_height_y;
	factor = min(x, y);
	if(factor < 4)
		factor = 1.5;
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

void	rotate_x(t_vec3 *start, t_vec3 *end, double rad_ang)
{
	float	a;
	float	b;

	a = start->z * cos(rad_ang) - start->y * sin(rad_ang);
	b = start->z * sin(rad_ang) + start->y * cos(rad_ang);
	start->y = a;
	start->z = b;
	a = end->z * cos(rad_ang) - end->y * sin(rad_ang);
	b = end->z * sin(rad_ang) + end->y * cos(rad_ang);
	end->y = a;
	end->z = b;
}

void	rotate_y(t_vec3 *start, t_vec3 *end, double rad_ang)
{
	float	a;
	float	b;

	a = start->x * cos(rad_ang) + start->z * sin(rad_ang);
	b = start->x * sin(rad_ang) + start->z * cos(rad_ang);
	start->x = a;
	start->z = b;
	a = end->x * cos(rad_ang) + end->z * sin(rad_ang);
	b = end->x * sin(rad_ang) + end->z * cos(rad_ang);
	end->x = a;
	end->z = b;
}

void	rotate_z(t_vec3 *start, t_vec3 *end, double rad_ang)
{
	float	a;
	float	b;

	a = start->x * cos(rad_ang) - start->y * sin(rad_ang);
	b = start->x * sin(rad_ang) + start->y * cos(rad_ang);
	start->x = a;
	start->y = b;
	a = end->x * cos(rad_ang) - end->y * sin(rad_ang);
	b = end->x * sin(rad_ang) + end->y * cos(rad_ang);
	end->x = a;
	end->y = b;
}
