/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:08:14 by lsorg             #+#    #+#             */
/*   Updated: 2024/06/05 18:06:22 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_engine.h"

t_matrix	shaper_scale(double scale, double z_scale)
{
	t_matrix	transformation;

	transformation = matrix_create(4, 4);
	transformation.matrix[0][0] = scale;
	transformation.matrix[1][1] = scale;
	transformation.matrix[2][2] = z_scale * scale;
	transformation.matrix[3][3] = 1;
	return (transformation);
}

t_matrix	shaper_translate(double translation_x, double translation_y,
		double translation_z)
{
	t_matrix	transformation;

	transformation = matrix_create(4, 4);
	transformation.matrix[0][0] = 1;
	transformation.matrix[1][1] = 1;
	transformation.matrix[2][2] = 1;
	transformation.matrix[3][3] = 1;
	transformation.matrix[0][3] = translation_x;
	transformation.matrix[1][3] = translation_y;
	transformation.matrix[2][3] = translation_z;
	return (transformation);
}

static t_matrix	shaper_rotate_y(double theta)
{
	t_matrix	transformation;

	transformation = matrix_create(4, 4);
	transformation.matrix[0][0] = cos(theta);
	transformation.matrix[0][2] = sin(theta);
	transformation.matrix[1][1] = 1;
	transformation.matrix[2][0] = -1 * sin(theta);
	transformation.matrix[2][2] = cos(theta);
	transformation.matrix[3][3] = 1;
	return (transformation);
}

static t_matrix	shaper_rotate_z(double theta)
{
	t_matrix	transformation;

	transformation = matrix_create(4, 4);
	transformation.matrix[0][0] = cos(theta);
	transformation.matrix[0][1] = -1 * sin(theta);
	transformation.matrix[1][0] = sin(theta);
	transformation.matrix[1][1] = cos(theta);
	transformation.matrix[2][2] = 1;
	transformation.matrix[3][3] = 1;
	return (transformation);
}

t_matrix	shaper_rotate(double rotation_x, double rotation_y,
		double rotation_z)
{
	t_matrix	transformation;
	t_matrix	output;
	t_matrix	trot_z;
	t_matrix	trot_y;

	transformation = matrix_create(4, 4);
	transformation.matrix[0][0] = 1;
	transformation.matrix[1][1] = cos(rotation_x);
	transformation.matrix[1][2] = -1 * sin(rotation_x);
	transformation.matrix[2][1] = sin(rotation_x);
	transformation.matrix[2][2] = cos(rotation_x);
	transformation.matrix[3][3] = 1;
	trot_z = shaper_rotate_z(rotation_z);
	trot_y = shaper_rotate_y(rotation_y);
	output = shaper_identity();
	matrix_dot_ex_restrict(output, transformation, output);
	matrix_dot_ex_restrict(output, trot_y, output);
	matrix_dot_ex_restrict(output, trot_z, output);
	matrix_delete(trot_y);
	matrix_delete(trot_z);
	matrix_delete(transformation);
	return (output);
}
