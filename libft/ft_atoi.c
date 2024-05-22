/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:17:25 by lsorg             #+#    #+#             */
/*   Updated: 2024/03/13 14:13:54 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				output;
	unsigned char	negativ;

	output = 0;
	negativ = 0;
	while (*str == '-' || *str == '0' || *str == '\t' || *str == '\n'
		|| *str == '\r' || *str == '\v' || *str == '\f' || *str == ' '
		|| *str == '+')
	{
		if (*str == '+' && !ft_isdigit(*(str + 1)))
			return (0);
		if (ft_isdigit(*str))
			break ;
		if (negativ)
			return (0);
		else if (*(str++) == '-' && !negativ)
			negativ = 1;
	}
	while (ft_isdigit(*str))
	{
		output *= 10;
		output += *(str++) - '0';
	}
	return (output * (-1 + 2 * !negativ));
}
