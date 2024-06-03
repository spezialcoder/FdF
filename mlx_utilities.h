/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utilities.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:12:17 by lsorg             #+#    #+#             */
/*   Updated: 2024/06/03 20:57:12 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <math.h>
#include "lib/MLX42/include/MLX42/MLX42.h"

typedef unsigned char       uint8;
typedef unsigned short     uint16;
typedef unsigned int       uint32;
typedef unsigned long long uint64;

typedef struct {
    int x;
    int y;
} t_position;

void img_draw_line(mlx_image_t *image, t_position start, t_position end, u_int32_t color);