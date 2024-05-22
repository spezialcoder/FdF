/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:09:05 by lsorg             #+#    #+#             */
/*   Updated: 2024/03/10 19:28:03 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_size_t	ft_strlcpy(char *dst, const char *src, t_size_t dstsize)
{
	char	*cptr;
	int		strlen;

	strlen = 0;
	cptr = (char *)src;
	while (cptr[strlen++])
		;
	while (*cptr && dstsize--)
	{
		if (dstsize > 0)
			*(dst++) = *(cptr++);
		else
			break ;
	}
	dstsize++;
	if (dstsize)
		*(dst) = 0;
	return (--strlen);
}
