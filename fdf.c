/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:54:40 by lsorg             #+#    #+#             */
/*   Updated: 2024/06/03 21:11:02 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libft/libft.h"
#include "matrix/matrix.h"
#include "loader.h"
#include "mlx_utilities.h"
#include "fdf_engine/fdf_engine.h"
#include <stdio.h>


static void printMatrix(t_matrix mat) {
    for(uint32_t i = 0; i < mat.dim_y; i++) {
        for(uint32_t j = 0; j < mat.dim_x; j++) {
            printf(" %f ",mat.matrix[i][j]);
        }
        printf("\n");
    }
}
//TODO: Scaling depends on the map size
//TODO: Fucking colors in the map
//TODO: HEATMAP
//TODO: Some other funky shit
int main(int argc, char *argv[]) {
    if(argc < 2) {
        ft_printf("Expecting arguments: ./fdf <map>\n");
        return (0);
    }
    if(access(argv[1],F_OK)) {
        ft_printf("File not found\n");
        return (0);
    }
    t_engine_config *engine = init_engine(1920,1080,"FdF",argv[1]);
    engine->state.scale = 1;
    engine->state.translation_y = engine->mlx->height/2;
    engine->state.translation_x = engine->mlx->width/2;
    calculate_state(engine);
    printMatrix(engine->affine);
    plot_grid(engine);
    mlx_loop(engine->mlx);
    terminate_engine(engine);
    return 0;
}
