/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:19:11 by user42            #+#    #+#             */
/*   Updated: 2020/10/17 09:27:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void handle_x_move(s_render_data *render_data)
{
    if (render_data->offset_x > MAX_OFFSET)
    {
        if (render_data->map[render_data->player_y][render_data->player_x + 1] == '1')
            render_data->offset_x = MAX_OFFSET;
        else
        {
            render_data->player_x += 1;
            render_data->offset_x -= MAX_OFFSET;
        } 
    }
    else if (render_data->offset_x < 0)
    {
        if (render_data->map[render_data->player_y][render_data->player_x - 1] == '1')
            render_data->offset_x = 0;
        else
        {
            render_data->player_x -= 1;
            render_data->offset_x += MAX_OFFSET;
        } 
    }
}


void handle_y_move(s_render_data *render_data)
{
    if (render_data->offset_y > MAX_OFFSET)
    {
        if (render_data->map[render_data->player_y + 1][render_data->player_x] == '1')
            render_data->offset_y = MAX_OFFSET;
        else
        {
            render_data->player_y += 1;
            render_data->offset_y -= MAX_OFFSET;
        } 
    }
    else if (render_data->offset_y < 0)
    {
        if (render_data->map[render_data->player_y - 1][render_data->player_x] == '1')
            render_data->offset_y = 0;
        else
        {
            render_data->player_y -= 1;
            render_data->offset_y += MAX_OFFSET;
        } 
    }
}

void handle_movement(int keycode, cub3d *data)
{
    if (keycode == FORWARD)
        data->render_data->offset_y -= PLAYER_SPEED; //TRANSFORM TO take INTO ACCOUNT THE DIRECTION OF the look vector
    if (keycode == BACKWARDS)
        data->render_data->offset_y += PLAYER_SPEED;
    if (keycode == STRAFE_LEFT)
        data->render_data->offset_x -= PLAYER_SPEED;
    if (keycode == STRAFE_RIGHT)
        data->render_data->offset_x += PLAYER_SPEED;
    handle_x_move(data->render_data);
    handle_y_move(data->render_data);
}
