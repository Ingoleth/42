/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 12:13:52 by user42            #+#    #+#             */
/*   Updated: 2020/10/20 18:36:49 by user42           ###   ########.fr       */
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
    if (ray_trc->sector == 0 || ray_trc->sector == 3)
        while (ray_trc->xIntercept < *x + 1) 
        {
            if (map[*y][*x] == '1')
            {
                ray_trc->xIntercept = 0;
                return (1);
            }
            *y += ray_trc->tileStepY;
            ray_trc->xIntercept += ray_trc->xStep;
        }
    else
        while (ray_trc->xIntercept > *x)
        {
            if (map[*y][*x + 1] == '1')
            {
                ray_trc->xIntercept = 0;
                return (1);
            }
            *y += ray_trc->tileStepY;
           ray_trc->xIntercept += ray_trc->xStep;
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
}

int calculate_collision(float angle, cub3d *data)
{
    int x;
    int y;

    x = data->render_data->player_x;
    y = data->render_data->player_y;
    set_ray_casting_data(angle, &data->ray_trc, data->render_data);
    calculate_collision_x(&x, &y, &data->ray_trc, data->render_data->map);
    printf("Found a wall!\n At %i, %i\n", x, y);
    add_collision_tile(x, y, &data->mlx_data);
    return(0);
}

void    ray_trace(cub3d *data)
{
    int i;
    float angle;

    i = 0;
    printf("Initial angle: %f\n", rad_to_degrees(data->render_data->view_angle));
    angle = data->render_data->view_angle - (POV / 2) * ANGLE_1;
    while (i < POV)
    {
        printf("%i.- Angle = %f\n", i, rad_to_degrees(angle));
        calculate_collision(angle, data);
        angle += ANGLE_1;
        i++;
    }
    
}