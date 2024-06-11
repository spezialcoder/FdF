/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utilities.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:12:17 by lsorg             #+#    #+#             */
/*   Updated: 2024/06/05 15:39:49 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "lib/MLX42/include/MLX42/MLX42.h"
#include <math.h>

typedef unsigned char		t_uint8;
typedef unsigned short		t_uint16;
typedef unsigned int		t_uint32;
typedef unsigned long long	t_uint64;

typedef struct s_position
{
	int						x;
	int						y;
}							t_position;

typedef struct s_algdata
{
	int						dx;
	int						dy;
	int						sx;
	int						sy;
	int						err;
}							t_algdata;
void						img_draw_line(mlx_image_t *image, t_position start,
								t_position end, u_int32_t color);