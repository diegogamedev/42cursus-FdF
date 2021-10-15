/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:25:05 by dienasci          #+#    #+#             */
/*   Updated: 2021/10/13 14:41:10 by dienasci         ###   ########.fr       */
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
# include "../includes/libft.h"
# include "../includes/libft.h"

//DATA STRUCTURES
typedef struct s_vector
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_vector;

typedef struct s_map
{
	t_vector	**coords;
	int			width_x;
	int			length_z;
	int			min_height_y;
	int			max_height_y;
}	t_map;

//MACROS
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

//FUNCTIONS
char		*remove_spaces(const char *str);
char		*get_next_line(int fd);
t_map		*init_map(t_list *prms);
void		add_vector(char *text, int x, int z, t_map *map);
t_list		*list_params(int fd);
t_list		*ft_lstnext(t_list *current);
int			ft_atoi_base(char *str, char *base);
t_vector	**init_coordinates(int width, int depth);
int			get_width(t_list *head);
void		remove_breakline(char *text);

#endif
