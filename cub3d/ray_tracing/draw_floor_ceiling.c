/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_ceiling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 10:41:56 by aiglesia          #+#    #+#             */
/*   Updated: 2020/12/15 15:27:43 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_ceiling(s_coords coords, s_render_data *render_data,
t_data *background, float *distance_array)
{
	float	distance;

	while (coords.y <= coords.end_y)
	{
		distance = render_data->column_height / ((coords.end_y - coords.y) * 2);
		while (coords.x < coords.end_x)
		{
			if (distance <= distance_array[coords.x] + 1)
				draw_pixel(background, coords.x, coords.y, add_shade(
			render_data->c_rgb, distance, render_data->shade_distance));
			coords.x++;
		}
		coords.y++;
		coords.x = 0;
	}
}

void	draw_floor(s_coords coords, s_render_data *render_data,
t_data *background, float *distance_array)
{
	float	distance;

	while (coords.y > coords.end_y)
	{
		distance = render_data->column_height / ((coords.y - coords.end_y) * 2);
		while (coords.x < coords.end_x)
		{
			if (distance < distance_array[coords.x] + 1)
				draw_pixel(background, coords.x, coords.y, add_shade(
			render_data->f_rgb, distance, render_data->shade_distance));
			coords.x++;
		}
		coords.y--;
		coords.x = 0;
	}
}

void	draw_floor_and_ceiling(cub3d *data, int y_offset, float *distance_array)
{
	draw_ceiling(set_draw_coords(0, 0, data->render_data.res_x,
	data->render_data.res_y / 2 + y_offset), &data->render_data,
	data->mlx_data.background, distance_array);
	draw_floor(set_draw_coords(0, data->render_data.res_y,
	data->render_data.res_x, data->render_data.res_y / 2 + y_offset),
	&data->render_data, data->mlx_data.background, distance_array);
}

void	draw_walls(cub3d *data, float *distance_array, float *offset_array,
int *dir_array)
{
	int i;

	i = 0;
	while (i < data->render_data.res_x)
	{
		data->ray_trc.img_x = offset_array[i];
		data->ray_trc.cardinal_collision = dir_array[i];
		draw_column(i, distance_array[i], data, data->render_data.y_offset);
		i++;
	}
}
