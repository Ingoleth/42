/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:19:11 by user42            #+#    #+#             */
/*   Updated: 2020/11/30 18:55:41 by aiglesia         ###   ########.fr       */
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

void handle_movement(cub3d *data)
{
    float angle;
    float temp_x;
    float temp_y;
    if (data->mlx_data.keys_pressed.backwards)
    {
        if (data->render_data.view_angle > PI)
            angle = data->render_data.view_angle - PI;
        else
            angle = PI + data->render_data.view_angle;
    }
    else
        angle = data->render_data.view_angle;
    temp_x = data->render_data.player_x + cos(angle) * PLAYER_SPEED;
    temp_y = data->render_data.player_y - sin(angle) * PLAYER_SPEED;
    if (data->render_data.map[(int)temp_y][(int)temp_x] == '0')
    {
        data->render_data.player_x = temp_x;
        data->render_data.player_y = temp_y;
    }
    handle_sprite_collision(data->render_data.map[(int)temp_y][(int)temp_x], &data->render_data);
    //TODO fix empalamiento contra la parec... :P
}
