/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:54:40 by lsorg             #+#    #+#             */
/*   Updated: 2024/06/01 20:38:52 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "matrix.h"
#include "loader.h"
#include "mlx_utilities.h"
#include "fdf_engine/fdf_engine.h"
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>


/*
 *  t_matrix a = matrix_create(3,2);
    a.matrix[0][0] = sqrt(3)/2;
    a.matrix[0][1] = -sqrt(3)/2;
    a.matrix[0][2] = 0;
    a.matrix[1][0] = 0.5;
    a.matrix[1][1] = 0.5;
    a.matrix[1][2] = -1;

    t_matrix point = matrix_create(1,3);
    point.matrix[0][0] = 2;
    point.matrix[1][0] = 0;
    point.matrix[2][0] = 9;
    t_matrix c = matrix_dot(a,point);
    printf("x: %f\ny: %f\n", c.matrix[0][0],c.matrix[1][0]);
    matrix_delete(c);
    matrix_delete(a);
    matrix_delete(point);

    t_mapdim maDim = get_map_dimension("test_maps/42.fdf");
    printf("Y: %d\n X: %d\n", maDim.y, maDim.x);
    int *data = load_map("test_maps/42.fdf");
    for(int i = 0; i <= maDim.x*maDim.y; i++) {
        printf(" %02d ", data[i]);
        if(i % maDim.x == 0) printf("\n");
    }
 */

static void printMatrix(t_matrix mat) {
    for(int i = 0; i < mat.dim_y; i++) {
        for(int j = 0; j < mat.dim_x; j++) {
            printf(" %f ",mat.matrix[i][j]);
        }
        printf("\n");
    }
}

void ft_hook(void* param) {
    t_engine_config *engine = param;

    if(mlx_is_key_down(engine->mlx,MLX_KEY_UP)) {
        engine->state.scale += 0.1;
        calculate_state(engine);
        plot_grid(engine);
    } else if(mlx_is_key_down(engine->mlx,MLX_KEY_RIGHT)) {
        engine->state.rotation_x += 0.1;
        calculate_state(engine);
        plot_grid(engine);
    } else if(mlx_is_key_down(engine->mlx,MLX_KEY_LEFT)) {
        engine->state.rotation_x -= 0.1;
        calculate_state(engine);
        plot_grid(engine);
    } else if(mlx_is_key_down(engine->mlx,MLX_KEY_DOWN)) {
        engine->state.rotation_z += 0.1;
        calculate_state(engine);
        plot_grid(engine);
    } else if(mlx_is_key_down(engine->mlx,MLX_KEY_W)) {
        engine->state.translation_y += 10;
        calculate_state(engine);
        plot_grid(engine);
    }else if(mlx_is_key_down(engine->mlx,MLX_KEY_S)) {
        engine->state.translation_y -= 10;
        calculate_state(engine);
        plot_grid(engine);
    }else if(mlx_is_key_down(engine->mlx,MLX_KEY_D)) {
        engine->state.translation_x -= 10;
        calculate_state(engine);
        plot_grid(engine);
    }else if(mlx_is_key_down(engine->mlx,MLX_KEY_A)) {
        engine->state.translation_x += 10;
        calculate_state(engine);
        plot_grid(engine);
    }
}



int main(int argc, char *argv[]) {
    t_engine_config *engine = init_engine(1920,1080,"FdF","test_maps/42.fdf");
    engine->state.scale = 1;
    engine->state.translation_y = 0;
    engine->state.translation_x = 0;
    calculate_state(engine);
    printMatrix(engine->affine);
    plot_grid(engine);
    mlx_loop_hook(engine->mlx,ft_hook,engine);
    mlx_loop(engine->mlx);
    mlx_terminate(engine->mlx);
    return 0;
}
