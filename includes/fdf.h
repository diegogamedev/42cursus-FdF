/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:25:05 by dienasci          #+#    #+#             */
/*   Updated: 2021/11/02 14:42:44 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

//LIBS
# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <mlx.h>
# include "../includes/libft.h"

//DATA STRUCTURES
typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
	int		color;
}	t_vec3;

typedef struct s_vec2
{
	double	x;
	double	y;
	int		color;
}	t_vec2;

typedef struct s_map
{
	t_vec3		**coords;
	int			width_x;
	int			length_z;
	int			min_height_y;
	int			max_height_y;
}	t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
	int		win_x;
	int		win_y;
	t_data	*img;
	t_map	*map;
}	t_mlx;

//MACROS
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# ifndef M_PI
#  define M_PI (3.14159265358979323846)
# endif

//FUNCTIONS
char		*remove_spaces(const char *str);
char		*get_next_line(int fd);
t_map		*init_map(t_list *prms);
void		init_mlx(t_map *map);
void		add_vector(char *text, int x, int z, t_map *map);
t_list		*list_params(int fd);
t_list		*ft_lstnext(t_list *current);
int			ft_atoi_base(char *str, char *base);
t_vec3		**init_coordinates(int width, int depth);
int			get_width(t_list *head);
void		remove_breakline(char *text);
void		put_pixel_in_image(t_data *i, t_vec2 v);
int			create_trgb(int t, int r, int g, int b);
t_vec2		*get_projection(t_vec3 start, t_vec3 end);
float		absolute(float nbr);
float		max(float a, float b);
float		min(float a, float b);
void		scale(t_mlx *mlx_data, t_vec2 *start, t_vec2 *end);
void		translate(t_vec2 *s, t_vec2 *e, float mv_x, float mv_y);
void		rotate_x(t_vec3 *start, t_vec3 *end, double rad_ang);
void		rotate_y(t_vec3 *start, t_vec3 *end, double rad_ang);
void		rotate_z(t_vec3 *start, t_vec3 *end, double rad_ang);
void		free_map(t_map *map, int height);
void		free_mlx(t_mlx *mlx);
int			key_events(int keycode, t_mlx *mlx);
int			lerp_color(int clr_a, int clr_b, float f);

#endif
