/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_axis_colors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:01:14 by lsorg             #+#    #+#             */
/*   Updated: 2024/06/05 17:56:42 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_engine.h"
#include "fdf_engine_space.h"

static inline int	z_direction(t_engine_config *config);
static inline int	y_direction(t_engine_config *config);
static inline int	x_direction(t_engine_config *config);

t_axis_color	get_axis_colors(t_engine_config *config)
{
	t_axis_color	colors;

	colors.z_color = 0x0000FFFF;
	colors.x_color = 0x800000FF;
	colors.y_color = 0x008000FF;
	if (z_direction(config))
		colors.z_color = 0x00FFFFFF;
	if (x_direction(config))
		colors.x_color = 0xFF0000FF;
	if (y_direction(config))
		colors.y_color = 0x00FF00FF;
	return (colors);
}

static inline int	z_direction(t_engine_config *config)
{
	return (x_direction(config) == y_direction(config));
}

static inline int	x_direction(t_engine_config *config)
{
	return (((config->state.rotation_y >= -M_PI / 2
				&& config->state.rotation_y <= M_PI / 2)
			|| fabs(config->state.rotation_y) >= (6.0 / 4) * M_PI));
}

static inline int	y_direction(t_engine_config *config)
{
	return (((config->state.rotation_x >= -M_PI / 2
				&& config->state.rotation_x <= M_PI / 2)
			|| fabs(config->state.rotation_x) >= (6.0 / 4) * M_PI));
}
