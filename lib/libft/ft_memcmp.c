/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:30:11 by lsorg             #+#    #+#             */
/*   Updated: 2024/03/09 20:08:34 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, t_size_t n)
{
	if (!n)
		return (0);
	while ((*((unsigned char *)(s1++)) == *((unsigned char *)(s2++))) && --n)
		;
	return (*((unsigned char *)--s1) - *((unsigned char *)--s2));
}
