/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_engine_menu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 21:17:45 by lsorg             #+#    #+#             */
/*   Updated: 2024/06/05 18:06:38 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_engine.h"
#include "fdf_engine_space.h"

static t_unit_vectors	get_unit_vectors(double scale);
static void				apply_rotation_matrix(t_engine_config *config,
							t_unit_vectors vectors);

void	fdf_show_space(t_engine_config *config)
{
	t_unit_vectors	vectors;
	t_position		origin;
	t_axis_color	colors;
	int				x_offset;
	int				y_offset;

	x_offset = config->image->width - 100;
	y_offset = 80;
	vectors = get_unit_vectors(50);
	colors = get_axis_colors(config);
	apply_rotation_matrix(config, vectors);
	origin = (t_position){.x = x_offset, .y = y_offset};
	img_draw_line(config->image, origin,
		(t_position){.x = vectors.xaxis.matrix[0][0] + x_offset,
		.y = vectors.xaxis.matrix[1][0] + y_offset}, colors.x_color);
	img_draw_line(config->image, origin,
		(t_position){.x = vectors.yaxis.matrix[0][0] + x_offset,
		.y = vectors.yaxis.matrix[1][0] + y_offset}, colors.y_color);
	img_draw_line(config->image, origin,
		(t_position){.x = vectors.zaxis.matrix[0][0] + x_offset,
		.y = vectors.zaxis.matrix[1][0] + y_offset}, colors.z_color);
	matrix_delete(vectors.xaxis);
	matrix_delete(vectors.zaxis);
	matrix_delete(vectors.yaxis);
}

static void	apply_rotation_matrix(t_engine_config *config,
		t_unit_vectors vectors)
{
	t_matrix	rotation;
	t_matrix	tmp;

	rotation = shaper_identity();
	tmp = shaper_rotate(config->state.rotation_x, config->state.rotation_y,
			config->state.rotation_z);
	matrix_dot_ex_restrict(rotation, tmp, rotation);
	matrix_dot_ex_restrict(rotation, vectors.xaxis, vectors.xaxis);
	matrix_dot_ex_restrict(rotation, vectors.yaxis, vectors.yaxis);
	matrix_dot_ex_restrict(rotation, vectors.zaxis, vectors.zaxis);
	matrix_delete(rotation);
	matrix_delete(tmp);
}

static t_unit_vectors	get_unit_vectors(double scale)
{
	t_matrix	xaxis;
	t_matrix	yaxis;
	t_matrix	zaxis;

	xaxis = matrix_create(1, 4);
	yaxis = matrix_create(1, 4);
	zaxis = matrix_create(1, 4);
	xaxis.matrix[0][0] = scale;
	xaxis.matrix[3][0] = 1;
	yaxis.matrix[1][0] = scale;
	yaxis.matrix[3][0] = 1;
	zaxis.matrix[2][0] = scale;
	zaxis.matrix[3][0] = 1;
	return ((t_unit_vectors){.xaxis = xaxis, .yaxis = yaxis, .zaxis = zaxis});
}

void	terminate_engine(t_engine_config *config)
{
	free(config->map_data);
	matrix_delete(config->affine);
	mlx_terminate(config->mlx);
	mlx_delete_image(config->mlx, config->image);
	free(config);
}
