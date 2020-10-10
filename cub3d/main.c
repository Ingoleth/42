/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 19:44:52 by user42            #+#    #+#             */
/*   Updated: 2020/10/10 12:04:09 by user42           ###   ########.fr       */
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
	mlx_key_hook(data.mlx_data.win_ptr, handle_keys, &data);
	//mlx_loop_hook(data.mlx_data.mlx_ptr, redraw_screen, &data); Need to do something to avoid excessive redraws...
	mlx_loop(data.mlx_data.mlx_ptr);
	free_render_data(data.render_data);
	return (0);
}