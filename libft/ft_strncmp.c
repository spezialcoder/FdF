/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:13:54 by lsorg             #+#    #+#             */
/*   Updated: 2024/03/10 19:38:52 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, t_size_t n)
{
	if (!n)
		return (0);
	while ((*s1 && *s2) && (*s1 == *s2) && --n > 0)
	{
		s1++;
		s2++;
	}
	if ((unsigned int)*s1 > (unsigned int)*s2)
		return (1);
	else if ((unsigned int)*s1 < (unsigned int)*s2)
		return (-1);
	return (0);
}
