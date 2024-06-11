/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_engine_space.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:01:59 by lsorg             #+#    #+#             */
/*   Updated: 2024/06/05 18:06:14 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "fdf_engine.h"

typedef struct s_unit_vectors
{
	t_matrix	xaxis;
	t_matrix	yaxis;
	t_matrix	zaxis;
}				t_unit_vectors;

typedef struct s_axis_color
{
	uint32_t	z_color;
	uint32_t	x_color;
	uint32_t	y_color;
}				t_axis_color;

t_axis_color	get_axis_colors(t_engine_config *config);