/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 12:13:52 by user42            #+#    #+#             */
/*   Updated: 2020/11/08 17:07:29 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    tileStepx/y = +-1;
    x/yStep = tan(a) / 1/tan(a);
    xIntercept = x + dx + dy/tan(); The x position wherein the ray intercepts with the vertical tile;
    YIntercept = y + dy + dy/tan();
*/

#include "../cub3d.h"

float calculate_collision(float angle, cub3d *data)
{
    float x;
    float y;

    x = data->render_data->player_x;
    y = data->render_data->player_y;
    data->ray_trc.sector = get_sector(angle);
    data->ray_trc.angle = angle;
    if (data->ray_trc.sector == 0)
        calculate_collision_0(&x,&y, &data->ray_trc, data->render_data->map);
    else if (data->ray_trc.sector == 1)
        calculate_collision_1(&x,&y, &data->ray_trc, data->render_data->map);
    else if (data->ray_trc.sector == 2)
        calculate_collision_2(&x,&y, &data->ray_trc, data->render_data->map);
    else if (data->ray_trc.sector == 3)
        calculate_collision_3(&x,&y, &data->ray_trc, data->render_data->map);
    x = fabsf((data->ray_trc.x_collision - data->render_data->player_x) * cosf(data->render_data->view_angle));
    y = fabsf((data->ray_trc.y_collision - data->render_data->player_y) * sinf(data->render_data->view_angle));
    return(x + y);
}

void    ray_trace(cub3d *data)
{
    int i;
    float angle;
    double time;
    double end_time;
    
    i = 0;
    time = (double)clock()/CLOCKS_PER_SEC;
    while (i < data->render_data->res_x - 1)
    {
        angle = data->render_data->view_angle - atan(tan((FOV / 2.0) * (2.0 * i / data->render_data->res_x - 1.0)));
        angle = angle < 0 ? PI2 + angle : angle;
        angle = angle > PI2 ? angle - PI2 : angle;
        draw_column(i, calculate_collision(angle, data), data);
        i++;
    }
    end_time = (double)clock()/CLOCKS_PER_SEC;
}