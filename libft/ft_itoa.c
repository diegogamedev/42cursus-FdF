/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:04:24 by dienasci          #+#    #+#             */
/*   Updated: 2021/10/05 12:46:43 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	count_decimal(int n)
{
	size_t	i;

	if (!n)
		return (1);
	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*result;
	long	ln;

	ln = n;
	n = 0;
	if (ln < 0)
	{
		ln = -ln;
		n = 1;
	}
	result = malloc(count_decimal(ln) + n + 1);
	i = count_decimal(ln) + n - 1;
	result[i + 1] = '\0';
	if (n)
		result[0] = '-';
	if (!ln)
		result[i] = '0';
	while (ln && result)
	{
		result[i] = (ln % 10) + '0';
		ln /= 10;
		i--;
	}
	return (result);
}
