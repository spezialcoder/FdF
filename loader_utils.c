/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:23:03 by lsorg             #+#    #+#             */
/*   Updated: 2024/06/04 16:08:13 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loader.h"

extern uint32_t atoi_hex(char *hex_string);

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
    int rowIdx;

    rowIdx = 0;
    while (array[rowIdx])
        free(array[rowIdx++]);
    free(array);
}

void fetchInto(int fd, t_map_vertex *target) {
    char *rowEater;
    char **pieces;
    int dataIdx;
    int pieceIdx;

    dataIdx = 0;
    rowEater = get_next_line(fd);
    while(rowEater) {
        pieces = ft_split(rowEater,' ');
        pieceIdx = 0;
        while(pieces[pieceIdx]) {
            target[dataIdx].value = ft_atoi(pieces[pieceIdx]);
            if(ft_strchr(pieces[pieceIdx],','))
                target[dataIdx].color = (atoi_hex(ft_strchr(pieces[pieceIdx],',')+1)<<8)|0xFF;
            dataIdx++;
            pieceIdx++;
        }
        free_split_array(pieces);
        free(rowEater);
        rowEater = get_next_line(fd);
    }
}

t_mapdim get_map_dimension(char *filename) {
    int fd;
    char *row;

    int idx;
    t_mapdim dim;

    idx = 0;
    ft_memset(&dim, 0,  sizeof(t_mapdim));
    fd = open(filename,O_RDONLY);
    if(fd < 0) {
        return (dim);
    }
    row = get_next_line(fd);
    dim.x = h_count_words(row,' ');
    dim.y = 0;
    while(row) {
        dim.y++;
        free(row);
        row = get_next_line(fd);

    }
    close(fd);
    return (dim);
}