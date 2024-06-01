/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utilities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:12:17 by lsorg             #+#    #+#             */
/*   Updated: 2024/06/01 19:33:01 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Lewin Sorg on 4/18/24.
//

#include "mlx_utilities.h"

inline int abs(int n) {
    return (n < 0 ? -n : n);
}

void img_draw_line(mlx_image_t *image, t_position start, t_position end, int color) {
    int dx = abs(end.x - start.x);
    int dy = abs(end.y - start.y);
    int sx = start.x < end.x ? 1 : -1;
    int sy = start.y < end.y ? 1 : -1;
    int err = dx - dy;
    int e2;

    while (!(start.x == end.x && start.y == end.y)) {
        if(start.x >= 0 && start.y >= 0 &&
        start.x <= image->width && start.y <= image->height) mlx_put_pixel(image,start.x,start.y,color);
        e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            start.x += sx;
        }
        if (e2 < dx) {
            err += dx;
            start.y += sy;
        }
    }
    if(start.x >= 0 && start.y >= 0 &&
       start.x <= image->width && start.y <= image->height) mlx_put_pixel(image,start.x,start.y,color);
}