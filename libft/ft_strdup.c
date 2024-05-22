/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:57:25 by lsorg             #+#    #+#             */
/*   Updated: 2024/03/12 13:50:15 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	void	*mem;

	mem = malloc(ft_strlen(s1) + 1);
	if (!mem)
		return (NULL);
	return (ft_memcpy(mem, s1, ft_strlen(s1) + 1));
}
