/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 19:44:52 by user42            #+#    #+#             */
/*   Updated: 2020/10/08 14:51:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stdio.h"

int main (void)
{
	s_render_data *render_data;
	s_mlx mlx_data;
	cub3d data;

	data.render_data = render_data;
	data.mlx_data = &mlx_data;
	mlx_data.mlx_ptr = mlx_init();
	if (!initialize_render_data(&mlx_data, render_data))
		return (0);
	printf("Hello world! mlx_data = %p; %p\n", &mlx_data, data.mlx_data);
	mlx_key_hook(mlx_data.win_ptr, close_window, &mlx_data);
	mlx_loop_hook(mlx_data.win_ptr, redraw_screen, &data);
	mlx_loop(mlx_data.mlx_ptr);
	free_render_data(render_data);
	return (0);
}

int close_window (int keycode, cub3d *data)
{
	s_mlx *mlx_data;

	mlx_data = data->mlx_data;
	printf("Hello world! mlx_data = %p; %p\n", mlx_data, data->mlx_data);
	if (keycode == ESC)
	{
		mlx_destroy_window(mlx_data->mlx_ptr, mlx_data->win_ptr);
		exit(0); //Remember to free memory and all that!
	}
	else
		redraw_screen(data);
	return(0);
}