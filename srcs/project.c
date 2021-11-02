/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 14:35:05 by dienasci          #+#    #+#             */
/*   Updated: 2021/11/02 12:03:51 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_vec2	*get_projection(t_vec3 start, t_vec3 end)
{
	t_vec2	*screen;

	screen = malloc(sizeof(*screen) * 2);
	screen[0].x = (start.x - start.y) * cos(0.52359877);
	screen[0].y = (start.x + start.y) * sin(0.52359877) - start.z;
	screen[0].color = start.color;
	screen[1].x = (end.x - end.y) * cos(0.52359877);
	screen[1].y = (end.x + end.y) * sin(0.52359877) - end.z;
	screen[1].color = end.color;
	return (screen);
}
