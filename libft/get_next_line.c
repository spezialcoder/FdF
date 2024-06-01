/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:38:30 by lsorg             #+#    #+#             */
/*   Updated: 2024/04/17 20:33:45 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*init_leftover(char **leftover);

char	*get_next_line(int fd)
{
	static char	*last;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return (read_line(&last, fd));
}

char	*read_line(char **leftover, int fd)
{
	char	*buffer;
	char	*tmp;
	int		rd_bytes;

	if (!init_leftover(leftover))
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(*leftover), *leftover = NULL, NULL);
	rd_bytes = 1;
	while (!ft_strchr(*leftover, '\n'))
	{
		rd_bytes = read(fd, buffer, BUFFER_SIZE);
		if (rd_bytes == -1)
			return (free(*leftover), free(buffer), *leftover = NULL, NULL);
		if (!rd_bytes)
			break ;
		buffer[rd_bytes] = 0;
		tmp = *leftover;
		*leftover = ft_strjoin(*leftover, buffer);
		if (!*(leftover))
			return (free(tmp), free(buffer), NULL);
		free(tmp);
	}
	return (free(buffer), extract_line(leftover));
}

static void	*init_leftover(char **leftover)
{
	if (!*leftover)
	{
		*leftover = malloc(1);
		if (!(*leftover))
			return (NULL);
		**leftover = 0;
	}
	return ((void *)*leftover);
}

char	*extract_line(char **str)
{
	int		ssize;
	char	*line;
	char	*tmp;

	tmp = *str;
	ssize = 0;
	if (!(**str))
		return (free(*str), *str = NULL, NULL);
	while (tmp[ssize] && tmp[ssize] != '\n')
		ssize++;
	if (tmp[ssize] == '\n')
		ssize++;
	line = (char *)malloc(ssize + 1);
	if (!line)
		return (free(*str), *str = NULL, NULL);
	ft_memcpy(line, *str, ssize);
	line[ssize] = 0;
	*str = malloc(ft_strlen(&tmp[ssize]) + 1);
	if (!*str)
		return (free(line), free(tmp), NULL);
	ft_memcpy(*str, &tmp[ssize], ft_strlen(&tmp[ssize]) + 1);
	free(tmp);
	return (line);
}
