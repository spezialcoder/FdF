/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_engine_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:19:53 by lsorg             #+#    #+#             */
/*   Updated: 2024/06/06 16:18:46 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_engine.h"

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

void	connect_vertex(t_line pos, t_matrix *vertex3d, t_matrix *vertex2d,
		t_engine_config *config)
{
	t_position	start;
	t_position	end;
	uint32_t	color;

	vertex3d->matrix[0][0] = pos.pos1.x;
	vertex3d->matrix[1][0] = pos.pos1.y;
	vertex3d->matrix[2][0] = config->map_data[pos.pos1.y
		* config->map_dimension.x + pos.pos1.x].value;
	matrix_dot_ex_fast(config->affine, *vertex3d, *vertex2d);
	start = (t_position){.x = round(vertex2d->matrix[0][0]),
		.y = round(vertex2d->matrix[1][0])};
	vertex3d->matrix[0][0] = pos.pos2.x;
	vertex3d->matrix[1][0] = pos.pos2.y;
	vertex3d->matrix[2][0] = config->map_data[pos.pos2.y
		* config->map_dimension.x + pos.pos2.x].value;
	matrix_dot_ex_fast(config->affine, *vertex3d, *vertex2d);
	end = (t_position){.x = round(vertex2d->matrix[0][0]),
		.y = round(vertex2d->matrix[1][0])};
	if (config->map_data[pos.pos2.y * config->map_dimension.x
			+ pos.pos2.x].color)
		color = config->map_data[pos.pos2.y * config->map_dimension.x
			+ pos.pos2.x].color;
	else
		color = config->color;
	img_draw_line(config->image, start, end, color);
}

int	sign(double value)
{
	if (value < 0)
		return (-1);
	return (1);
}

void	reset_view(t_engine_config *config)
{
	config->state.rotation_x = 0;
	config->state.rotation_y = 0;
	config->state.rotation_z = 0;
	config->state.scale = 10;
	config->state.translation_y = config->mlx->height / 2
		- config->map_dimension.x / 2 * config->state.scale;
	config->state.translation_x = config->mlx->width / 2
		- config->map_dimension.y / 2 * config->state.scale;
}

t_matrix	shaper_identity(void)
{
	t_matrix	identity;

	identity = matrix_create(4, 4);
	identity.matrix[0][0] = 1;
	identity.matrix[1][1] = 1;
	identity.matrix[2][2] = 1;
	identity.matrix[3][3] = 1;
	return (identity);
}
