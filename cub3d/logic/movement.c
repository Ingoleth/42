/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:19:11 by user42            #+#    #+#             */
/*   Updated: 2020/11/09 12:40:14 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void handle_movement(cub3d *data)
{
    float distance;
    float angle;

    if (data->mlx_data.keys_pressed.backwards)
        if (data->render_data->view_angle > PI)
            angle = data->render_data->view_angle - PI;
        else
            angle = PI - data->render_data->view_angle;
    else
        angle = data->render_data->view_angle;
    distance = calculate_collision(angle, data);
    if (distance < PLAYER_SPEED)
    {
        data->render_data->player_x = data->render_data->player_x;
        data->render_data->player_y = data->render_data->player_y;
    }
    else
    {
        data->render_data->player_x = data->render_data->player_x + PLAYER_SPEED * cosf(angle);
        data->render_data->player_y = data->render_data->player_y + PLAYER_SPEED * -sinf(angle);
    }
}
