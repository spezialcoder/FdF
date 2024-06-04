/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_engine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:16:51 by lsorg             #+#    #+#             */
/*   Updated: 2024/06/04 19:49:50 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_engine.h"
#define SCALE_CONSTANT 10.0

t_engine_config	*init_engine(int width, int height, char *window_name,
		char *filename)
{
	t_engine_config	*engine;

	engine = ft_calloc(1, sizeof(t_engine_config));
	engine->mlx = mlx_init(width, height, window_name, true);
	if (!engine->mlx)
		return (NULL);
	engine->image = mlx_new_image(engine->mlx, width, height);
	if (!engine->image)
		return (NULL);
	engine->affine = matrix_create(4, 4);
	engine->map_dimension = get_map_dimension(filename);
	engine->map_data = load_map(filename, engine->map_dimension);
	engine->color = 0xFFFFFFFF;
	engine->state.z_scale = 0.1;
	init_hooks(engine);
    reset_view(engine);
    calculate_state(engine);
    engine->scale_constant = (sqrt(
            ((engine->map_dimension.y*engine->map_dimension.x*1.0)+SCALE_CONSTANT)
                              /SCALE_CONSTANT));
	return (engine);
}

void	terminate_engine(t_engine_config *config)
{
	free(config->map_data);
	matrix_delete(config->affine);
	mlx_terminate(config->mlx);
	mlx_delete_image(config->mlx, config->image);
	free(config);
}

void	plot_grid(t_engine_config *config)
{
	t_matrix	vertex3d;
	t_matrix	vertex2d;
	uint32_t    x;
	uint32_t    y;

	mlx_delete_image(config->mlx, config->image);
	config->image = mlx_new_image(config->mlx, config->mlx->width,
			config->mlx->width);
	vertex3d = matrix_create(1, 4);
	vertex2d = matrix_create(1, 4);
	vertex3d.matrix[3][0] = 1;
	y = 0;
	while (y < config->map_dimension.y)
	{
		x = 0;
		while (x < config->map_dimension.x - 1)
		{
			connect_vertex((t_position){.x = x, .y = y}, (t_position){.x = x
				+ 1, .y = y}, &vertex3d, &vertex2d, config);
			if (y < config->map_dimension.y - 1)
				connect_vertex((t_position){.x = x, .y = y},
					(t_position){.x = x, .y = y + 1}, &vertex3d, &vertex2d,
					config);
			x++;
		}
		if (y < config->map_dimension.y - 1)
			connect_vertex((t_position){.x = x, .y = y}, (t_position){.x = x,
				.y = y + 1}, &vertex3d, &vertex2d, config);
		y++;
	}
	matrix_delete(vertex3d);
	matrix_delete(vertex2d);
    fdf_show_space(config);
	mlx_image_to_window(config->mlx, config->image, 0, 0);
}

void	calculate_state(t_engine_config *config)
{
	t_matrix	affine;
	t_matrix	identity;
	t_matrix	tmp;

	identity = shaper_identity();
	tmp = shaper_translate(config->state.translation_x,
			config->state.translation_y, config->state.translation_z);
	affine = matrix_dot(identity, tmp);
	matrix_delete(tmp);
	matrix_delete(identity);
	tmp = shaper_translate((double)config->map_dimension.x / 2
			* config->state.scale, (double)config->map_dimension.y / 2
			* config->state.scale, -1.0*config->state.translation_z*config->state.scale);
	matrix_dot_ex_restrict(affine, tmp, affine);
	matrix_delete(tmp);
	tmp = shaper_rotate(config->state.rotation_x, config->state.rotation_y,
			config->state.rotation_z);
	matrix_dot_ex_restrict(affine, tmp, affine);
	matrix_delete(tmp);
	tmp = shaper_translate(-1 * (double)config->map_dimension.x / 2
			* config->state.scale, -1 * (double)config->map_dimension.y / 2
			* config->state.scale, config->state.translation_z*config->state.scale);
	matrix_dot_ex_restrict(affine, tmp, affine);
	matrix_delete(tmp);
    tmp = shaper_scale(config->state.scale, config->state.z_scale);
	matrix_dot_ex_restrict(affine, tmp, affine);
	matrix_delete(tmp);
	matrix_delete(config->affine);
	config->affine = affine;
}
