/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:54:03 by lsorg             #+#    #+#             */
/*   Updated: 2024/03/12 14:52:27 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, t_size_t len)
{
	char		*ss;
	t_size_t	ssize;

	if (ft_strlen(s) > start)
	{
		if ((ft_strlen(s + start)) >= len)
			ssize = len;
		else
			ssize = ft_strlen(s + start);
		ss = malloc(ssize + 1);
		if (!ss)
			return (NULL);
		ss[0] = '\0';
		ft_strlcpy(ss, (s + start), ssize + 1);
	}
	else
	{
		ss = malloc(1);
		if (!ss)
			return (NULL);
		*ss = 0;
	}
	return (ss);
}
