/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:33:12 by lsorg             #+#    #+#             */
/*   Updated: 2024/06/05 15:33:36 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../lib/libft/libft.h"
#include <stdlib.h>

typedef unsigned char		t_uint8;
typedef unsigned short		t_uint16;
typedef unsigned int		t_uint32;
typedef unsigned long long	t_uint64;

typedef struct s_matrix
{
	double					**matrix;
	t_uint32				dim_x;
	t_uint32				dim_y;
}							t_matrix;

typedef struct s_iterator
{
	t_uint32						j;
	t_uint32						k;
	t_uint32						i;
}							t_iterator;

t_matrix					matrix_create(t_uint32 dim_x, t_uint32 dim_y);
t_matrix					matrix_create(t_uint32 dim_x, t_uint32 dim_y);
void						matrix_delete(t_matrix matrix);
t_matrix					matrix_dot(t_matrix a, t_matrix b);
t_matrix					matrix_dot_ex(t_matrix a, t_matrix b,
								t_matrix result);
void						matrix_copy(t_matrix src, t_matrix dest);
t_matrix					matrix_dot_ex_restrict(t_matrix a, t_matrix b,
								t_matrix result);