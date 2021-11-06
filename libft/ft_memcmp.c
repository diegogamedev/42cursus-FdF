/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:04:32 by dienasci          #+#    #+#             */
/*   Updated: 2021/08/17 09:29:43 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void	*str1, void	*str2, size_t n)
{
	unsigned char	*aux1;
	unsigned char	*aux2;
	size_t			index;

	aux1 = (unsigned char *)str1;
	aux2 = (unsigned char *)str2;
	index = 0;
	if (aux1 == aux2)
		return (0);
	while (index < n)
	{
		if (aux1[index] != aux2[index])
			return (aux1[index] - aux2[index]);
		index++;
	}
	return (0);
}
