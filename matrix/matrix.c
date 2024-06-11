/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:33:12 by lsorg             #+#    #+#             */
/*   Updated: 2024/06/05 15:34:02 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Lewin Sorg on 4/22/24.
//

#include "matrix.h"

// Col x Row
t_matrix	matrix_create(t_uint32 dim_x, t_uint32 dim_y)
{
	double		**result;
	t_uint32	temp;

	temp = dim_y;
	result = ft_calloc(dim_y, sizeof(double *));
	while (temp--)
	{
		result[temp] = ft_calloc(dim_x, sizeof(double));
	}
	return ((t_matrix){.matrix = result, .dim_x = dim_x, .dim_y = dim_y});
}

void	matrix_delete(t_matrix matrix)
{
	uint32_t	idx;

	idx = 0;
	while (idx < matrix.dim_y)
		free(matrix.matrix[idx++]);
	free(matrix.matrix);
}

t_matrix	matrix_dot(t_matrix a, t_matrix b)
{
	t_matrix	result;
	t_iterator	vars;

	ft_memset(&vars, 0, sizeof(t_iterator));
	if (a.dim_x != b.dim_y)
		return ((t_matrix){.matrix = NULL, .dim_x = 0, .dim_y = 0});
	result = matrix_create(b.dim_x, a.dim_y);
	while (vars.i < a.dim_y)
	{
		while (vars.j < b.dim_x)
		{
			while (vars.k < a.dim_x)
			{
				result.matrix[vars.i][vars.j] += a.matrix[vars.i][vars.k]
					* b.matrix[vars.k][vars.j];
				vars.k++;
			}
			vars.j++;
			vars.k = 0;
		}
		vars.i++;
		vars.j = 0;
		vars.k = 0;
	}
	return (result);
}

t_matrix	matrix_dot_ex_restrict(t_matrix a, t_matrix b, t_matrix result)
{
	t_matrix	tmp;
	t_iterator	vars;

	ft_memset(&vars, 0, sizeof(t_iterator));
	if (a.dim_x != b.dim_y)
		return ((t_matrix){.matrix = NULL, .dim_x = 0, .dim_y = 0});
	tmp = matrix_create(b.dim_x, a.dim_y);
	while (vars.i < a.dim_y)
	{
		while (vars.j < b.dim_x)
		{
			while (vars.k < a.dim_x)
			{
				tmp.matrix[vars.i][vars.j] += a.matrix[vars.i][vars.k]
					* b.matrix[vars.k][vars.j];
				vars.k++;
			}
			vars.j++;
			vars.k = 0;
		}
		vars = (t_iterator){.j = 0, .k = 0, .i = vars.i + 1};
	}
	matrix_copy(tmp, result);
	matrix_delete(tmp);
	return (result);
}

void	matrix_copy(t_matrix src, t_matrix dest)
{
	uint32_t	x;
	uint32_t	y;

	if (src.dim_x != dest.dim_x || src.dim_y != dest.dim_y)
		return ;
	y = 0;
	while (y < src.dim_y)
	{
		x = 0;
		while (x < src.dim_x)
		{
			dest.matrix[y][x] = src.matrix[y][x];
			x++;
		}
		y++;
	}
}
