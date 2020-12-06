/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_level.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 19:57:29 by aiglesia          #+#    #+#             */
/*   Updated: 2020/12/06 16:35:31 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void change_level(cub3d *data, char *map_path)
{
	s_mlx *mlx_data;
	s_render_data aux;

	mlx_data = &data->mlx_data;
	aux.res_x = data->render_data.res_x;
	aux.res_y = data->render_data.res_y;
	aux.column_height = data->render_data.column_height;
	aux.current_health = data->render_data.current_health;
	free_render_data(&data->render_data, data->mlx_data.mlx_ptr);
	if (!read_file(map_path, &data->render_data, mlx_data->mlx_ptr) ||
	check_render_data(&data->render_data, mlx_data->mlx_ptr))
		cleanup(data);
	data->render_data.res_x = aux.res_x;
	data->render_data.res_y = aux.res_y;
	data->render_data.current_health = aux.current_health;
	data->render_data.column_height = aux.column_height;
	free_image(data->mlx_data.mlx_ptr, data->mlx_data.map);
	load_map(data->render_data.map, mlx_data, data->render_data.res_x, data->render_data.res_y);
	redraw_screen(data);
}