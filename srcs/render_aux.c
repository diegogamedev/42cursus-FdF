/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:49:06 by dienasci          #+#    #+#             */
/*   Updated: 2021/10/21 13:56:53 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

t_vector	subtract(t_vector src, t_vector dst)
{
	t_vector	diff;

	diff.x = src.x - dst.x;
	diff.y = src.y - dst.y;
	diff.z = src.z - dst.z;
	return (diff);
}

float	dot_product(t_vector src, t_vector dst)
{
	return (src.x * dst.x + src.y * dst.y + src.z * dst.z);
}

t_vector	divide(t_vector src, float num)
{
	t_vector	vec;

	vec.x = src.x / num;
	vec.y = src.y / num;
	vec.z = src.z / num;
	return (vec);
}

float	magnitude(t_vector vec)
{
	return (sqrtf(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}
