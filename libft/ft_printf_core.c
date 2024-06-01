/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_core.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:20:34 by lsorg             #+#    #+#             */
/*   Updated: 2024/04/17 20:59:00 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pt_printchar(char c)
{
	return (write(1, &c, 1));
}

int	pt_printstr(char *s)
{
	int	length;

	length = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*s)
	{
		length++;
		write(1, s++, 1);
	}
	return (length);
}

static void	h_printn(unsigned long long n, int *len, char *charset, int b)
{
	if (n)
		h_printn(n / b, len, charset, b);
	else
		return ;
	(*len)++;
	pt_printchar(*(charset + (n % b)));
}

void	pt_printn(unsigned long long n, int *len, char *charset,
		struct s_flags flags)
{
	if ((long long)n < 0 && !flags.u)
	{
		write(1, "-", 1);
		n = -n;
		(*len)++;
	}
	if (!flags.p)
		n &= 0xFFFFFFFF;
	else
	{
		write(1, "0x", 2);
		(*len) += 2;
	}
	if (!n)
	{
		write(1, "0", 1);
		(*len)++;
		return ;
	}
	h_printn(n, len, charset, flags.b);
}
