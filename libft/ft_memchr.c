/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:11:49 by lsorg             #+#    #+#             */
/*   Updated: 2024/03/10 19:33:41 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, t_size_t n)
{
	char	*cp;

	cp = (char *)s;
	while (n--)
	{
		if (*cp == (char)c)
			return ((void *)cp);
		cp++;
	}
	return (NULL);
}
