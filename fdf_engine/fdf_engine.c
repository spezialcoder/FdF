/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_engine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:16:51 by lsorg             #+#    #+#             */
/*   Updated: 2024/06/02 20:53:42 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_engine.h"

static void init_isometrics(t_engine_config *config);

t_engine_config *init_engine(int width, int height, char *window_name,
                             char *filename) {
    t_engine_config *engine;

    engine = ft_calloc(1,sizeof(t_engine_config));
    engine->mlx = mlx_init(width,height,window_name,true);
    if(!engine->mlx) return (NULL);
    engine->image = mlx_new_image(engine->mlx,width,height);
    if(!engine->image) return (NULL);
    engine->affine = matrix_create(4,4);
    calculate_state(engine);
    engine->map_dimension = get_map_dimension(filename);
    engine->map_data = load_map(filename, engine->map_dimension);
    engine->color = 0xFFFFFF;
    engine->state.z_scale = 0.1;
    init_hooks(engine);
    return (engine);
}


void terminate_engine(t_engine_config *config) {
    free(config->map_data);
    matrix_delete(config->affine);
    mlx_terminate(config->mlx);
    mlx_delete_image(config->mlx,config->image);
    free(config);
}

void plot_grid(t_engine_config *config) {
    t_matrix vertex3d;
    t_matrix vertex2d;
    int x;
    int y;
    mlx_delete_image(config->mlx,config->image);
    config->image = mlx_new_image(config->mlx,config->mlx->width,config->mlx->width);
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
    matrix_delete(vertex3d);
    matrix_delete(vertex2d);
    mlx_image_to_window(config->mlx,config->image,0,0);
}

void calculate_state(t_engine_config *config) {
    t_matrix affine;
    t_matrix identity;
    t_matrix tmp;

    identity = shaper_identity();
    tmp = shaper_translate(config->state.translation_x,
                           config->state.translation_y,
                           config->state.translation_z);
    affine = matrix_dot(identity, tmp);
    matrix_delete(tmp);
    matrix_delete(identity);
    tmp = shaper_translate((double)config->map_dimension.x/2*config->state.scale,
                           (double)config->map_dimension.y/2*config->state.scale,
                           0);
    matrix_dot_ex(affine,tmp,affine);
    matrix_delete(tmp);
    tmp = shaper_rotate(config->state.rotation_x,
                        config->state.rotation_y,
                        config->state.rotation_z);
    matrix_dot_ex(affine,tmp,affine);
    matrix_delete(tmp);

    tmp = shaper_translate(-1*(double)config->map_dimension.x/2*config->state.scale,
                           -1*(double)config->map_dimension.y/2*config->state.scale,
                           0);
    matrix_dot_ex(affine,tmp,affine);
    matrix_delete(tmp);

    tmp = shaper_scale(config->state.scale, config->state.z_scale);
    matrix_dot_ex(affine,tmp,affine);
    matrix_delete(tmp);

    matrix_delete(config->affine);
    config->affine = affine;
}


