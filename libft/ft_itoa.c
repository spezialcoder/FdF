/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:12:39 by lsorg             #+#    #+#             */
/*   Updated: 2024/03/12 18:01:29 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_length(int n)
{
	int	length;

	length = 0;
	while (n)
	{
		length++;
		n = n / 10;
	}
	return (length);
}

static void	norminette_complained(char *str, int len, int idx, long long n)
{
	while (len--)
	{
		str[idx--] = (n % 10) + '0';
		n = n / 10;
	}
}

char	*ft_itoa(int nr)
{
	char		*str;
	int			idx;
	int			length;
	long long	n;

	n = nr;
	idx = n_length(n);
	length = n_length(n);
	if (n <= 0)
		idx++;
	str = (char *)malloc(idx + 1);
	if (!str)
		return (NULL);
	str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[idx--] = 0;
	if (n == 0)
		return (str);
	norminette_complained(str, length, idx, n);
	return (str);
}
