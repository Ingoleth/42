/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 12:13:52 by user42            #+#    #+#             */
/*   Updated: 2020/12/18 12:57:22 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	draw_background(cub3d *data)
{
	draw_pixel_area(data->mlx_data.background, set_draw_coords(0, 0,
	data->render_data.res_x, data->render_data.res_y / 2),
	data->render_data.c_rgb);
	draw_pixel_area(data->mlx_data.background, set_draw_coords(0,
	data->render_data.res_y / 2, data->render_data.res_x,
	data->render_data.res_y), data->render_data.f_rgb);
}

void	ray_trace(cub3d *data)
{
	float	distance_array[data->render_data.res_x];
	float	y_offset;
	int		i;
	float	angle;

	y_offset = 0;
	i = 0;
	draw_background(data);
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
		draw_column(i, distance_array[i], data, 0);
		i++;
	}
	draw_sprites(data, distance_array, y_offset);
}
