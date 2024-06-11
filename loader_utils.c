/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:23:03 by lsorg             #+#    #+#             */
/*   Updated: 2024/06/06 15:40:17 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loader.h"

extern uint32_t	atoi_hex(char *hex_string);

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

static void	free_split_array(char **array)
{
	int	row_idx;

	row_idx = 0;
	while (array[row_idx])
		free(array[row_idx++]);
	free(array);
}

void	fetch_into(int fd, t_map_vertex *target)
{
	char	*row_eater;
	char	**pieces;
	int		data_idx;
	int		piece_idx;

	data_idx = 0;
	row_eater = get_next_line(fd);
	while (row_eater)
	{
		pieces = ft_split(row_eater, ' ');
		piece_idx = 0;
		while (pieces[piece_idx])
		{
			target[data_idx].value = ft_atoi(pieces[piece_idx]);
			if (ft_strchr(pieces[piece_idx], ','))
				target[data_idx].color = (atoi_hex(ft_strchr(pieces[piece_idx],
								',') + 1) << 8) | 0xFF;
			data_idx++;
			piece_idx++;
		}
		free_split_array(pieces);
		free(row_eater);
		row_eater = get_next_line(fd);
	}
}

t_mapdim	get_map_dimension(char *filename)
{
	t_mapdim	dim;
	char		*row;
	int			fd;

	ft_memset(&dim, 0, sizeof(t_mapdim));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		return (dim);
	}
	row = get_next_line(fd);
	dim.x = h_count_words(row, ' ');
	dim.y = 0;
	while (row)
	{
		dim.y++;
		free(row);
		row = get_next_line(fd);
	}
	close(fd);
	return (dim);
}
