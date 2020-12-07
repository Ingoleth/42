/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 12:13:52 by user42            #+#    #+#             */
/*   Updated: 2020/12/07 14:39:00 by aiglesia         ###   ########.fr       */
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
    y = fabsf((data->ray_trc.y_collision - data->render_data.player_y) / sinf(angle));
    x = fabsf(x * cosf(beta));
    y = fabsf(y * cosf(beta));
    return(x > y ? y : x);
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
        aux2->distance = (sqrtf(x * x + y * y) * fabsf(cosf(aux2->angle)));
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

void draw_sprite_column(int drawing_position, t_sprite *sprite, cub3d *data, int y_offset)
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
        if (pixel != 0 && pixel != -16777216) //Double check
            draw_pixel(data->mlx_data.background, drawing_position, y_draw_coord, add_shade(pixel, sprite->distance, data->render_data.shade_distance));
        y_position++;
        y_draw_coord++;
    }
    
}

void    draw_sprite(cub3d *data, t_sprite *sprite, float *distance_array, float time)
{
    int drawing_position;

    sprite->sprite_center_x = (tan(sprite->angle) / tan(FOV / 2) + 1) * data->render_data.res_x / 2;
    sprite->size_half = data->render_data.column_height / (sprite->distance);
    sprite->sprite_center_y = data->render_data.res_y / 2 + (data->render_data.res_y / 2) / sprite->distance - sprite->size_half;
    drawing_position = sprite->sprite_center_x - sprite->size_half > 0 ? sprite->sprite_center_x - sprite->size_half : 0;
    while (drawing_position < sprite->sprite_center_x  + sprite->size_half && drawing_position < data->render_data.res_x)
    {
        if (distance_array[drawing_position] > sprite->distance)
            draw_sprite_column(drawing_position, sprite, data, time);
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

void    draw_sprites(cub3d *data, float *distance_array, float time)
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

int handle_jump(t_bool *is_jumping, float *start_time)
{
    int y_offset;
    float time;

    if (!*start_time)
        *start_time = (float)clock() / CLOCKS_PER_SEC - *start_time;
    time = (float)clock() / CLOCKS_PER_SEC - *start_time;
        if (time > 0.7)
        {
            *is_jumping = false;
            *start_time = 0;
            return(0);
        }
        if (time < 0.1)
            y_offset = -5 * sinf(time / 0.1 * PI);
        else if (time < 0.6)
            y_offset = 60 * sinf((time - 0.1) / 0.5 * PI);
        else
            y_offset = -7 * sinf((time - 0.6) / 0.1 * PI);
        return (y_offset);
}

void draw_ceiling(s_coords coords, s_render_data *render_data, t_data *background)
{
	float distance;
    int y_res_2;

    y_res_2 = coords.end_y / 2;
    while (coords.y <= y_res_2)
    {
        distance = render_data->column_height / ((y_res_2 - coords.y) * 2);
        while (coords.x < coords.end_x)
        {
            if (distance <= render_data->distance_array[coords.x])
                draw_pixel(background, coords.x, coords.y, add_shade(render_data->c_rgb, distance, render_data->shade_distance));
            coords.x++;
        }
        coords.y++;
        coords.x = 0;
    }
}

void draw_floor(s_coords coords, s_render_data *render_data, t_data *background)
{
	float distance;
    int res_y_2;
	
    res_y_2 = coords.end_y / 2;
    while (coords.y > res_y_2)
    {
        distance = render_data->column_height / ((coords.y - res_y_2) * 2);
        while (coords.x < coords.end_x)
        {
            if (distance < render_data->distance_array[coords.x])
                draw_pixel(background, coords.x, coords.y, add_shade(render_data->f_rgb, distance, render_data->shade_distance));
            coords.x++;
        }
        coords.y--;
        coords.x = 0;
    }
}

void    ray_trace(cub3d *data)
{
    int i;
    float angle;
    float distance_array[data->render_data.res_x];
    float y_offset; 
    
    i = 0;
    if (data->mlx_data.keys_pressed.jump)
        y_offset = handle_jump(&data->mlx_data.keys_pressed.jump, &data->ray_trc.jump_time);
     else
        y_offset = 0;
    while (i < data->render_data.res_x)
    {
        angle = data->render_data.view_angle - atan(tan(FOV / 2.0) * (2.0 * i / data->render_data.res_x - 1.0));
        angle = angle < 0 ? PI2 + angle : angle;
        angle = angle > PI2 ? angle - PI2 : angle;
        distance_array[i] = calculate_collision(angle, data);
        if (!distance_array[i])
            distance_array[i] = 0.001;
        draw_column(i, distance_array[i], data, y_offset);
        i++;
    }
    i = 0;
    data->render_data.distance_array = distance_array;
    draw_ceiling(set_draw_coords(0, 0, data->render_data.res_x, data->render_data.res_y + 2 * y_offset), &data->render_data, data->mlx_data.background);
    draw_floor(set_draw_coords(0, data->render_data.res_y, data->render_data.res_x, data->render_data.res_y + 2 * y_offset), &data->render_data, data->mlx_data.background);
        draw_sprites(data, distance_array, y_offset);
}