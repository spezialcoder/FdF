/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:53:08 by lsorg             #+#    #+#             */
/*   Updated: 2024/03/12 17:11:15 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	h_strlen(const char *s, char term)
{
	int	ssize;

	ssize = 0;
	while (*s && *(s++) != term)
		ssize++;
	return (ssize);
}

static int	h_count_words(const char *s, char delim)
{
	int	words;

	words = 0;
	while (*s)
	{
		if (h_strlen(s, delim))
		{
			words++;
			s += h_strlen(s, delim);
		}
		else
			s++;
	}
	return (words);
}

static void	*free_array(char **array, int amount)
{
	while (amount > 0)
		free(array[(amount--) - 1]);
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str_array;
	int		array_idx;

	str_array = (char **)malloc((h_count_words(s, c) + 1) * sizeof(char *));
	if (!str_array)
		return (NULL);
	array_idx = 0;
	while (*s)
	{
		if (h_strlen(s, c))
		{
			str_array[array_idx] = (char *)malloc(h_strlen(s, c) + 1);
			if (!str_array[array_idx])
				return (free_array(str_array, array_idx + 1));
			ft_strlcpy(str_array[array_idx++], s, h_strlen(s, c) + 1);
			s += h_strlen(s, c);
		}
		else
			s++;
	}
	str_array[array_idx] = NULL;
	return (str_array);
}
