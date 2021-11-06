/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:04:28 by dienasci          #+#    #+#             */
/*   Updated: 2021/08/17 09:29:42 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void	*str, int c, size_t n)
{
	unsigned char	*aux;

	aux = (unsigned char *)str;
	while (n--)
	{
		if (*aux != (unsigned char)c)
			aux++;
		else
			return (aux);
	}
	return (NULL);
}
