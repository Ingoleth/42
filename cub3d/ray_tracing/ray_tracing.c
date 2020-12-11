/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 12:13:52 by user42            #+#    #+#             */
/*   Updated: 2020/12/10 13:08:39 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float	calculate_collision(float angle, cub3d *data, float x, float y)
{
	float beta;

	beta = fabsf(data->render_data.view_angle - angle);
	data->ray_trc.sector = get_sector(angle);
	data->ray_trc.angle = angle;
	data->ray_trc.tan_y = handle_tan(angle);
	data->ray_trc.tan_x = 1 / data->ray_trc.tan_y;
	if (data->ray_trc.sector == 0)
		calculate_collision_0(x, y, &data->ray_trc, data->render_data.map);
	else if (data->ray_trc.sector == 1)
		calculate_collision_1(x, y, &data->ray_trc, data->render_data.map);
	else if (data->ray_trc.sector == 2)
		calculate_collision_2(x, y, &data->ray_trc, data->render_data.map);
	else if (data->ray_trc.sector == 3)
		calculate_collision_3(x, y, &data->ray_trc, data->render_data.map);
	x = fabsf((data->ray_trc.x_collision - data->render_data.player_x)
	/ cosf(angle));
	y = fabsf((data->ray_trc.y_collision - data->render_data.player_y) /
	sinf(angle));
	x = fabsf(x * cosf(beta));
	y = fabsf(y * cosf(beta));
	return (x > y ? y : x);
}

int		handle_jump(t_bool *is_jumping, float *start_time)
{
	int		y_offset;
	float	time;

	if (!*start_time)
		*start_time = (float)clock() / CLOCKS_PER_SEC - *start_time;
	time = (float)clock() / CLOCKS_PER_SEC - *start_time;
	if (time > 0.7)
	{
		*is_jumping = false;
		*start_time = 0;
		return (0);
	}
	if (time < 0.1)
		y_offset = -5 * sinf(time / 0.1 * PI);
	else if (time < 0.6)
		y_offset = 60 * sinf((time - 0.1) / 0.5 * PI);
	else
		y_offset = -7 * sinf((time - 0.6) / 0.1 * PI);
	return (y_offset);
}

void	draw_ceiling(s_coords coords, s_render_data *render_data,
t_data *background)
{
	float	distance;
	int		y_res_2;

	y_res_2 = coords.end_y / 2;
	while (coords.y <= y_res_2)
	{
		distance = render_data->column_height / ((y_res_2 - coords.y) * 2);
		while (coords.x < coords.end_x)
		{
			if (distance <= render_data->distance_array[coords.x])
				draw_pixel(background, coords.x, coords.y, add_shade(
			render_data->c_rgb, distance, render_data->shade_distance));
			coords.x++;
		}
		coords.y++;
		coords.x = 0;
	}
}

void	draw_floor(s_coords coords, s_render_data *render_data,
t_data *background)
{
	float	distance;
	int		res_y_2;

	res_y_2 = coords.end_y / 2;
	while (coords.y > res_y_2)
	{
		distance = render_data->column_height / ((coords.y - res_y_2) * 2);
		while (coords.x < coords.end_x)
		{
			if (distance < render_data->distance_array[coords.x])
				draw_pixel(background, coords.x, coords.y, add_shade(
			render_data->f_rgb, distance, render_data->shade_distance));
			coords.x++;
		}
		coords.y--;
		coords.x = 0;
	}
}

void	ray_trace(cub3d *data)
{
	int		i;
	float	angle;
	float	distance_array[data->render_data.res_x];
	float	y_offset;

	i = 0;
	y_offset = data->render_data.y_angle * data->render_data.column_height;
	if (data->mlx_data.keys_pressed.jump)
		y_offset += handle_jump(&data->mlx_data.keys_pressed.jump,
		&data->ray_trc.jump_time);
	while (i < data->render_data.res_x)
	{
		angle = data->render_data.view_angle - atan(tan(FOV / 2.0) *
		(2.0 * i / data->render_data.res_x - 1.0));
		angle = angle < 0 ? PI2 + angle : angle;
		angle = angle > PI2 ? angle - PI2 : angle;
		distance_array[i] = calculate_collision(angle, data,
		data->render_data.player_x, data->render_data.player_y);
		if (!distance_array[i])
			distance_array[i] = 0.001;
		draw_column(i, distance_array[i], data, y_offset);
		i++;
	}
	data->render_data.distance_array = distance_array;
	draw_sprites_and_ceiling(data, y_offset, distance_array);
}
