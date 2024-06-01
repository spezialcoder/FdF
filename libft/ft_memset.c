/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:19:24 by lsorg             #+#    #+#             */
/*   Updated: 2024/03/13 17:16:05 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, t_size_t len)
{
	unsigned char	*d;

	d = (unsigned char *)b;
	while (len--)
		*(d++) = (unsigned char)c;
	return (b);
}
