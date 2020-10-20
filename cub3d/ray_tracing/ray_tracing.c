/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 12:13:52 by user42            #+#    #+#             */
/*   Updated: 2020/10/20 11:42:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    tileStepx/y = +-1;
    x/yStep = tan(a) / 1/tan(a);
    xIntercept = x + dx + dy/tan(); The x position wherein the ray intercepts with the vertical tile;
    YIntercept = y + dy + dy/tan();
*/

#include "../cub3d.h"

/*
 Checks the y coordinate of the next horizontal intersection
 (hence the + 1 on the ray going downwards)
*/

int calculate_collision_x(int * x, int * y, s_ray_tracing *ray_trc, char **map) //Check values, might need an equal sign...
{
    printf("X: Angle = %f, Y intercept = %f, x = %i, y = %i\n", rad_to_degrees(ray_trc->angle), ray_trc->yIntercept, *x, *y);
    if (ray_trc->sector == 0 || ray_trc->sector == 1)
        while (ray_trc->yIntercept > *y)
        {
            if (map[*y][*x] == '1') //Double check
            {
                ray_trc->yIntercept = 0;
                return (1); //Change to de adequate function
            }
            *x += ray_trc->tileStepX;
            ray_trc->yIntercept += ray_trc->yStep;
            printf("X: Angle = %f, Y intercept = %f, x = %i, y = %i\n", rad_to_degrees(ray_trc->angle), ray_trc->yIntercept, *x, *y);
        }
    else
        while (ray_trc->yIntercept < *y + 1)
        {
            if (map[*y][*x] == '1')
            {
                ray_trc->yIntercept = 0;
                return (1); //Change to de adequate function
            }
            *x += ray_trc->tileStepX;
            ray_trc->yIntercept += ray_trc->yStep;
        }
    return (calculate_collision_y(x, y, ray_trc, map));
}


/*
 Checks whether the ray interception is within the boundaries of the current x tile
 (hence the + 1 on the ray going right)
*/

int calculate_collision_y(int * x, int * y, s_ray_tracing *ray_trc, char **map)
{
    printf("Y/// X intercept = %f, x = %i, y = %i\n", ray_trc->xIntercept, *x, *y);
    if (ray_trc->sector == 0 || ray_trc->sector == 3)
        while (ray_trc->xIntercept < *x + 1) 
        {
            if (map[*y][*x] == '1')
            {
                ray_trc->xIntercept = 0;
                return (1); //Change to de adequate function
            }
            *y += ray_trc->tileStepY;
            ray_trc->xIntercept += ray_trc->xStep;
            printf("(%i, %f, Sector = %i, YtileStep = %i)", *y, ray_trc->xIntercept, ray_trc->sector, ray_trc->tileStepY);
        }
    else
        while (ray_trc->xIntercept > *x)
        {
            if (map[*y][*x + 1] == '1')
            {
                ray_trc->xIntercept = 0;
                return (1); //Change to de adequate function
            }
            *y += ray_trc->tileStepY;
           ray_trc->xIntercept += ray_trc->xStep;
            printf("(%i, %f, Sector = %i, YtileStep = %i\n)", *y, ray_trc->xIntercept, ray_trc->sector, ray_trc->tileStepY);
        }
    return (calculate_collision_x(x, y, ray_trc, map));
}

void set_ray_casting_data(float angle, s_ray_tracing *ray_trc, s_render_data *render_data)
{
    int x;
    int y;
    float offset_y;
    float offset_x;

    x = render_data->player_x;
    y = render_data->player_y;
    get_sector_info(angle, ray_trc);
    offset_y = (float)render_data->offset_y / MAX_OFFSET;
    offset_x = (float)render_data->offset_x / MAX_OFFSET;
    if (ray_trc->sector == 0 || ray_trc->sector == 1)
        ray_trc->xIntercept = x + offset_x + offset_y * ray_trc->xStep;
    else
        ray_trc->xIntercept = x + offset_x + (1 - offset_y) * ray_trc->xStep;
    if (ray_trc->sector == 1 || ray_trc->sector == 2)
        ray_trc->yIntercept = y + offset_y + offset_x * ray_trc->yStep;
    else
        ray_trc->yIntercept = y + offset_y + (1 - offset_x) * ray_trc->yStep;
    printf("Angle = %f, sector = %i, x = %i, y = %i;\n", rad_to_degrees(ray_trc->angle), ray_trc->sector, x, y);
    printf("Offset y = %f; TileStepY = %i; yStep = %f; Yintercept = %f;\n", offset_y, ray_trc->tileStepY, ray_trc->yStep, ray_trc->yStep);
    printf("Offset x = %f; TileStepX = %i; xStep = %f; Xintercept = %f;\n", offset_x, ray_trc->tileStepX, ray_trc->xStep, ray_trc->xStep);

}

int calculate_collision(float angle, s_render_data *render_data, s_ray_tracing *ray_trc)
{
    int x;
    int y;

    x = render_data->player_x;
    y = render_data->player_y;
    set_ray_casting_data(angle, ray_trc, render_data);
    calculate_collision_x(&x, &y, ray_trc, render_data->map); //It is important that you get called first!
    printf("Found a wall!\n At %i, %i\n", x, y);

    return(0);
}

void    ray_trace(cub3d *data)
{
    calculate_collision(data->render_data->view_angle, data->render_data, &data->ray_trc);

}