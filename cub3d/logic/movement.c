/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:19:11 by user42            #+#    #+#             */
/*   Updated: 2020/12/07 14:16:16 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void handle_sprite_collision(char tile, s_render_data *render_data)
{
    if (tile == '2')
    {
        if (render_data->current_health)
            render_data->current_health -= 1;
    }
    else if (tile == '3')
    {
        if (render_data->current_health < MAX_HEALTH)
            render_data->current_health += 1;
    }
}

void handle_strife(cub3d *data, float *temp_x, float *temp_y)
{
    float angle;
    angle = data->render_data.view_angle;
    if (data->mlx_data.keys_pressed.mv_left)
        angle += PI_2;
    else if (data->mlx_data.keys_pressed.mv_right)
        angle -= PI_2;
    if (data->mlx_data.keys_pressed.mv_left || data->mlx_data.keys_pressed.mv_right)
    {
        *temp_x = *temp_x + cosf(angle) * PLAYER_SPEED;
        *temp_y = *temp_y - sinf(angle) * PLAYER_SPEED;
    }
}

void handle_movement(cub3d *data)
{
    float angle;
    float temp_x;
    float temp_y;

    temp_x = data->render_data.player_x;
    temp_y = data->render_data.player_y;
    if (data->mlx_data.keys_pressed.backwards)
    {
        if (data->render_data.view_angle > PI)
            angle = data->render_data.view_angle - PI;
        else
            angle = PI + data->render_data.view_angle;
    }
    else
        angle = data->render_data.view_angle;
    if (data->mlx_data.keys_pressed.forward || data->mlx_data.keys_pressed.backwards)
    {
        temp_x += cosf(angle) * PLAYER_SPEED;
        temp_y -= sinf(angle) * PLAYER_SPEED;
    }
    handle_strife(data, &temp_x, &temp_y);
    if (data->render_data.map[(int)temp_y][(int)temp_x] == '0')
    {
        data->render_data.player_x = temp_x;
        data->render_data.player_y = temp_y;
    }
    handle_sprite_collision(data->render_data.map[(int)temp_y][(int)temp_x], &data->render_data);
    //TODO fix empalamiento contra la parec... :P
}
