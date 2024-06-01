/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:32:46 by lsorg             #+#    #+#             */
/*   Updated: 2024/06/01 15:08:06 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Lewin Sorg on 4/22/24.
//
#include "matrix.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include <fcntl.h>

#ifndef FDF_MAPPER_H
#define FDF_MAPPER_H

typedef struct {
    u_int32_t x;
    u_int32_t y;
} t_mapdim;

int *load_map(char *filename, t_mapdim mapDim);
t_mapdim get_map_dimension(char *filename);

#endif //FDF_MAPPER_H
