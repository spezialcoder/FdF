/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:33:12 by lsorg             #+#    #+#             */
/*   Updated: 2024/06/02 17:23:53 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Lewin Sorg on 4/22/24.
//

#include "matrix.h"

// Col x Row
t_matrix matrix_create(uint32 dim_x, uint32 dim_y) {
    double** result;
    uint32 temp;

    temp = dim_y;
    result = ft_calloc(dim_y, sizeof(double*));
    while(temp--) {
        result[temp] = ft_calloc(dim_x,sizeof(double));
    }

    return ((t_matrix) {
        .matrix = result,
        .dim_x = dim_x,
        .dim_y = dim_y
    });
}


void matrix_delete(t_matrix matrix) {
    int idx;

    idx = 0;
    while(idx < matrix.dim_y)
        free(matrix.matrix[idx++]);
    free(matrix.matrix);
}

t_matrix matrix_dot(t_matrix a, t_matrix b) {
    t_matrix result;
    uint32 i;
    uint32 j;
    uint32 k;

    j = 0;
    k = 0;
    i = 0;
    if(a.dim_x != b.dim_y)
        return ((t_matrix){.matrix=NULL,.dim_x=0,.dim_y=0});
    result = matrix_create(b.dim_x,a.dim_y);
    while(i < a.dim_y) {
        while(j < b.dim_x) {
            while(k < a.dim_x) {
                result.matrix[i][j] += a.matrix[i][k] * b.matrix[k][j];
                k++;
            }
            j++;
            k = 0;
        }
        i++;
        j = k = 0;
    }
    return (result);
}

t_matrix matrix_dot_ex(t_matrix a, t_matrix b, t_matrix result) {
    uint32 i;
    uint32 j;
    uint32 k;
    t_matrix tmp;

    tmp = matrix_create(b.dim_x,a.dim_y);
    j = 0;
    k = 0;
    i = 0;
    if(a.dim_x != b.dim_y)
        return ((t_matrix){.matrix=NULL,.dim_x=0,.dim_y=0});
    while(i < a.dim_y) {
        while(j < b.dim_x) {
            while(k < a.dim_x) {
                tmp.matrix[i][j] += a.matrix[i][k] * b.matrix[k][j];
                k++;
            }
            j++;
            k = 0;
        }
        i++;
        j = k = 0;
    }
    matrix_copy(tmp,result);
    matrix_delete(tmp);
    return (result);
}

void matrix_copy(t_matrix src, t_matrix dest) {
    int x;
    int y;

    if(src.dim_x != dest.dim_x
    || src.dim_y != dest.dim_y)
        return;
    y = 0;
    while(y < src.dim_y) {
        x = 0;
        while(x < src.dim_x) {
            dest.matrix[y][x] = src.matrix[y][x];
            x++;
        }
        y++;
    }
}