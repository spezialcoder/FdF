/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_engine.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:16:51 by lsorg             #+#    #+#             */
/*   Updated: 2024/06/01 20:03:10 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../MLX42/include/MLX42/MLX42.h"
#include "../matrix.h"
#include "../mlx_utilities.h"
#include "../loader.h"
#include <math.h>

typedef struct {
    double scale;
    double translation_x;
    double translation_y;
    double translation_z;
    double rotation_x;
    double rotation_z;
    double rotation_y;
} t_construct;

typedef struct {
    mlx_t *mlx;
    mlx_image_t *image;
    t_matrix affine;
    t_matrix isometric;
    t_construct state;
    t_mapdim map_dimension;
    int *map_data;
    int color;
} t_engine_config;

typedef struct {
    int x;
    int y;
} t_vertex_2d;

typedef struct {
    int x;
    int y;
    int z;
} t_vertex_3d;

t_engine_config *init_engine(int width, int height, char *window_name,
                             char *filename);
t_matrix shaper_rotate(double rotation_x, double rotation_y, double rotation_z);
t_matrix shaper_translate(double translation_x, double translation_y, double translation_z);
t_matrix shaper_scale(double scale);
void calculate_state(t_engine_config *config);
void plot_grid(t_engine_config *config);
void connect_vertex(t_position pos1, t_position pos2, t_matrix *vertex3d,
                    t_matrix *vertex2d, t_engine_config *config);
t_matrix shaper_identity();