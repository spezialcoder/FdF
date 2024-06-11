/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_engine_routines.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:54:19 by lsorg             #+#    #+#             */
/*   Updated: 2024/06/06 15:55:29 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_engine.h"

void	handle_cursor(t_engine_config *config, double xpos, double ypos)
{
	config->state.rotation_x -= (ypos - config->cursor_data.last_ypos)
		/ MOUSE_SENSITIVITY;
	config->state.rotation_y += (xpos - config->cursor_data.last_xpos)
		/ MOUSE_SENSITIVITY;
	if (fabs(config->state.rotation_x) > 2 * M_PI)
	{
		config->state.rotation_x = fmod(config->state.rotation_x, 2 * M_PI);
	}
	if (fabs(config->state.rotation_y) > 2 * M_PI)
	{
		config->state.rotation_y = fmod(config->state.rotation_y, 2 * M_PI);
	}
	config->cursor_data.last_xpos = xpos;
	config->cursor_data.last_ypos = ypos;
}
