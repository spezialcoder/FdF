/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:33:12 by lsorg             #+#    #+#             */
/*   Updated: 2024/06/03 20:45:45 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdlib.h>
#include "../lib/libft/libft.h"

typedef unsigned char       uint8;
typedef unsigned short     uint16;
typedef unsigned int       uint32;
typedef unsigned long long uint64;

typedef struct {
    double** matrix;
    uint32 dim_x;
    uint32 dim_y;
} t_matrix;

t_matrix matrix_create(uint32 dim_x, uint32 dim_y);
t_matrix matrix_create(uint32 dim_x, uint32 dim_y);
void matrix_delete(t_matrix matrix);
t_matrix matrix_dot(t_matrix a, t_matrix b);
t_matrix matrix_dot_ex(t_matrix a, t_matrix b, t_matrix result);
void matrix_copy(t_matrix src, t_matrix dest);
t_matrix matrix_dot_ex_restrict(t_matrix a, t_matrix b, t_matrix result);