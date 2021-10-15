/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:19:53 by dienasci          #+#    #+#             */
/*   Updated: 2021/10/05 12:46:43 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		b1;
	size_t		b2;
	size_t		l1;
	size_t		l2;

	if (*little == '\0')
		return ((char *)big);
	b1 = 0;
	l1 = 0;
	while (*(big + b1) && b1 < len)
	{
		b2 = b1;
		l2 = l1;
		while (*(little + l2) && *(big + b2) == *(little + l2) && b1 + l2 < len)
		{
			b2++;
			l2++;
		}
		if (*(little + l2) == '\0')
			return ((char *)(big + b1));
		b1++;
	}
	return (NULL);
}
