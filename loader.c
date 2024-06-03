/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:16:51 by lsorg             #+#    #+#             */
/*   Updated: 2024/06/03 20:26:34 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Lewin Sorg on 4/22/24.
//

#include "loader.h"

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

static void fetchInto(int fd, int *target) {
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
            target[dataIdx++] = ft_atoi(pieces[pieceIdx]);
            pieceIdx++;
        }
        free_split_array(pieces);
        free(rowEater);
        rowEater = get_next_line(fd);
    }
}

int *load_map(char *filename, t_mapdim mapDim) {

    int *mapData;
    int fd;

    mapData = ft_calloc(mapDim.y,mapDim.x*sizeof(int));
    if( !*((u_int64_t*)&mapDim) ) return (NULL);
    fd = open(filename,O_RDONLY);
    if(!fd) return (NULL);
    fetchInto(fd, mapData);
    return (mapData);
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