/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 12:13:52 by user42            #+#    #+#             */
/*   Updated: 2020/11/05 13:51:13 by aiglesia         ###   ########.fr       */
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
    float distance;
    int sector;

    x = data->render_data->player_x;
    y = data->render_data->player_y;
    sector = get_sector(angle);
    data->ray_trc.angle = angle;
    printf("Sector: %i\n", sector);
    if (sector == 0)
        calculate_collision_0(&x,&y, &data->ray_trc, data->render_data->map);
    else if (sector == 1)
        calculate_collision_1(&x,&y, &data->ray_trc, data->render_data->map);
    else if (sector == 2)
        calculate_collision_2(&x,&y, &data->ray_trc, data->render_data->map);
    else if (sector == 3)
        calculate_collision_3(&x,&y, &data->ray_trc, data->render_data->map);
    distance = 0;
    printf("Found a wall! At: %f, %f\n", x, y);
    return(distance);
}

void    ray_trace(cub3d *data)
{
    int i;
    float angle;

    i = data->render_data->res_x - 1;
    angle = data->render_data->view_angle + (POV / 2);
    /*while (i >= 0)
    {
        calculate_collision(angle, data);
        angle -= POV / data->render_data->res_x;
        i--;
    }*/
    calculate_collision(data->render_data->view_angle, data);
}