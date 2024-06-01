/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_engine_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:19:53 by lsorg             #+#    #+#             */
/*   Updated: 2024/06/01 20:39:43 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_engine.h"
#include <stdio.h>

void connect_vertex(t_position pos1, t_position pos2, t_matrix *vertex3d,
                    t_matrix *vertex2d, t_engine_config *config) {
    t_position start;
    t_position end;

    vertex3d->matrix[0][0] = pos1.x;
    vertex3d->matrix[1][0] = pos1.y;
    vertex3d->matrix[2][0] = config->map_data[pos1.y*config->map_dimension.x+pos1.x]/4;
    matrix_dot_ex(config->affine,*vertex3d,*vertex2d);
    start = (t_position) {
        .x = round(vertex2d->matrix[0][0]),
        .y = round(vertex2d->matrix[1][0])
    };
    vertex3d->matrix[0][0] = pos2.x;
    vertex3d->matrix[1][0] = pos2.y;
    vertex3d->matrix[2][0] = config->map_data[pos2.y*config->map_dimension.x+pos2.x]/4;
    matrix_dot_ex(config->affine,*vertex3d,*vertex2d);
    end = (t_position) {
        .x = round(vertex2d->matrix[0][0]),
        .y = round(vertex2d->matrix[1][0])
    };
    img_draw_line(config->image,start,end,config->color);
}