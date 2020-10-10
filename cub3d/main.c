/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 19:44:52 by user42            #+#    #+#             */
/*   Updated: 2020/10/10 14:21:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stdio.h"

int main (void)
{
	cub3d data;

	data.mlx_data.mlx_ptr = mlx_init();
	initialize_render_data(&data.mlx_data, &data);
	if (!(data.render_data))
		return (0);
	mlx_mouse_hide(data.mlx_data.mlx_ptr, data.mlx_data.win_ptr);
	mlx_key_hook(data.mlx_data.win_ptr, handle_keys, &data);
	mlx_hook(data.mlx_data.win_ptr, 8, 1L<<5, handle_mouse, &data);
	//mlx_mouse_hook(data.mlx_data.win_ptr, handle_mouse, &data);
	//mlx_loop_hook(data.mlx_data.mlx_ptr, redraw_screen, &data); Need to do something to avoid excessive redraws...
	mlx_hook(data.mlx_data.win_ptr, 17, 1L<<2, close_window, &data);
	mlx_loop(data.mlx_data.mlx_ptr);
	free_render_data(data.render_data);
	return (0);
}