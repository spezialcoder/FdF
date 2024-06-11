/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:32:46 by lsorg             #+#    #+#             */
/*   Updated: 2024/06/06 15:37:59 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Lewin Sorg on 4/22/24.
//

#pragma once
#include "lib/libft/get_next_line.h"
#include "lib/libft/libft.h"
#include "matrix/matrix.h"
#include <fcntl.h>

typedef struct s_mapdim
{
	u_int32_t	x;
	u_int32_t	y;
	int			max;
	int			min;
}				t_mapdim;

typedef struct s_map_vertex
{
	int			value;
	uint32_t	color;
}				t_map_vertex;

t_mapdim		get_map_dimension(char *filename);
t_map_vertex	*load_map(char *filename, t_mapdim mapDim);
