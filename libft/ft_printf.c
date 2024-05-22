/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:19:22 by lsorg             #+#    #+#             */
/*   Updated: 2024/04/17 20:58:55 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	call_format(char fmt, va_list args)
{
	int	length;

	length = 0;
	if (fmt == 'c')
		return (pt_printchar(va_arg(args, int) & 0xFF));
	else if (fmt == 's')
		return (pt_printstr(va_arg(args, char *)));
	else if (fmt == 'd' || fmt == 'i')
		return (pt_printn(va_arg(args, int), &length, "0123456789",
				(struct s_flags){.b = 10, .u = 0, .p = 0}), length);
	else if (fmt == 'u')
		return (pt_printn(va_arg(args, int), &length, "0123456789",
				(struct s_flags){.b = 10, .u = 1, .p = 0}), length);
	else if (fmt == 'x')
		return (pt_printn(va_arg(args, int), &length, "0123456789abcdef",
				(struct s_flags){.b = 16, .u = 1, .p = 0}), length);
	else if (fmt == 'X')
		return (pt_printn(va_arg(args, int), &length, "0123456789ABCDEF",
				(struct s_flags){.b = 16, .u = 1, .p = 0}), length);
	else if (fmt == 'p')
		return (pt_printn(va_arg(args, unsigned long long), &length,
				"0123456789abcdef", (struct s_flags){.b = 16, .u = 1, .p = 1}),
			length);
	else
		return (write(1, "%", 1));
}

int	ft_printf(const char *format, ...)
{
	int		result;
	va_list	args;

	result = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			result += call_format(*(++format), args);
		}
		else
		{
			if (pt_printchar(*format) < 0)
				return (-1);
			result++;
		}
		format++;
	}
	va_end(args);
	return (result);
}
