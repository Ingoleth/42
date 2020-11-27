/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:19:11 by user42            #+#    #+#             */
/*   Updated: 2020/11/26 10:35:17 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
    if (data->render_data.map[(int)temp_y][(int)temp_x] != '1')
    {
        data->render_data.player_x = temp_x;
        data->render_data.player_y = temp_y;
    }
    //TODO fix empalamiento contra la parec... :P
}
