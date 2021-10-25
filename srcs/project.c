/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 14:35:05 by dienasci          #+#    #+#             */
/*   Updated: 2021/10/25 14:02:32 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_vec2	*get_projection(t_vec3 start, t_vec3 end)
{
	t_vec2	*screen;

	screen = malloc(sizeof(*screen) * 2);
	screen[0].x = (start.x - start.z) * cos(0.52359877);
	screen[0].y = (start.x + start.z) * sin(0.52359877) - start.y;
	screen[0].color = start.color;
	screen[1].x = (end.x - end.z) * cos(0.52359877);
	screen[1].y = (end.x + end.z) * sin(0.52359877) - end.y;
	screen[1].color = end.color;
	return (screen);
}
