/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:32:46 by lsorg             #+#    #+#             */
/*   Updated: 2024/04/22 15:32:46 by lsorg            ###   ########.fr       */
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

t_matrix **loadMap(char *map);

#endif //FDF_MAPPER_H
