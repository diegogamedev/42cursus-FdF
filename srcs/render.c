/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:48:57 by dienasci          #+#    #+#             */
/*   Updated: 2021/10/24 11:58:07 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void	put_pixel_in_image(t_data *i, t_vec2 v)
{
	char	*dst;

	dst = i->addr + (v.y * i->line_length + v.x * (i->bits_per_pixel / 8));
	if(v.color == -1)
		*(unsigned int *)dst = create_trgb(0,255,0,0);
	else
		*(unsigned int *)dst = v.color;
}

void	bresenham(t_vec2 start, t_vec2 end, t_data *img)
{
	int		m_new;
	int		slope_error;
	t_vec2	p;

	m_new = 2 * (end.y - start.y);
	slope_error = m_new - (end.x - start.x);
	p.x = start.x;
	p.y = start.y;
	p.color = start.color;
	while (p.x <= end.x)
	{
		put_pixel_in_image(img, p);
		slope_error += m_new;
		if (slope_error >= 0)
		{
			p.y++;
			slope_error -= 2 * (end.x - start.x);
		}
	}
}

void	render(t_data *img, t_vec3 start, t_vec3 end)
{
	t_vec2	*temp;

	temp = get_projection(start, end);
	bresenham(temp[0], temp[1], img);
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
				render(&data->img, data->map->coords[x][z], \
				data->map->coords[x + 1][z]);
			if (z < data->map->length_z - 1)
				render(&data->img, data->map->coords[x][z], \
				data->map->coords[x][z + 1]);
			x++;
		}
		z++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win, data->img.img, 0, 0);
	return (1);
}

void	init_mlx(t_map *map)
{
	t_mlx	data;

	data.mlx_ptr = mlx_init();
	data.win = mlx_new_window(data.mlx_ptr, 640, 480, "fdf");
	data.win_x = 640;
	data.win_y = 480;
	data.img.img = mlx_new_image(data.mlx_ptr, 640, 480);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, \
			&data.img.line_length, &data.img.endian);
	data.map = map;
	draw(&data);
	mlx_expose_hook(data.win, draw, &data);
	mlx_loop(data.mlx_ptr);
}
