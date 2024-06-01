/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:08:35 by lsorg             #+#    #+#             */
/*   Updated: 2024/03/12 15:45:56 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in(char *set, char c)
{
	while (*set)
	{
		if (c == *(set++))
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*src;
	char		*str;
	t_size_t	ssize;

	src = (char *)s1;
	ssize = ft_strlen(src);
	while (*src && is_in((char *)set, *src))
	{
		src++;
		ssize--;
	}
	while (*src && is_in((char *)set, src[ssize - 1]))
		ssize--;
	str = (char *)malloc(ssize + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, src, ssize);
	str[ssize] = 0;
	return (str);
}
