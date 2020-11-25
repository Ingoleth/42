/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 12:13:52 by user42            #+#    #+#             */
/*   Updated: 2020/11/25 12:57:38 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float calculate_collision(float angle, cub3d *data)
{
    float x;
    float y;
    float beta;

    x = data->render_data.player_x;
    y = data->render_data.player_y;
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
    x = fabsf((data->ray_trc.x_collision - data->render_data.player_x) / cosf(angle));
    return(fabsf(x * cosf(beta))); //TODO: It doesn't work on 0 / PI for obvious reasons. Add if. Or if sneaky, change the values so it nevers get there :P
}

void    get_sprite_distance(cub3d *data)
{
    t_list *aux;
    t_sprite *aux2;
    float x;
    float y;
    
    aux = data->ray_trc.sprite;
    while (aux)
    {
        aux2 = (t_sprite *)aux->content;
        x = fabsf(data->render_data.player_x - aux2->sprite_x);
        y = fabsf(data->render_data.player_y - aux2->sprite_y);
        aux2->lower_limit = fabsf(atanf(y / x));
        aux2->distance = (sqrtf(x * x + y * y) * cos(data->render_data.view_angle - aux2->lower_limit));
        aux2->upper_limit = aux2->lower_limit + fabsf(atanf(0.5 / aux2->distance));
        aux2->lower_limit = aux2->upper_limit - 2 * (aux2->upper_limit - aux2->lower_limit);
        aux = aux->next;
    }
}

int get_sprite_colour(int i)
{
    if (i == '2')
        return(RED);
    else if (i == '3')
        return(YELLOW);
    else if (i == '4')
        return(CYAN);
    else
        return(PURPLE);
    
}

void draw_sprite_column(t_sprite *sprite, int i, cub3d *data)
{
	int y_axis;
	int column_size;
	int max_draw_height;
	int j;

	y_axis = data->render_data.res_y / 2;
	column_size = (int)(data->ray_trc.column_height / sprite->distance);
	max_draw_height = column_size > y_axis ? y_axis : column_size;
	j = 0;
	while (j < max_draw_height) //Changed recently; change to see if it works properly...
	{
		draw_pixel(data->mlx_data.background, i, y_axis + j, get_sprite_colour(sprite->texture));
		draw_pixel(data->mlx_data.background, i, y_axis - j, get_sprite_colour(sprite->texture));
		j++;
	}
}

void draw_sprite(float angle, t_list *aux, int i, cub3d *data)
{
    t_sprite    *sprite;

    sprite = aux->content;
    while (aux)
    {
        if ((angle <= sprite->upper_limit && angle <= sprite->end) &&
            (angle >= sprite->lower_limit && angle >= sprite->beggining))
            draw_sprite_column(sprite, i, data);
        aux = aux->next;
        if (aux)
            sprite = aux->content;
    }
}

void    draw_sprites(cub3d *data)
{
    float angle;
    int i;
    t_list *aux;
    
    get_sprite_distance(data);
    aux = data->ray_trc.sprite;
    i = data->render_data.res_x - 1;
    while (i >= 0)
    {
        
        angle = data->render_data.view_angle - atan(tan(FOV / 2.0) * (2.0 * i / data->render_data.res_x - 1.0));
        angle = angle < 0 ? PI2 + angle : angle;
        angle = angle > PI2 ? angle - PI2 : angle;
        data->ray_trc.angle = angle;
        draw_sprite(angle, aux, i, data);
        i--;
    }
    ft_lstclear(&data->ray_trc.sprite, free);
}

void    ray_trace(cub3d *data)
{
    int i;
    float angle;
    
    i = 0;
    while (i < data->render_data.res_x)
    {
        angle = data->render_data.view_angle - atan(tan(FOV / 2.0) * (2.0 * i / data->render_data.res_x - 1.0));
        angle = angle < 0 ? PI2 + angle : angle;
        angle = angle > PI2 ? angle - PI2 : angle;
        draw_column(i, calculate_collision(angle, data), data);
        i++;
    }
    if (data->ray_trc.sprite)
        draw_sprites(data);
}