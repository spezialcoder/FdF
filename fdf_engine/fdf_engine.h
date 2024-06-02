/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_engine.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:16:51 by lsorg             #+#    #+#             */
/*   Updated: 2024/06/02 21:10:49 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../MLX42/include/MLX42/MLX42.h"
#include "../matrix/matrix.h"
#include "../mlx_utilities.h"
#include "../loader.h"
#include <math.h>

#define MOUSE_SENSITIVITY 200

typedef struct {
    double scale;
    double z_scale;
    double translation_x;
    double translation_y;
    double translation_z;
    double rotation_x;
    double rotation_z;
    double rotation_y;
} t_construct;

typedef struct {
    int x;
    int y;
} t_vertex_2d;

typedef struct {
    int x;
    int y;
    int z;
} t_vertex_3d;


typedef struct {
    double last_xpos;
    double last_ypos;
} t_cursor_data;

typedef struct {
    mlx_t *mlx;
    mlx_image_t *image;
    t_matrix affine;
    t_construct state;
    t_mapdim map_dimension;
    int *map_data;
    int color;
    t_cursor_data cursor_data;
} t_engine_config;


t_engine_config *init_engine(int width, int height, char *window_name,
                             char *filename);
void terminate_engine(t_engine_config *config);
t_matrix shaper_rotate(double rotation_x, double rotation_y, double rotation_z);
t_matrix shaper_translate(double translation_x, double translation_y, double translation_z);
t_matrix shaper_scale(double scale, double z_scale);
t_matrix shaper_identity();
void calculate_state(t_engine_config *config);
void plot_grid(t_engine_config *config);
void connect_vertex(t_position pos1, t_position pos2, t_matrix *vertex3d,
                    t_matrix *vertex2d, t_engine_config *config);
void init_hooks(t_engine_config *config);
int sign(double value);
uint32_t calculate_color(int max, int min, int value);