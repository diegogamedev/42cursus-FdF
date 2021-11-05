/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:48:57 by dienasci          #+#    #+#             */
/*   Updated: 2021/11/05 20:45:15 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void	put_pixel_in_image(t_data *i, t_vec2 v)
{
	char	*dst;

	dst = i->addr + ((int)v.y * i->len + (int)v.x * (i->bpp / 8));
	*(unsigned int *)dst = v.color;
}

void	bresenham(t_vec2 start, t_vec2 end, t_mlx *mlx)
{
	float	x_step;
	float	y_step;
	int		max_steps;
	int		i_line;
	int		t_color;

	x_step = end.x - start.x;
	y_step = end.y - start.y;
	max_steps = (int)max(absolute(x_step), absolute(y_step));
	x_step /= max_steps;
	y_step /= max_steps;
	i_line = 0;
	t_color = start.color;
	while (i_line < max_steps)
	{
		i_line++;
		start.color = lerp_color(t_color, end.color, i_line / max_steps);
		if (start.x >= 0 && start.y >= 0 && start.x < mlx->win_x \
		&& start.y < mlx->win_y)
			put_pixel_in_image(mlx->i, start);
		start.x += x_step;
		start.y += y_step;
	}
}

void	render(t_mlx *mlx, t_vec3 start, t_vec3 end)
{
	t_vec2	*temp;

	rotate_x(&start, &end, 0 * M_PI / 180);
	rotate_y(&start, &end, 0 * M_PI / 180);
	rotate_z(&start, &end, 0 * M_PI / 180);
	temp = get_projection(start, end);
	scale(mlx, &temp[0], &temp[1]);
	translate(&temp[0], &temp[1], mlx->win_x / 2, mlx->win_y / 2);
	bresenham(temp[0], temp[1], mlx);
	free(temp);
}

int	draw(t_mlx *data)
{
	int	x;
	int	z;

	z = 0;
	while (z < data->map->length_z)
	{
		x = 0;
		while (x < data->map->width_x)
		{
			if (x < data->map->width_x - 1)
				render(data, data->map->coords[x][z], \
				data->map->coords[x + 1][z]);
			if (z < data->map->length_z - 1)
				render(data, data->map->coords[x][z], \
				data->map->coords[x][z + 1]);
			x++;
		}
		z++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win, data->i->img, 0, 0);
	return (1);
}

void	init_mlx(t_map *map)
{
	t_mlx	a;

	a.mlx_ptr = mlx_init();
	a.win = mlx_new_window(a.mlx_ptr, 1024, 720, "fdf");
	a.win_x = 1024;
	a.win_y = 720;
	a.i = malloc(sizeof(*a.i));
	a.i->img = mlx_new_image(a.mlx_ptr, 1024, 720);
	a.i->addr = mlx_get_data_addr(a.i->img, &a.i->bpp, &a.i->len, &a.i->end);
	a.map = map;
	draw(&a);
	mlx_expose_hook(a.win, draw, &a);
	mlx_key_hook(a.win, key_events, &a);
	mlx_loop(a.mlx_ptr);
}
