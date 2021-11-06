/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:16:10 by dienasci          #+#    #+#             */
/*   Updated: 2021/08/17 09:29:56 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	s1_size;
	size_t	s2_size;

	if (s1 && s2)
	{
		s1_size = ft_strlen(s1);
		s2_size = ft_strlen(s2);
		ret = (char *)ft_calloc(s1_size + s2_size + 1, sizeof(char));
		if (!ret)
			return (NULL);
		ft_strlcpy(ret, s1, s1_size + 1);
		ft_strlcpy(&ret[s1_size], s2, s2_size + 1);
		return (ret);
	}
	return (NULL);
}
