/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 12:13:52 by user42            #+#    #+#             */
/*   Updated: 2020/11/23 17:57:12 by aiglesia         ###   ########.fr       */
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
        calculate_collision_0(x,y, &data->ray_trc, data->render_data.map);
    else if (data->ray_trc.sector == 1)
        calculate_collision_1(x,y, &data->ray_trc, data->render_data.map);
    else if (data->ray_trc.sector == 2)
        calculate_collision_2(x,y, &data->ray_trc, data->render_data.map);
    else if (data->ray_trc.sector == 3)
        calculate_collision_3(x,y, &data->ray_trc, data->render_data.map);
    x = fabsf((data->ray_trc.x_collision - data->render_data.player_x) / cosf(angle));
    return(fabsf(x * cosf(beta))); //TODO: It doesn't work on 0 / PI for obvious reasons. Add if.
}

void    ray_trace(cub3d *data)
{
    int i;
    float angle;
    
    i = 0;
    while (i < data->render_data.res_x)
    {
        angle = data->render_data.view_angle - atan(tan(FOV / 2.0) * (2.0 * i / data->render_data.res_x - 1.0));
        angle = angle < 0 ? PI2 + angle : angle;
        angle = angle > PI2 ? angle - PI2 : angle;
        data->ray_trc.sprite = 0;
        draw_column(i, calculate_collision(angle, data), data);
        if(data->ray_trc.sprite != 0)
            draw_sprite_column(i, data);
        i++;
    }
}