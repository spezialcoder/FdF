//
// Created by Lewin Sorg on 4/22/24.
//

#include "loader.h"


t_matrix **loadMap(char *filename) {
    int fd;
    int cols;
    char *first_row;
    char **data;
    t_matrix **map_data;
    int y;
    int x;

    y = 0;
    x = 0;
    cols = 0;
    fd = open(filename,O_RDONLY);
    if(fd < 0) {
        return (NULL);
    }

    first_row = get_next_line(fd);
    data = ft_split(first_row,' ');
    while(data[cols++]);

}