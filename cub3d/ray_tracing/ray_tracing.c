/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 12:13:52 by user42            #+#    #+#             */
/*   Updated: 2020/10/15 13:54:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    tileStepx/y = +-1;
    x/yStep = tan(a) / 1/tan(a);
    xIntercept = x + dx + dy/tan();
    YIntercept = y + dy + dy/tan();
*/

#include "../cub3d.h"

calculate_collision_x(int * x, int * y, float yIntercept, cub3d *data)
{
    if (data->ray_trc.angle > PI1_1_2 || data->ray_trc.angle < PI_2)
        while (yIntercept < *y)
        {
            if (data->render_data->map[*x][(int)yIntercept])
                return (1);
            *x += data->ray_trc.tileStepX;
            yIntercept += data->ray_trc.yStep;
        }
    else
        while (yIntercept < *y) //Check sign
    {
        if (data->render_data->map[*x][(int)yIntercept])
            return (1);
        *x += data->ray_trc.tileStepX;
        yIntercept += data->ray_trc.yStep;
    } 
}

calculate_collision_y()
{

}

set_ray_casting_data(float angle, float *xIntercept, float *yIntercept, cub3d *data)
{
    int x;
    int y;
    float offset_y;
    float offset_x;

    x = data->render_data->player_x;
    y = data->render_data->player_y;
    offset_y = data->render_data->offset_y / MAX_OFFSET;
    offset_x = data->render_data->offset_x / MAX_OFFSET;
    if(data->ray_trc.sector == 0)
    {
        *xIntercept = x + offset_x + offset_y * data->ray_trc.yStep; //SET YSTEP in update sector!
        *yIntercept = x + offset_x + offset_y * data->ray_trc.yStep; //Actually... Since you have to do it per ray...
    }
}

int calculate_colision(float angle, s_render_data *render_data, s_ray_tracing *ray_trc)
{
    int x;
    int y;
    float xIntercept;
    float yIntercept;

    set_ray_casting_data(angle, &xIntercept, &yIntercept, ray_trc);
    while (x)
    {
            calculate_collision_x();
            calculate_collision_y();
    }
    
    return(0);
}

void    ray_trace(cub3d *data)
{
    calculate_colision(1, data->render_data, &data->ray_trc);

}