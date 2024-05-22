/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:12:45 by lsorg             #+#    #+#             */
/*   Updated: 2024/03/10 19:39:45 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	h_strncmp(const char *s1, const char *s2, int len)
{
	while ((*s2) && (*s1 == *s2) && len--)
	{
		s1++;
		s2++;
	}
	if (!*s2)
		return (1);
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, t_size_t len)
{
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len--)
	{
		if (*haystack == *needle)
		{
			if (h_strncmp(haystack, needle, len + 1))
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
