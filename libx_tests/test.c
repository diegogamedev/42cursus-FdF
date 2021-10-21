//This is a bit of an ugly script, but is a test of concept

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
	int		win_x;
	int		win_y;
	t_data	img;
} t_mlx;

typedef struct s_vec
{
	int	x;
	int	y;
	int	z;
} vec3_t;

vec3_t Subtract(vec3_t src, vec3_t dst)
{
	vec3_t diff;
	diff.x = src.x - dst.x;
	diff.y = src.y - dst.y;
	diff.z = src.z - dst.z;
	return diff;
}

int DotProduct(vec3_t src, vec3_t dst)
{
	return src.x * dst.x + src.y * dst.y + src.z * dst.z;
}

int create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	bresenham_draw_3d_line(int x1, int y1, int z1, int x2, int y2, int z2, t_data *data)
{
	int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
	int dy = abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
	int dz = abs(z2 - z1), sz = z1 < z2 ? 1 : -1;
	int p1 = 0, p2 = 0;

	if (dx >= dy && dx >= dz)
	{
		p1 = 2 *dy - dx;
		p2 = 2 * dz - dx;
		while (x1 != x2)
		{
			x1 += sx;
			if (p1 >= 0)
			{
				y1 += sy;
				p1 -= 2 * dx;
			}
			if (p2 >= 0)
			{
				z1 += sz;
				p2 -= 2 * dx;
			}
			p1 += 2 *dy;
			p2 += 2 * dz;
			my_mlx_pixel_put(data, x1, y1, create_trgb(0,255,0,0));
		}
	}
	else if (dy >= dx && dy >= dz)
	{
		p1 = 2 * dx - dy;
		p2 = 2 * dz - dy;
		while (y1 != y2)
		{
			y1 += sy;
			if (p1 >= 0)
			{
				x1 += sy;
				p1 -= 2 * dy;
			}
			if (p2 >= 0)
			{
				z1 += sz;
				p2 -= 2 * dy;
			}
			p1 += 2 * dx;
			p2 += 2 * dz;
			my_mlx_pixel_put(data, x1, y1, create_trgb(0, 255, 0, 0));
		}
	}
	else
	{
		p1 = 2 * dy - dz;
		p2 = 2 * dx - dz;
		while (z1 != z2)
		{
			z1 += sz;
			if (p1 >= 0)
			{
				y1 += sy;
				p1 -= 2 * dz;
			}
			if (p2 >= 0)
			{
				x1 += sx;
				p2 -= 2 * dz;
			}
			p1 += 2 * dx;
			p2 += 2 * dz;
			my_mlx_pixel_put(data, x1, y1, create_trgb(0, 255, 0, 0));
		}
	}
}

int draw(t_mlx *data)
{
	bresenham_draw_3d_line(20, 20, 20, 50, 20, 50, &data->img);
	bresenham_draw_3d_line(50, 20, 20, 50, 50, 50, &data->img);
	bresenham_draw_3d_line(50, 50, 20, 20, 50, 50, &data->img);
	bresenham_draw_3d_line(20, 50, 20, 20, 20, 50, &data->img);
	mlx_put_image_to_window(data->mlx_ptr, data->win, data->img.img, 0, 0);
	return (0);
}

int main(void)
{
	t_mlx data;

	data.mlx_ptr = mlx_init();
	data.win = mlx_new_window(data.mlx_ptr, 640, 480, "Hello world!");
	data.win_x = 640;
	data.win_y = 480;
	data.img.img = mlx_new_image(data.mlx_ptr, 640, 480);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);
	draw(&data);
	mlx_expose_hook(data.win, draw, &data);
	mlx_loop(data.mlx_ptr);
}
