/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 15:18:47 by dienasci          #+#    #+#             */
/*   Updated: 2021/11/06 22:47:57 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/key.h"

static void	params_translate(int keycode, t_mlx *mlx)
{
	if (keycode == W)
		mlx->params->trans_y += 2;
	if (keycode == S)
		mlx->params->trans_y -= 2;
	if (keycode == A)
		mlx->params->trans_x -= 2;
	if (keycode == D)
		mlx->params->trans_x += 2;
}

int key_events(int keycode, t_mlx *mlx)
{
	if (keycode == ESCAPE)
		free_mlx(mlx);
	if (keycode == W || keycode == S || keycode == A || keycode == D)
		params_translate(keycode, mlx);
	draw(mlx);
	return (0);
}
