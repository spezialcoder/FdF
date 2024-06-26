/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_engine.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:16:51 by lsorg             #+#    #+#             */
/*   Updated: 2024/06/06 15:56:06 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../loader.h"
#include "../matrix/matrix.h"
#include "../mlx_utilities.h"
#include <math.h>

#define MOUSE_SENSITIVITY 200

typedef struct s_construct
{
	double			scale;
	double			z_scale;
	double			translation_x;
	double			translation_y;
	double			translation_z;
	double			rotation_x;
	double			rotation_z;
	double			rotation_y;
}					t_construct;

typedef struct s_vertex_2d
{
	int				x;
	int				y;
}					t_vertex_2d;

typedef struct s_vertex_3d
{
	int				x;
	int				y;
	int				z;
}					t_vertex_3d;

typedef struct s_cursor_data
{
	double			last_xpos;
	double			last_ypos;
}					t_cursor_data;

typedef struct s_engine_config
{
	mlx_t			*mlx;
	mlx_image_t		*image;
	t_matrix		affine;
	t_construct		state;
	t_mapdim		map_dimension;
	t_map_vertex	*map_data;
	uint32_t		color;
	t_cursor_data	cursor_data;
	double			scale_constant;
}					t_engine_config;

typedef struct s_line
{
	t_position		pos1;
	t_position		pos2;
}					t_line;

t_engine_config		*init_engine(int width, int height, char *window_name,
						char *filename);
void				terminate_engine(t_engine_config *config);
t_matrix			shaper_rotate(double rotation_x, double rotation_y,
						double rotation_z);
t_matrix			shaper_translate(double translation_x, double translation_y,
						double translation_z);
t_matrix			shaper_scale(double scale, double z_scale);
t_matrix			shaper_identity(void);
void				calculate_state(t_engine_config *config);
void				plot_grid(t_engine_config *config);
void				connect_vertex(t_line pos, t_matrix *vertex3d,
						t_matrix *vertex2d, t_engine_config *config);
void				init_hooks(t_engine_config *config);
int					sign(double value);
uint32_t			calculate_color(int max, int min, int value);
void				fdf_show_space(t_engine_config *config);
void				reset_view(t_engine_config *config);
void				handle_cursor(t_engine_config *config, double xpos,
						double ypos);