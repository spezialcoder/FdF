/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utilities.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:12:17 by lsorg             #+#    #+#             */
/*   Updated: 2024/04/23 20:47:15 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <math.h>

typedef unsigned char       uint8;
typedef unsigned short     uint16;
typedef unsigned int       uint32;
typedef unsigned long long uint64;



typedef struct	 {
    void	*img;
    char	*addr;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
}				t_imgdata;

typedef struct {
    void *mlx;
    void *win;
    t_imgdata *data;
} fdf_data;

typedef struct {
    int x;
    int y;
} t_position;

void	img_put_pixel(t_imgdata *data, int x, int y, int color);
void    img_draw_line(t_imgdata *data, t_position start, t_position end, int color);