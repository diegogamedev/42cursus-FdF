/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 20:58:57 by dienasci          #+#    #+#             */
/*   Updated: 2021/11/06 22:54:47 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void	*s, size_t n)
{
	char	*c;
	size_t	index;

	c = s;
	index = 0;
	while (index < n)
	{
		c[index] = 0;
		index++;
	}
}
