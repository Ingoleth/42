/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 19:44:52 by user42            #+#    #+#             */
/*   Updated: 2020/11/27 18:42:12 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stdio.h"

int main (void)
{
	cub3d data;

	ft_memset(&data, 0, sizeof(cub3d));
	if (!(data.mlx_data.mlx_ptr = mlx_init()) ||
	!initialize_render_data(&data.mlx_data, &data, "/home/user42/Documents/42/cub3d/map.cub"))
		exit(-1);
	mlx_mouse_hide(data.mlx_data.mlx_ptr, data.mlx_data.win_ptr);
	mlx_hook(data.mlx_data.win_ptr, 2, 1L<<0, on_key_pressed, &data);
	mlx_hook(data.mlx_data.win_ptr, 3, 1L<<1, on_key_released, &data.mlx_data);
	mlx_hook(data.mlx_data.win_ptr, 17, 1L<<2, close_window, &data);
	mlx_loop_hook(data.mlx_data.mlx_ptr, check_keys, &data);
	mlx_loop(data.mlx_data.mlx_ptr);

}