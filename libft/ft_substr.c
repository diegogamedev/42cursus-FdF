/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:20:04 by dienasci          #+#    #+#             */
/*   Updated: 2021/10/05 12:46:43 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start > s_len)
		return ((char *)ft_calloc(1, sizeof(char)));
	if (s_len < len)
		len = s_len;
	if (s_len - start < len)
		len = s_len - start;
	cpy = malloc(len + 1);
	i = 0;
	if (!cpy)
		return (cpy);
	while (i < len && s[i])
		cpy[i++] = s[start++];
	cpy[i] = '\0';
	return (cpy);
}
