/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_engine_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:19:53 by lsorg             #+#    #+#             */
/*   Updated: 2024/06/03 20:51:35 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_engine.h"
#include <stdio.h>

static t_matrix	matrix_dot_ex_fast(t_matrix a, t_matrix b, t_matrix result)
{
	result.matrix[0][0] = a.matrix[0][0] * b.matrix[0][0] + a.matrix[0][1]
		* b.matrix[1][0] + a.matrix[0][2] * b.matrix[2][0] + a.matrix[0][3]
		* b.matrix[3][0];
	result.matrix[1][0] = a.matrix[1][0] * b.matrix[0][0] + a.matrix[1][1]
		* b.matrix[1][0] + a.matrix[1][2] * b.matrix[2][0] + a.matrix[1][3]
		* b.matrix[3][0];
	return (result);
}

void	connect_vertex(t_position pos1, t_position pos2, t_matrix *vertex3d,
		t_matrix *vertex2d, t_engine_config *config)
{
	t_position	start;
	t_position	end;

	vertex3d->matrix[0][0] = pos1.x;
	vertex3d->matrix[1][0] = pos1.y;
	vertex3d->matrix[2][0] = -config->map_data[pos1.y * config->map_dimension.x
		+ pos1.x];
	matrix_dot_ex_fast(config->affine, *vertex3d, *vertex2d);
	start = (t_position){.x = round(vertex2d->matrix[0][0]),
		.y = round(vertex2d->matrix[1][0])};
	vertex3d->matrix[0][0] = pos2.x;
	vertex3d->matrix[1][0] = pos2.y;
	vertex3d->matrix[2][0] = -config->map_data[pos2.y * config->map_dimension.x
		+ pos2.x];
	matrix_dot_ex_fast(config->affine, *vertex3d, *vertex2d);
	end = (t_position){.x = round(vertex2d->matrix[0][0]),
		.y = round(vertex2d->matrix[1][0])};
	img_draw_line(config->image, start, end, config->color);
}

int	sign(double value)
{
	if (value < 0)
		return (-1);
	return (1);
}
