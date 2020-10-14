/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 13:00:56 by user42            #+#    #+#             */
/*   Updated: 2020/10/14 17:13:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float rad_to_degrees(float angle)
{
    return (angle * 180 / PI);
}

void    update_sector(int sector, s_ray_tracing *ray_trc)
{
    if(sector == 4)
        ray_trc->sector = 0;
    else if (sector == -1)
        ray_trc->sector = 3;
    else
        ray_trc->sector = sector;
    ray_trc->sector_pos = ray_trc->sector_pos > 0 ? ray_trc->sector_pos - PI_2 :
    PI_2 + ray_trc->sector_pos;
    ray_trc->tileStepX = sector == 0 || sector == 3 ? 1 : -1;
    ray_trc->tileStepY = sector == 0 || sector == 1 ? 1 : -1;
}

void calculate_step(s_ray_tracing * ray_trc)
{
    ray_trc->tileStepX = 1;
    ray_trc->tileStepY = 1;   
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
        data->ray_trc.sector_pos -= ROTATION_SPEED;
    }
    if (keycode == LOOK_LEFT)
    {
        *angle += ROTATION_SPEED;
        if (*angle >= PI2)
            *angle = *angle - PI2;
        data->ray_trc.sector_pos += ROTATION_SPEED;
    }
    if (data->ray_trc.sector_pos >= PI_2)
        update_sector(data->ray_trc.sector + 1, &data->ray_trc);
    if (data->ray_trc.sector_pos < 0)
        update_sector(data->ray_trc.sector - 1, &data->ray_trc);
    calculate_step(&data->ray_trc);
}