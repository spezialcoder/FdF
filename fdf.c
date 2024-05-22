/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:54:40 by lsorg             #+#    #+#             */
/*   Updated: 2024/04/30 19:02:20 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "matrix.h"
#include "MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    t_matrix a = matrix_create(3,2);
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
}
