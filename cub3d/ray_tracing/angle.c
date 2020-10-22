/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 13:00:56 by user42            #+#    #+#             */
/*   Updated: 2020/10/20 17:36:16 by user42           ###   ########.fr       */
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
        ray_trc->tileStepY = -1;
    }
    else if (sector == 1)
    {
        ray_trc->tileStepX = -1;
        ray_trc->tileStepY = -1;
    }
    else if (sector == 2)
    {
        ray_trc->tileStepX = -1;
        ray_trc->tileStepY = 1;
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
    else if (angle <= PI)
        return (1);
    else if (angle < PI1_1_2)
        return (2);
    else 
        return (3);
}

void set_tan_step(float tang, float tang_div, s_ray_tracing *ray_trc)
{
    if (ray_trc->sector == 0)
    {
        ray_trc->xStep = tang_div;
        ray_trc->yStep = -tang;
    }
    else if (ray_trc->sector == 1)
    {
        ray_trc->xStep = tang_div;
        ray_trc->yStep = tang;
    }
    else if (ray_trc->sector == 2)
    {
        ray_trc->xStep = -tang_div;
        ray_trc->yStep = tang;
    }
    else
    {
        ray_trc->xStep = tang_div;
        ray_trc->yStep = tang;
    }
}

void handle_tan(float angle, float minimum, s_ray_tracing *ray_trc)
{
    float tang;
    float tang_div;
    if (angle > TOP_MIN && angle < TOP_MAX)
    {
        ray_trc->xStep = 0;
        ray_trc->yStep = -1;
        return ;
    }
    else if (angle > BOT_MIN && angle < BOT_MAX)
    {
        ray_trc->xStep = 0;
        ray_trc->yStep = 1;
        return ;
    }
    tang = (float) tan(angle);
    if (tang > 0)
        tang = tang < minimum ? minimum : tang;
    else
        tang = tang > -minimum ? minimum : tang;
    tang_div = 1 / tang;
    set_tan_step(tang, tang_div, ray_trc);
}

void get_sector_info(float angle, s_ray_tracing *ray_trc) //Double check
{
    float minimum;

    ray_trc->sector = get_sector(angle);
    set_step(ray_trc, ray_trc->sector);
    ray_trc->angle = angle;
    minimum = 1;
    minimum /= (2 * MAX_OFFSET);
    handle_tan(angle, minimum, ray_trc);
}

void    update_angle_info(int keycode, float *angle)
{
    static float ang = 0;

    if (!ang)
        ang = ANGLE_1 * ROTATION_SPEED;
    if (keycode == LOOK_RIGHT)
    {
        *angle -= ang;
        if (*angle < 0)
            *angle = PI2 + *angle;
    }
    if (keycode == LOOK_LEFT)
    {
        *angle += ang;
        if (*angle >= PI2)
            *angle = *angle - PI2;
    }
}