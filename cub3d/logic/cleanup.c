/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 10:47:37 by aiglesia          #+#    #+#             */
/*   Updated: 2020/10/31 10:48:14 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
