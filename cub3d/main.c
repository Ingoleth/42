/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 19:44:52 by user42            #+#    #+#             */
/*   Updated: 2020/12/11 13:32:49 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(void)
{
	cub3d data;

	ft_memset(&data, 0, sizeof(cub3d));
	if (!(data.mlx_data.mlx_ptr = mlx_init()) || !initialize_render_data(
		&data.mlx_data, &data, "/home/user42/Documents/42/cub3d/map.cub")) //TODO take from parameter!
		cleanup(&data);
	mlx_hook(data.mlx_data.win_ptr, 2, 1L << 0, on_key_pressed, &data);
	mlx_hook(data.mlx_data.win_ptr, 3, 1L << 1, on_key_released,
	&data.mlx_data);
	mlx_hook(data.mlx_data.win_ptr, 17, 1L << 2, cleanup, &data);
	mlx_hook(data.mlx_data.win_ptr, 9, 1L << 21, redraw_screen, &data);
	mlx_loop_hook(data.mlx_data.mlx_ptr, check_keys, &data);
	mlx_loop(data.mlx_data.mlx_ptr);
}
