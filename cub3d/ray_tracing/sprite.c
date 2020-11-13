/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:06:53 by aiglesia          #+#    #+#             */
/*   Updated: 2020/11/13 18:39:58 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_sprite_data(int x, int y, s_ray_tracing * ray_trc, t_bool horiz)
{
	if (horiz)
	{
		ray_trc->sprite = 1; // Add the number on the tile to get multiple objects!
		ray_trc->sprite_x = ray_trc->x_collision;
		ray_trc->sprite_y = y;
	}
	else
	{
		ray_trc->sprite = -1;
		ray_trc->sprite_x = x;
		ray_trc->sprite_y = ray_trc->y_collision;
	}	
}

t_bool check_wall_collision(int x, int y, char **map, s_ray_tracing * ray_trc)
{
	if(map[y][x] == '1')
		return (true);
	if (map[y][x] == '2')
	{
		if (ray_trc->sector == 0) // add here the value of the tile so you can have multiple objects!
			set_sprite_data(x, y, ray_trc, ray_trc->x_collision - x <= 1 + y - ray_trc->y_collision);
		else if (ray_trc->sector == 1)
			set_sprite_data(x, y, ray_trc, 1 + x - ray_trc->x_collision <= 1 + y - ray_trc->y_collision);
		else if (ray_trc->sector == 2)
			set_sprite_data(x, y, ray_trc, 1 + x - ray_trc->x_collision <= ray_trc->y_collision - y);
		else
			set_sprite_data(x, y, ray_trc, ray_trc->x_collision - x <= ray_trc->y_collision - y);
	}
	return (0);
}

unsigned int get_sprite_colour(cub3d *data, int column_size, int img_y)
{
	t_data *image;
	int x;
	int y;
	float max_size;

	image = &data->render_data->sprite;
	max_size = fabs(cos(data->render_data->view_angle)) + fabs(cos(data->render_data->view_angle));
	x = (int)(image->width * (get_sprite_horizontal_lenght(&data->ray_trc, data->render_data->view_angle) / max_size));
	y = (int)(image->height * (0.5 + (0.5 * img_y / column_size)));

	return (get_pixel(image, x, y)); // Add a check to only return something if non-transparent!
}

void draw_sprite_column(int i, cub3d *data)
{
	int y_axis;
	int column_size;
	int max_draw_height;
	int j;
	float distance;

	distance = data->ray_trc.sprite == 1 ? fabs(data->ray_trc.sprite_y + 0.5 - data->render_data->player_y) * data->ray_trc.tan_y :
	fabs(data->ray_trc.sprite_x + 0.5 - data->render_data->player_x) * data->ray_trc.tan_x;
	y_axis = data->render_data->res_y / 2;
	column_size = (int)(data->ray_trc.column_height / (2 * distance));
	max_draw_height = column_size > y_axis / 2 ? y_axis / 2 : column_size;
	j = 0;
	while (j < max_draw_height) //Move to a different function, check for sprite in a while to avoid double drawing...
	{
		draw_pixel(data->mlx_data.background, i, y_axis + j, add_shade(get_sprite_colour(data, column_size, j), distance));
		draw_pixel(data->mlx_data.background, i, y_axis - j, add_shade(get_sprite_colour(data, column_size, -j), distance));
		j++;
	}
}