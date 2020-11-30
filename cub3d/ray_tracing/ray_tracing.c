/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 12:13:52 by user42            #+#    #+#             */
/*   Updated: 2020/11/30 16:35:52 by aiglesia         ###   ########.fr       */
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
        x = aux2->sprite_x - data->render_data.player_x;
        y = -(aux2->sprite_y - data->render_data.player_y);
        aux2->angle =  data->render_data.view_angle - atanf(y / x);
        aux2->distance = (sqrtf(x * x + y * y) * fabsf(cos(aux2->angle)));
        aux = aux->next;
    }
}

int get_sprite_colour(cub3d *data, int x, int y, t_sprite *sprite)
{
    t_data *image;
    float image_x;
    float image_y;

    if (sprite->texture == '2')
        image = &data->render_data.sprite1;
    else if (sprite->texture == '3')
       image = &data->render_data.sprite2;
    else
       image = &data->render_data.sprite3;
    image_x = ((x - sprite->sprite_center_x + sprite->size_half) / (float)sprite->size_half / 2) * image->width;
    image_y = (y / ((float)sprite->size_half * 2)) * image->height;
    return(get_pixel(image, image_x, image_y));
}

void draw_sprite_column(int drawing_position, t_sprite *sprite, cub3d *data)
{
    int y_draw_coord;
    int y_position;
    int size;
    int pixel;

    size = sprite->size_half * 2;
    y_position = 0;
    y_draw_coord = sprite->sprite_center_y - sprite->size_half;
    while (y_draw_coord < 0)
    {
        y_position++;
        y_draw_coord++;
    }
    while (y_position < size && y_draw_coord < data->render_data.res_y)
    {
        pixel = get_sprite_colour(data, drawing_position, y_position, sprite);
        if (pixel != 0 && pixel != -16777216) //Double check
            draw_pixel(data->mlx_data.background, drawing_position, y_draw_coord, pixel);
        y_position++;
        y_draw_coord++;
    }
    
}

void    draw_sprite(cub3d *data, t_sprite *sprite, float *distance_array)
{
    int drawing_position;

    sprite->sprite_center_x = (tan(sprite->angle) / tan(FOV / 2) + 1) * data->render_data.res_x / 2;
    sprite->size_half = data->ray_trc.column_height / (sprite->distance);
    sprite->sprite_center_y = data->render_data.res_y / 2 + (data->render_data.res_y / 2) / sprite->distance - sprite->size_half;
    drawing_position = sprite->sprite_center_x - sprite->size_half > 0 ? sprite->sprite_center_x - sprite->size_half : 0;
    while (drawing_position < sprite->sprite_center_x  + sprite->size_half && drawing_position < data->render_data.res_x)
    {
        if (distance_array[drawing_position] > sprite->distance)
            draw_sprite_column(drawing_position, sprite, data);
        drawing_position++;
    }
}

void    order_sprites(t_list *sprite)
{
    t_list *aux;
    int i;

    i = 1;
    while (i)
    {
        i = 0;
        aux = sprite;
        if (aux->next)
        while (aux)
        {
            if (aux->next && ((t_sprite *)aux->next->content)->distance > ((t_sprite *)aux->content)->distance)
            {
                i = 1;
                ft_lstmove_backwards(aux);
            }
            aux = aux->next;
        }
    }  
}   

void    draw_sprites(cub3d *data, float *distance_array)
{
    t_list *aux;
    int i;

    aux = data->ray_trc.sprite;
    get_sprite_distance(data);
    order_sprites(aux);
    while (aux)
    {
        draw_sprite(data, aux->content, distance_array);
        aux = aux->next;
    }
    i = 0 + 1;
    aux += i;
    ft_lstclear(&data->ray_trc.sprite, free);
}

void    ray_trace(cub3d *data)
{
    int i;
    float angle;
    float distance_array[data->render_data.res_x];
    
    i = 0;
    while (i < data->render_data.res_x)
    {
        angle = data->render_data.view_angle - atan(tan(FOV / 2.0) * (2.0 * i / data->render_data.res_x - 1.0));
        angle = angle < 0 ? PI2 + angle : angle;
        angle = angle > PI2 ? angle - PI2 : angle;
        distance_array[i] = calculate_collision(angle, data);
        draw_column(i, distance_array[i], data);
        i++;
    }
    if (data->ray_trc.sprite)
        draw_sprites(data, distance_array);
}