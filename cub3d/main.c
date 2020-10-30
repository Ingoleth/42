/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 19:44:52 by user42            #+#    #+#             */
/*   Updated: 2020/10/30 12:36:58 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stdio.h"

void cleanup(cub3d *data)
{
	t_data          **cursor;
	int i;
	
	i = 0;
	cursor = data->mlx_data.cursor;
	while (i < 8)
	{
		mlx_destroy_image(data->mlx_data.mlx_ptr, cursor[i]->img);
		i++;
	}
	free(cursor);
	free_image(data->mlx_data.mlx_ptr, data->mlx_data.background);
	free_image(data->mlx_data.mlx_ptr, data->mlx_data.map);
	mlx_destroy_window(data->mlx_data.mlx_ptr, data->mlx_data.win_ptr);
	mlx_destroy_display(data->mlx_data.mlx_ptr);
	free(data->mlx_data.mlx_ptr);
	free_render_data(data->render_data);
	exit(0);
}

int main (void)
{
	cub3d data;

	if (!(data.mlx_data.mlx_ptr = mlx_init()))
		exit(-1);
	initialize_render_data(&data.mlx_data, &data);
	if (!(data.render_data))
		exit(-1);
	cleanup(&data);
	mlx_mouse_hide(data.mlx_data.mlx_ptr, data.mlx_data.win_ptr);
	mlx_hook(data.mlx_data.win_ptr, 2, 1L<<0, handle_keys, &data);
	mlx_hook(data.mlx_data.win_ptr, 17, 1L<<2, close_window, &data);
	mlx_loop(data.mlx_data.mlx_ptr);
}