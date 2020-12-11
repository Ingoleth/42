/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_drawing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 11:13:27 by aiglesia          #+#    #+#             */
/*   Updated: 2020/12/10 12:12:27 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_sprite_distance(cub3d *data)
{
	t_list		*aux;
	t_sprite	*aux2;
	float		x;
	float		y;

	aux = data->ray_trc.sprite;
	while (aux)
	{
		aux2 = (t_sprite *)aux->content;
		x = aux2->sprite_x - data->render_data.player_x;
		y = -(aux2->sprite_y - data->render_data.player_y);
		aux2->angle = data->render_data.view_angle - atanf(y / x);
		aux2->distance = (sqrtf(x * x + y * y) * fabsf(cosf(aux2->angle)));
		aux = aux->next;
	}
}

int		get_sprite_colour(cub3d *data, int x, int y, t_sprite *sprite)
{
	t_data	*image;
	float	image_x;
	float	image_y;

	if (sprite->texture == '2')
		image = &data->render_data.sprite1;
	else if (sprite->texture == '3')
		image = &data->render_data.sprite2;
	else
		image = &data->render_data.sprite3;
	image_x = ((x - sprite->sprite_center_x + sprite->size_half) /
	(float)sprite->size_half / 2) * image->width;
	image_y = (y / ((float)sprite->size_half * 2)) * image->height;
	return (get_pixel(image, image_x, image_y));
}

void	draw_sprite_column(int drawing_position, t_sprite *sprite, cub3d *data,
int y_offset)
{
	int y_draw_coord;
	int y_position;
	int size;
	int pixel;

	size = sprite->size_half * 2;
	y_position = 0;
	y_draw_coord = sprite->sprite_center_y - sprite->size_half + y_offset;
	while (y_draw_coord < 0)
	{
		y_position++;
		y_draw_coord++;
	}
	while (y_position < size && y_draw_coord < data->render_data.res_y)
	{
		pixel = get_sprite_colour(data, drawing_position, y_position, sprite);
		if (pixel != 0 && pixel != -16777216)
			draw_pixel(data->mlx_data.background, drawing_position,
		y_draw_coord,
		add_shade(pixel, sprite->distance, data->render_data.shade_distance));
		y_position++;
		y_draw_coord++;
	}
}

void	draw_sprite(cub3d *data, t_sprite *sprite, float *distance_array,
float time)
{
	int drawing_position;

	sprite->sprite_center_x = (tan(sprite->angle) / tan(FOV / 2) + 1) *
	data->render_data.res_x / 2;
	sprite->size_half = data->render_data.column_height / (sprite->distance);
	sprite->sprite_center_y = data->render_data.res_y / 2 +
	(data->render_data.res_y / 2) / sprite->distance - sprite->size_half;
	drawing_position = sprite->sprite_center_x - sprite->size_half > 0
	? sprite->sprite_center_x - sprite->size_half : 0;
	while (drawing_position < sprite->sprite_center_x + sprite->size_half &&
	drawing_position < data->render_data.res_x)
	{
		if (distance_array[drawing_position] > sprite->distance)
			draw_sprite_column(drawing_position, sprite, data, time);
		drawing_position++;
	}
}

void	draw_sprites(cub3d *data, float *distance_array, float time)
{
	t_list *aux;

	aux = data->ray_trc.sprite;
	if (!aux)
		return ;
	get_sprite_distance(data);
	order_sprites(aux);
	while (aux)
	{
		draw_sprite(data, aux->content, distance_array, time);
		aux = aux->next;
	}
	ft_lstclear(&data->ray_trc.sprite, free);
}
