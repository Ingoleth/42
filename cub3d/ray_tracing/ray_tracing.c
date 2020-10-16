/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 12:13:52 by user42            #+#    #+#             */
/*   Updated: 2020/10/16 13:05:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    tileStepx/y = +-1;
    x/yStep = tan(a) / 1/tan(a);
    xIntercept = x + dx + dy/tan();
    YIntercept = y + dy + dy/tan();
*/

#include "../cub3d.h"

/*
/* Checks whether the ray interception is within the boundaries of the current y tile
/* (hence the + 1 on the ray going downwards)
*/

calculate_collision_x(int * x, int * y, float yIntercept, char **map) //Check values, might need an equal sign...
{
    if (data->ray_trc.angle > PI1_1_2 || data->ray_trc.angle < PI_2)
        while (yIntercept > *y)
        {
            if (map[*x][(int)yIntercept])
                return (1); //Change to de adequate function
            *x += data->ray_trc.tileStepX;
            yIntercept += data->ray_trc.yStep;
        }
    else
        while (yIntercept < *y + 1)
        {
            if (map[*x][(int)yIntercept])
                return (1); //Change to de adequate function
            *x += data->ray_trc.tileStepX;
            yIntercept += data->ray_trc.yStep;
        } 
}


/*
/* Checks whether the ray interception is within the boundaries of the current x tile
/* (hence the + 1 on the ray going right)
*/

calculate_collision_y(int *x, int *y, float xIntercept, char **map)
{
    if (data->ray_trc.angle > PI1_1_2 || data->ray_trc.angle < PI_2)
        while (xIntercept < *x + 1)
        {
            if (data->render_data->map[(int)xIntercept][*y])
                return (1); //Change to de adequate function
            *x += data->ray_trc.tileStepX;
            xIntercept += data->ray_trc.yStep;
        }
    else
        while (xIntercept > *x)
        {
            if (data->render_data->map[*x][*y])
                return (1); //Change to de adequate function
            *x += data->ray_trc.tileStepX;
            xIntercept += data->ray_trc.yStep;
        } 
}

set_ray_casting_data(float angle, cub3d *data)
{
    int x;
    int y;
    float offset_y;
    float offset_x;

    x = data->render_data->player_x;
    y = data->render_data->player_y;
    offset_y = data->render_data->offset_y / MAX_OFFSET;
    offset_x = data->render_data->offset_x / MAX_OFFSET;
    data->ray_trc.xIntercept = x + offset_x + offset_y * data->ray_trc.yStep;
    data->ray_trc.yIntercept = x + offset_x + offset_y * data->ray_trc.yStep;
    get_sector_info(angle, &data->ray_trc);
}

int calculate_colision(float angle, s_render_data *render_data, s_ray_tracing *ray_trc)
{
    int x;
    int y;

    set_ray_casting_data(angle, ray_trc);
    while (x)
    {
            calculate_collision_x(&x, &y, ray_trc->yIntercept, render_data->map);
            calculate_collision_y(&x, &y, ray_trc->xIntercept, render_data->map);
    }
    
    return(0);
}

void    ray_trace(cub3d *data)
{
    calculate_colision(1, data->render_data, &data->ray_trc);

}