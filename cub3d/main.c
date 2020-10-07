/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 19:44:52 by user42            #+#    #+#             */
/*   Updated: 2020/10/07 22:14:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stdio.h"

int main (void)
{
	s_render_data *render_data;
	s_mlx mlx_data;

	mlx_data.mlx_ptr = mlx_init();
	if (!(render_data = read_file("/home/user42/Documents/cub3d/map")) ||
	check_render_data(render_data, mlx_data.mlx_ptr))
		return ((int)free_render_data(render_data));
	mlx_data.win_ptr = mlx_new_window(mlx_data.mlx_ptr, render_data->res_x, render_data->res_y, "Cub3d");
	render_floor_ceiling(render_data, &mlx_data);
	render_map(render_data->map, &mlx_data, render_data->res_x, render_data->res_y);
	mlx_key_hook(mlx_data.win_ptr, close_window, &mlx_data);
	mlx_loop(mlx_data.mlx_ptr);
	free_render_data(render_data);
	return (0);
}

int close_window (int keycode, s_mlx *mlx_data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(mlx_data->mlx_ptr, mlx_data->win_ptr);
		exit(0); //Remember to free memory and all that!
	}
	return(0);
}