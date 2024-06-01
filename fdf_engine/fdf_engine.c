/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_engine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:16:51 by lsorg             #+#    #+#             */
/*   Updated: 2024/06/01 20:32:07 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_engine.h"

static void init_isometrics(t_engine_config *config);

t_engine_config *init_engine(int width, int height, char *window_name,
                             char *filename) {
    t_engine_config *engine;

    engine = ft_calloc(1,sizeof(t_engine_config));
    engine->mlx = mlx_init(width,height,window_name,false);
    if(!engine->mlx) return (NULL);
    engine->image = mlx_new_image(engine->mlx,width,height);
    if(!engine->image) return (NULL);
    engine->affine = matrix_create(4,4);
    init_isometrics(engine);
    calculate_state(engine);
    engine->map_dimension = get_map_dimension(filename);
    engine->map_data = load_map(filename, engine->map_dimension);
    engine->color = 0xFFFFFF;
    return (engine);
}

static void init_isometrics(t_engine_config *config) {
    config->isometric = matrix_create(4,4);
    config->isometric.matrix[0][0] = sqrt(3)/2;
    config->isometric.matrix[0][2] = 0.5;
    config->isometric.matrix[1][0] = 1/ sqrt(6);
    config->isometric.matrix[1][1] = 2/ sqrt(6);
    config->isometric.matrix[1][2] = -1/ sqrt(6);
    config->isometric.matrix[3][3] = 1;
}
void plot_grid(t_engine_config *config) {
    t_matrix vertex3d;
    t_matrix vertex2d;
    int x;
    int y;
    mlx_delete_image(config->mlx,config->image);
    config->image = mlx_new_image(config->mlx,1920,1080);
    vertex3d = matrix_create(1,4);
    vertex2d = matrix_create(1,4);
    vertex3d.matrix[3][0] = 1;
    y = 0;
    while(y < config->map_dimension.y) {
        x = 0;
        while(x < config->map_dimension.x-1) {
            connect_vertex((t_position){.x=x,.y=y},
                           (t_position){.x=x+1,.y=y},
                           &vertex3d,&vertex2d,config);
            if(y < config->map_dimension.y-1)
                connect_vertex((t_position){.x=x,.y=y},
                           (t_position){.x=x,.y=y+1},
                           &vertex3d,&vertex2d,config);
            x++;
        }
        if(y < config->map_dimension.y-1)
            connect_vertex((t_position){.x=x,.y=y},
                           (t_position){.x=x,.y=y+1},
                           &vertex3d,&vertex2d,config);
        y++;
    }
    mlx_image_to_window(config->mlx,config->image,0,0);
}

void calculate_state(t_engine_config *config) {
    // Apply isometric transformation
    t_matrix affine = matrix_dot(config->isometric, shaper_identity());

// Translate
    affine = matrix_dot(affine, shaper_translate(config->state.translation_x,
                                                 config->state.translation_y,
                                                 config->state.translation_z));

// Rotate
    affine = matrix_dot(affine, shaper_rotate(config->state.rotation_x,
                                              config->state.rotation_y,
                                              config->state.rotation_z));

// Scale
    affine = matrix_dot(affine, shaper_scale(config->state.scale));

// Update config->affine
    matrix_delete(config->affine);
    config->affine = affine;

}


