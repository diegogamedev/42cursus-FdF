/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:13:00 by dienasci          #+#    #+#             */
/*   Updated: 2021/11/06 20:34:24 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_list	*ft_lstnext(t_list *current)
{
	t_list	*temp;

	temp = current->next;
	return (temp);
}

int	get_width(t_list *head)
{
	int		width;
	int		temp;
	int		index;
	char	*a;

	index = ft_lstsize(head);
	width = 0;
	while (index)
	{
		a = (char *)head->content;
		temp = count_words(a, ' ');
		if (temp > width)
			width = temp;
		head = ft_lstnext(head);
		index--;
	}
	return (width);
}

t_vec3	**init_coordinates(int width, int height)
{
	t_vec3	**coordinates;
	int		i;
	int		j;

	coordinates = malloc(width * sizeof(t_vec3 *));
	if (!coordinates)
		return (NULL);
	i = 0;
	while (i < width)
	{
		coordinates[i] = malloc(height * sizeof(t_vec3));
		if (!coordinates[i])
			return (NULL);
		j = 0;
		while (j < height)
		{
			coordinates[i][j].x = 0;
			coordinates[i][j].y = 0;
			coordinates[i][j].z = 0;
			coordinates[i][j].color = 0;
			j++;
		}
		i++;
	}
	return (coordinates);
}

void	remove_breakline(char *text)
{
	int	index;

	index = ft_strlen(text);
	if (text[index - 1] == '\n')
		text[index - 1] = '\0';
}

void	free_2d_array(char **split)
{
	int	index;

	index = 0;
	while (split[index])
	{
		free(split[index]);
		index++;
	}
	free(split);
}
