/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utilities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:12:17 by lsorg             #+#    #+#             */
/*   Updated: 2024/06/06 15:51:35 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Lewin Sorg on 4/18/24.
//

#include "mlx_utilities.h"

inline int	abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static inline int	ternary(int val, int val2, int o1, int o2)
{
	if (val < val2)
		return (o1);
	return (o2);
}

static inline void	put_pixel(mlx_image_t *image, int x, int y, uint32_t color)
{
	if (x > 0 && y > 0 && x < (int)image->width && y < (int)image->height)
		mlx_put_pixel(image, x, y, color);
}

void	img_draw_line(mlx_image_t *image, t_position start, t_position end,
		u_int32_t color)
{
	t_algdata	rtd;
	int			e2;

	rtd.dx = abs(end.x - start.x);
	rtd.dy = abs(end.y - start.y);
	rtd.sx = ternary(start.x, end.x, 1, -1);
	rtd.sy = ternary(start.y, end.y, 1, -1);
	rtd.err = rtd.dx - rtd.dy;
	while (!(start.x == end.x && start.y == end.y))
	{
		put_pixel(image, start.x, start.y, color);
		e2 = 2 * rtd.err;
		if (e2 > -rtd.dy)
		{
			rtd.err -= rtd.dy;
			start.x += rtd.sx;
		}
		if (e2 < rtd.dx)
		{
			rtd.err += rtd.dx;
			start.y += rtd.sy;
		}
	}
	put_pixel(image, start.x, start.y, color);
}
