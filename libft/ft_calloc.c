/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:54:25 by lsorg             #+#    #+#             */
/*   Updated: 2024/03/12 13:50:35 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(t_size_t count, t_size_t size)
{
	void	*mem;

	mem = malloc(size * count);
	if (!mem)
		return (NULL);
	return (ft_memset(mem, 0, size * count));
}
