/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 12:17:24 by dienasci          #+#    #+#             */
/*   Updated: 2022/01/15 13:44:11 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	welcome_message()
{
	write(1, "/**************************************/\n", 42);
	write(1, "Fils de Fer by dienasci\n", 25);
	write(1, "/**************************************/\n", 42);
	write(1, "WASD -> Move the camera in X and Y\n", 36);
	write(1, "LShift/LCtrl -> Zoom (a.k.a translate in the z axis)\n", 54);
	write(1, "Q and E -> yaw\n", 16);
	write(1, "Up and Down -> pitch\n", 22);
	write(1, "Left and Right -> roll\n", 24);
	write(1, "Escape to exit\n\n\n", 18);
}

void	fdf_init(int fd)
{
	t_map	*map;
	t_list	*list;

	list_params(fd, &list);
	map = init_map(list);
	ft_lstclear(&list, free);
	if (!map)
		write(1, "Bad format or allocation error\n", 32);
	else
		init_mlx(map);
}

int	main(int argc, char **argv)
{
	int		fd;

	welcome_message();
	if (argc == 1)
		write(1, "Wrong usage: ./fdf [relative file path]", 40);
	else
	{
		if (!ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])))
			write(1, "Unexpected file", 16);
		else
		{
			fd = open(argv[1], O_RDONLY);
			if (fd <= 0)
				write(1, "Failed to open file", 20);
			else
				fdf_init(fd);
			close(fd);
		}
	}
	return (1);
}
