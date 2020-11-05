/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:19:11 by user42            #+#    #+#             */
/*   Updated: 2020/11/05 14:22:47 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    calculate_collision_point(float angle, float *x, float *y, s_render_data *data)
{
    int sector;

    sector = get_sector(angle);
        if (sector == 0)
        {
            *y = (1 - data->player_x + (int)data->player_x) * tanf(angle);
            *x = (1 - data->player_y + (int)data->player_y) * tanf(angle);
            if (y > (int)data->player_y)
                *x = (int)data->player_x + 1;
            else
                *y = (int)data->player_y + 1;
        }
}

/*
** Might slip out the corners such as 
**       1
**      1\
*/


void    handle_collision(int key_code, s_render_data *data)
{
    float angle;
    int sector;
    float x;
    float y;

    angle = key_code == FORWARD ? data->view_angle + PI : data->view_angle;
    if(data->map[(int)data->player_y][(int)data->player_x] == '1')
    {
        sector = get_sector(angle);
        calculate_collision_point(angle, &x, &y, data);
        data->player_x = x;
        data->player_y = y;
    }
}

void handle_movement(int keycode, s_render_data *render_data)
{
    int sector;

    if (keycode == FORWARD)
    {
        render_data->player_x += PLAYER_SPEED * cosf(render_data->view_angle);
        render_data->player_y += PLAYER_SPEED * -sinf(render_data->view_angle);
    }
    if (keycode == BACKWARDS)
    {
        render_data->player_x -= PLAYER_SPEED * cosf(render_data->view_angle);
        render_data->player_y -= PLAYER_SPEED * -sinf(render_data->view_angle);
    }
    if (render_data->map[(int)render_data->player_y][(int)render_data->player_x] == 1)
        handle_collision(keycode, render_data);
}
