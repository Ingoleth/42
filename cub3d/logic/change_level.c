/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_level.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 19:57:29 by aiglesia          #+#    #+#             */
/*   Updated: 2020/12/08 10:25:33 by aiglesia         ###   ########.fr       */
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
	free(map_path);
	data->render_data.res_x = aux.res_x;
	data->render_data.res_y = aux.res_y;
	data->render_data.current_health = aux.current_health;
	data->render_data.column_height = aux.column_height;
	data->render_data.shade_distance = 0;
	free_image(data->mlx_data.mlx_ptr, data->mlx_data.map);
	load_map(data->render_data.map, mlx_data, data->render_data.res_x, data->render_data.res_y);
}

void transition_to_level(cub3d *data)
{
	static float time_init;
	float time;
	static t_bool controller = 0;

	if (time_init == 0)
		time_init = (float)clock() / CLOCKS_PER_SEC;
	time = (float)clock() / CLOCKS_PER_SEC - time_init;
	if (controller == 0)
	{
		if (time < FADE_TIME)
		{
			data->render_data.shade_distance = SHADE_DISTANCE - SHADE_DISTANCE * (time / FADE_TIME);
			return ;
		}
		controller = 1;
	}
	if (controller == 1)
	{
		if (!data->render_data.extra_level)
			cleanup(data);
		printf("%s\n", data->render_data.extra_level);
		change_level(data, ft_strdup(data->render_data.extra_level));
		controller = 2;
		time_init = 0;
		return ;
	}
	if (time < FADE_TIME)
	{
		data->render_data.shade_distance = SHADE_DISTANCE * (time / FADE_TIME);
		return ;
	}
	controller = 0;
	time_init = 0;
	data->render_data.shade_distance = SHADE_DISTANCE;
	data->mlx_data.keys_pressed.transition = false;
}