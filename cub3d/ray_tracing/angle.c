/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 13:00:56 by user42            #+#    #+#             */
/*   Updated: 2020/10/17 09:36:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float rad_to_degrees(float angle)
{
    return (angle * 180 / PI);
}

void set_step(s_ray_tracing * ray_trc, int sector)
{
    if (sector == 0)
    {
        ray_trc->tileStepX = 1;
        ray_trc->tileStepY = 1;
    }
    if (sector == 1)
    {
        ray_trc->tileStepX = -1;
        ray_trc->tileStepY = 1;
    }
    if (sector == 2)
    {
        ray_trc->tileStepX = -1;
        ray_trc->tileStepY = -1;
    }
    else
    {
        ray_trc->tileStepX = 1;
        ray_trc->tileStepY = 1;
    }
}

int get_sector(float angle)
{
    if (angle <= PI_2)
        return (0);
    if (angle <= PI)
        return (1);
    if (angle < PI1_1_2)
        return (2);
    else 
        return (3);
}

void get_sector_info(float angle, s_ray_tracing *ray_trc) //Double check
{
    int sector;
    
    sector = get_sector(angle);
    ray_trc->angle = angle;
    set_step(ray_trc, sector);
    if (sector == 0)
    {
        ray_trc->xStep = 1/tan(angle);
        ray_trc->yStep = tan(angle);
    }
    else if (sector == 1)
    {
        ray_trc->xStep = 1/tan(angle);
        ray_trc->yStep = -tan(angle);
    }
    else if (sector == 2)
    {
        ray_trc->xStep = -1/tan(angle);
        ray_trc->yStep = tan(angle);
    }
    else
    {
        ray_trc->xStep = -1/tan(angle);
        ray_trc->yStep = tan(angle);
    }  
}

void    update_angle_info(int keycode, cub3d *data)
{
    float *angle;

    angle = &data->render_data->view_angle;
    if (keycode == LOOK_RIGHT)
    {
        *angle -= ROTATION_SPEED;
        if (*angle < 0)
            *angle = PI2 + *angle;
    }
    if (keycode == LOOK_LEFT)
    {
        *angle += ROTATION_SPEED;
        if (*angle >= PI2)
            *angle = *angle - PI2;
    }
}