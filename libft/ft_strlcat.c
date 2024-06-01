/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:18:48 by lsorg             #+#    #+#             */
/*   Updated: 2024/03/10 18:23:19 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_size_t	ft_strlcat(char *dst, const char *src, t_size_t dstsize)
{
	char	*d;
	char	*length;

	d = (char *)dst;
	while (*(d++) && dstsize)
		dstsize--;
	length = d;
	d--;
	while (*(d++))
		;
	return ((length - 1 - dst) + ft_strlcpy(d - 1, src, dstsize));
}
