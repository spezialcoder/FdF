/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_engine_heatmap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 19:46:39 by lsorg             #+#    #+#             */
/*   Updated: 2024/06/02 21:12:10 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_engine.h"

uint32_t calculate_color(int max, int min, int value) {
    uint32_t color;

    color = 0xFFFF;
    color |= ((0xFF/max)*value)<<24;
    return (color);
}