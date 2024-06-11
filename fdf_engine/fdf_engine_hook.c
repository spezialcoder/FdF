/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_engine_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:21:19 by lsorg             #+#    #+#             */
/*   Updated: 2024/06/06 16:05:21 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_engine.h"

static void	fdf_scroll(double xdelta, double ydelta, void *param);
static void	fdf_cursor(double xpos, double ypos, void *param);
static void	fdf_key(mlx_key_data_t keydata, void *param);
static void	fdf_mouse(mouse_key_t button, action_t action, modifier_key_t mods,
				void *param);

void	init_hooks(t_engine_config *config)
{
	mlx_scroll_hook(config->mlx, &fdf_scroll, (void *)config);
	mlx_cursor_hook(config->mlx, &fdf_cursor, (void *)config);
	mlx_key_hook(config->mlx, &fdf_key, (void *)config);
	mlx_mouse_hook(config->mlx, &fdf_mouse, (void *)config);
}

static void	fdf_mouse(mouse_key_t button,
		action_t action __attribute__((unused)),
		modifier_key_t mods __attribute__((unused)), void *param)
{
	t_engine_config	*config;
	int32_t			xpos;
	int32_t			ypos;

	config = (t_engine_config *)param;
	if (button == MLX_MOUSE_BUTTON_LEFT || button == MLX_MOUSE_BUTTON_RIGHT)
	{
		mlx_get_mouse_pos(config->mlx, &xpos, &ypos);
		config->cursor_data.last_xpos = (double)xpos;
		config->cursor_data.last_ypos = (double)ypos;
	}
}

static void	fdf_scroll(double xdelta __attribute__((unused)), double ydelta,
		void *param)
{
	double			tmp;
	t_engine_config	*config;

	config = (t_engine_config *)param;
	if (config->state.scale > 1 || ydelta < 0)
	{
		tmp = config->state.scale;
		if (mlx_is_key_down(config->mlx, MLX_KEY_LEFT_CONTROL))
			config->state.scale -= (sign(ydelta) * 50.0)
				/ config->scale_constant;
		else
			config->state.scale -= (sign(ydelta) * 10.0)
				/ config->scale_constant;
		if (config->state.scale < 0)
		{
			config->state.scale = tmp;
		}
		calculate_state(config);
		plot_grid(config);
	}
}

static void	fdf_cursor(double xpos, double ypos, void *param)
{
	t_engine_config	*config;

	config = (t_engine_config *)param;
	if (*((uint64_t *)&config->cursor_data) == 0)
	{
		config->cursor_data.last_xpos = xpos;
		config->cursor_data.last_ypos = ypos;
	}
	if (mlx_is_mouse_down(config->mlx, MLX_MOUSE_BUTTON_LEFT))
	{
		handle_cursor(config, xpos, ypos);
		calculate_state(config);
		plot_grid(config);
	}
	else if (mlx_is_mouse_down(config->mlx, MLX_MOUSE_BUTTON_RIGHT))
	{
		config->state.translation_x += (xpos - config->cursor_data.last_xpos);
		config->state.translation_y += (ypos - config->cursor_data.last_ypos);
		config->cursor_data.last_xpos = xpos;
		config->cursor_data.last_ypos = ypos;
		calculate_state(config);
		plot_grid(config);
	}
}

static void	fdf_key(mlx_key_data_t keydata, void *param)
{
	t_engine_config	*config;

	config = (t_engine_config *)param;
	if (keydata.key == MLX_KEY_I && keydata.action == MLX_PRESS)
		return (config->state.rotation_x = 45 * (M_PI / 180),
			config->state.rotation_z = 35.264 * (M_PI / 180),
			config->state.rotation_y = 0, calculate_state(config),
			plot_grid(config));
	else if (keydata.key == MLX_KEY_ESCAPE)
		return (mlx_close_window(config->mlx));
	else if (keydata.key == MLX_KEY_KP_ADD)
		return (config->state.z_scale += 0.02, calculate_state(config),
			plot_grid(config));
	else if (keydata.key == MLX_KEY_KP_SUBTRACT)
		return (config->state.z_scale -= 0.02, calculate_state(config),
			plot_grid(config));
	else if (keydata.key == MLX_KEY_Q)
		return (config->state.rotation_z -= 2.5 * (M_PI / 180),
			calculate_state(config), plot_grid(config));
	else if (keydata.key == MLX_KEY_E)
		return (config->state.rotation_z += 2.5 * (M_PI / 180),
			calculate_state(config), plot_grid(config));
	else if (keydata.key == MLX_KEY_R)
		return (reset_view(config), calculate_state(config), plot_grid(config));
}
