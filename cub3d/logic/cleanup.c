/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 10:47:37 by aiglesia          #+#    #+#             */
/*   Updated: 2020/12/06 16:51:05 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int cleanup(cub3d *data)
{
	t_data          **cursor;
	int i;
	
	i = 0;
	cursor = data->mlx_data.cursor;
	if (cursor)
	{
		while (i < 8)
		{
			free_image(data->mlx_data.mlx_ptr, cursor[i]);
			i++;
		}
		free(cursor);
	}
	if (data->mlx_data.health_bar.image)
	free_image(data->mlx_data.mlx_ptr, data->mlx_data.health_bar.image);
	if (data->mlx_data.background)
	free_image(data->mlx_data.mlx_ptr, data->mlx_data.background);
	if (data->mlx_data.map)
	free_image(data->mlx_data.mlx_ptr, data->mlx_data.map);
	free_render_data(&data->render_data, data->mlx_data.mlx_ptr);
	if (data->mlx_data.win_ptr)
		mlx_destroy_window(data->mlx_data.mlx_ptr, data->mlx_data.win_ptr);
	mlx_destroy_display(data->mlx_data.mlx_ptr);
	free(data->mlx_data.mlx_ptr);
	exit(0);
	return (0);
}
