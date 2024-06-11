/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsorg <lsorg@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:54:40 by lsorg             #+#    #+#             */
/*   Updated: 2024/06/06 16:29:36 by lsorg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_engine/fdf_engine.h"
#include "lib/libft/libft.h"

int	main(int argc, char *argv[])
{
	t_engine_config	*engine;

	if (argc != 2)
	{
		ft_printf("Expecting arguments: ./fdf <map>\n");
		return (0);
	}
	if (access(argv[1], F_OK))
	{
		ft_printf("File not found\n");
		return (0);
	}
	engine = init_engine(1920, 1080, "FdF", argv[1]);
	plot_grid(engine);
	mlx_loop(engine->mlx);
	terminate_engine(engine);
	return (0);
}
