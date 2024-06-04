/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:16:51 by lsorg             #+#    #+#             */
/*   Updated: 2024/06/04 17:57:44 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Lewin Sorg on 4/22/24.
//

#include "loader.h"

extern void fetchInto(int fd, t_map_vertex *target);

t_map_vertex* load_map(char *filename, t_mapdim mapDim) {

    t_map_vertex *mapData;
    int fd;

    mapData = ft_calloc(mapDim.y,mapDim.x*sizeof(t_map_vertex));
    if( !*((u_int64_t*)&mapDim) ) return (NULL);
    fd = open(filename,O_RDONLY);
    if(!fd) return (NULL);
    fetchInto(fd, mapData);
    close(fd);
    return (mapData);
}

uint32_t atoi_hex(char *hex_string) {
    uint32_t value;

    hex_string = ft_strchr(hex_string,'x')+1;
    value = 0;
    while(*hex_string) {
        value *= 16;
        if(ft_isdigit(*hex_string)) {
            value += *hex_string - '0';
        } else {
            value += *hex_string - 55;
        }
        hex_string++;
    }
    return (value);

}