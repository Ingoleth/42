/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 13:00:56 by user42            #+#    #+#             */
/*   Updated: 2020/10/13 17:00:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    update_sector(int sector, s_ray_tracing *ray_trc)
{
    ray_trc->sector = (sector == 4 || sector == -1) ? 0 : sector;
    ray_trc->sector_pos = ray_trc->sector_pos > 0 ? ray_trc->sector_pos - PI_2 :
    PI_2 - ray_trc->sector_pos;
    ray_trc->tileStepX = sector == 0 || sector == 1 ? 1 : -1;
    ray_trc->tileStepY = sector == 0 || sector == 3 ? 1 : -1;
}

void    calculate_step()
{

}

void    update_angle_info(int keycode, cub3d *data)
{
    float previous_angle;

    previous_angle = data->render_data->view_angle;
    if (keycode == LOOK_LEFT)
    {
        set_cursor(data->render_data->view_angle -= 0.4);
        data->ray_trc.sector_pos -= 0.4;
    }
    if (keycode == LOOK_RIGHT)
    {
        set_cursor(data->render_data->view_angle += 0.4);
        data->ray_trc.sector_pos += 0.4;
    }
    if (data->ray_trc.sector_pos > PI_2)
        update_sector(data->ray_trc.sector + 1, &data->ray_trc);
    if (data->ray_trc.sector_pos < 0)
        update_sector(data->ray_trc.sector - 1, &data->ray_trc);
    calculate_step();
}