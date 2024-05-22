/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:08:34 by lsorg             #+#    #+#             */
/*   Updated: 2024/03/13 16:03:59 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nr, int fd)
{
	char		str[11];
	int			idx;
	long long	n;

	n = nr;
	idx = 10;
	str[10] = 0;
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	while (n)
	{
		str[--idx] = (n % 10) + '0';
		n /= 10;
	}
	write(fd, &str[idx], 10 - idx);
}
