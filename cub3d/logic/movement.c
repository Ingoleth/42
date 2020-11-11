/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:19:11 by user42            #+#    #+#             */
/*   Updated: 2020/11/11 17:30:29 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_bool  check_wall_distance(cub3d *data, float temp_x, float temp_y)
{
    if(data->ray_trc.cardinal_collision == NORTH || data->ray_trc.cardinal_collision == SOUTH)
    {
        if(fabsf(temp_y - data->ray_trc.y_collision) < WALL_DISTANCE)
            return (true);
    }
    else if (data->ray_trc.cardinal_collision == EAST || data->ray_trc.cardinal_collision == WEST)
    {
        if(fabsf(temp_x - data->ray_trc.x_collision) < WALL_DISTANCE)
            return (true);
    }
    return (false);
}

void handle_movement(cub3d *data)
{
    float distance;
    float angle;
    float temp_x;
    float temp_y;
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
    {
        temp_x = data->ray_trc.x_collision;
        temp_y = data->ray_trc.y_collision;
    } 
    else
    {
        temp_x = data->render_data->player_x + PLAYER_SPEED * cosf(angle);
        temp_y = data->render_data->player_y + PLAYER_SPEED * -sinf(angle);
    }
    move_from_wall(data, temp_x, temp_y);
}
