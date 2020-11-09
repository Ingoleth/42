/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:19:11 by user42            #+#    #+#             */
/*   Updated: 2020/11/09 14:35:15 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float get_collision_right_angle(int sector, int face)
{
    if(face == NORTH)
        return(sector == 0 ? 0 : PI);
    else if(face == EAST)
        return(sector == 0 ? PI_2 : PI1_1_2);
    else if (face == SOUTH)
        return(sector == 3 ? 0 : PI);
    else
        return(sector == 2 ? PI_2 : PI1_1_2);
}

void handle_wall_collision(float angle, cub3d *data)
{
    float remaining;
    float distance;

        data->render_data->player_x = data->ray_trc.x_collision;
        data->render_data->player_y = data->ray_trc.y_collision;
        remaining = (PLAYER_SPEED - cos(angle) * fabsf(data->render_data->player_x - data->ray_trc.x_collision)) / 4;
        return;
        angle = get_collision_right_angle(get_sector(angle), data->ray_trc.cardinal_collision);
        distance = calculate_collision(angle, data);
        if (distance > remaining)
        {
            data->render_data->player_x = data->render_data->player_x + remaining * cosf(angle);
            data->render_data->player_y = data->render_data->player_y + remaining * -sinf(angle); 
        }
        else
        {
            data->render_data->player_x = data->ray_trc.x_collision;
            data->render_data->player_y = data->ray_trc.y_collision;
        }   
}

void handle_movement(cub3d *data)
{
    float distance;
    float angle;
    if (data->mlx_data.keys_pressed.backwards)
    {
        if (data->render_data->view_angle > PI)
            angle = data->render_data->view_angle - PI;
        else
            angle = PI + data->render_data->view_angle;
    }
    else
        angle = data->render_data->view_angle;
    distance = calculate_collision(angle, data);
    if (distance < PLAYER_SPEED)
        handle_wall_collision(angle, data);
    else
    {
        data->render_data->player_x = data->render_data->player_x + PLAYER_SPEED * cosf(angle);
        data->render_data->player_y = data->render_data->player_y + PLAYER_SPEED * -sinf(angle);
    }
}
