//
// Created by Lewin Sorg on 4/22/24.
//

#include "loader.h"

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
    t_mapdim dim;

    ft_memset(&dim, 0,  sizeof(t_mapdim));
    fd = open(filename,O_RDONLY);
    if(fd < 0) {
        return (dim);
    }
    row = get_next_line(fd);
    while(*row) {
        if(ft_isdigit(*(row++))) dim.x++;
    }
    dim.y = 1;
    while(get_next_line(fd)) dim.y++;
    close(fd);
    return (dim);
}