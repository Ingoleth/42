/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 12:13:52 by user42            #+#    #+#             */
/*   Updated: 2020/12/20 11:51:07 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	calculate_collision(float angle, t_cub3d *data, float x, float y)
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

void	get_distance_and_offset(t_cub3d *data, float *distance_array,
float *offset_array, int *dir_array)
{
	int		i;
	float	angle;

	i = 0;
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
		if (data->ray_trc.cardinal_collision == NORTH ||
		data->ray_trc.cardinal_collision == SOUTH)
			offset_array[i] = data->ray_trc.x_collision
			- (int)data->ray_trc.x_collision;
		else
			offset_array[i] = data->ray_trc.y_collision
			- (int)data->ray_trc.y_collision;
		dir_array[i] = data->ray_trc.cardinal_collision;
		i++;
	}
}

void	ray_trace(t_cub3d *data)
{
	float	distance_array[data->render_data.res_x];
	float	offset_array[data->render_data.res_x];
	int		dir_array[data->render_data.res_x];
	float	y_offset;

	y_offset = data->render_data.y_angle * data->render_data.column_height;
	if (data->mlx_data.keys_pressed.jump)
		y_offset += handle_jump(&data->mlx_data.keys_pressed.jump,
		&data->ray_trc.jump_time);
	data->render_data.y_offset = y_offset;
	get_distance_and_offset(data, distance_array, offset_array, dir_array);
	draw_floor_and_ceiling(data, y_offset, distance_array);
	draw_walls(data, distance_array, offset_array, dir_array);
	draw_sprites(data, distance_array, y_offset);
}
