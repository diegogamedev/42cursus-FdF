/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:25:05 by dienasci          #+#    #+#             */
/*   Updated: 2021/10/23 15:01:08 by dienasci         ###   ########.fr       */
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
	int	x;
	int	y;
	int	z;
	int	color;
}	t_vec3;

typedef struct s_vec2
{
	int x;
	int y;
	int color;
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
} t_data;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
	int		win_x;
	int		win_y;
	t_data	img;
	t_map	*map;
} t_mlx;

//MACROS
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
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
t_vec3		subtract(t_vec3 src, t_vec3 dst);
float		dot_product(t_vec3 src, t_vec3 dst);
t_vec3		divide(t_vec3 src, float num);
float		magnitude(t_vec3 vec);
t_vec2		*get_projection(t_vec3 start, t_vec3 end);

#endif
