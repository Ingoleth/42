/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:19:11 by user42            #+#    #+#             */
/*   Updated: 2020/11/11 16:22:55 by aiglesia         ###   ########.fr       */
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

void move_from_wall(cub3d *data, float x, float y)
{
    if (check_wall_distance(data, x, y))
    {
        if (data->ray_trc.cardinal_collision == SOUTH)
        {
            y = (y - (int)y < WALL_DISTANCE) ? (int)y + WALL_DISTANCE : y;
            if (data->ray_trc.sector == 0 && data->render_data->map[(int)y][(int)x + 1] == '1')
                x = (x - (int)x > 1 - WALL_DISTANCE) ? (int) x + 1 - WALL_DISTANCE : x;
            else if (data->ray_trc.sector == 1 && data->render_data->map[(int)y][(int)x - 1] == '1')
                x = (x - (int)x < WALL_DISTANCE) ? (int) x + WALL_DISTANCE : x;
        }
        else if (data->ray_trc.cardinal_collision == EAST)
        {
            x = (x - (int)x < WALL_DISTANCE) ? (int) x + WALL_DISTANCE : x;
            if (data->ray_trc.sector == 1 && data->render_data->map[(int)y - 1][(int)x] == '1')
                y = (y - (int)y < WALL_DISTANCE) ? (int) y + WALL_DISTANCE : y;
            else if (data->ray_trc.sector == 2 && data->render_data->map[(int)y + 1][(int)x] == '1')
                 y = (y - (int)y > 1 - WALL_DISTANCE) ? (int) y + 1 - WALL_DISTANCE : y;
        }
        else if (data->ray_trc.cardinal_collision == NORTH)
        {
             y = (y - (int)y > 1 - WALL_DISTANCE) ? (int)y + 1 - WALL_DISTANCE : y;
            if (data->ray_trc.sector == 2 && data->render_data->map[(int)y][(int)x - 1] == '1')
                x = (x - (int)x < WALL_DISTANCE) ? (int) x + WALL_DISTANCE : x;
            else if (data->ray_trc.sector == 3 && data->render_data->map[(int)y][(int)x + 1] == '1')
                x = (x - (int)x > 1 - WALL_DISTANCE) ? (int) x + 1 - WALL_DISTANCE : x;
        }
        else
        {
            x = (x - (int)x > 1 - WALL_DISTANCE) ? (int)x + 1 - WALL_DISTANCE : x;
            if (data->ray_trc.sector == 0 && data->render_data->map[(int)y - 1][(int)x] == '1')
                y = (y - (int)y < WALL_DISTANCE) ? (int) y + WALL_DISTANCE : y;
            else if (data->ray_trc.sector == 3 && data->render_data->map[(int)y + 1][(int)x] == '1')
                 y = (y - (int)y > 1 - WALL_DISTANCE) ? (int) y + 1 - WALL_DISTANCE : y;
        }
    }
    data->render_data->player_x = x; 
    data->render_data->player_y = y; 
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
