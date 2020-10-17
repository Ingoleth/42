/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 12:13:52 by user42            #+#    #+#             */
/*   Updated: 2020/10/17 10:48:46 by user42           ###   ########.fr       */
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
 Checks whether the ray interception is within the boundaries of the current y tile
 (hence the + 1 on the ray going downwards)
*/

int calculate_collision_x(int * x, int * y, s_ray_tracing *ray_trc, char **map) //Check values, might need an equal sign...
{
    printf("Checking on x!\n");
    if (ray_trc->angle < PI)
        while (ray_trc->yIntercept > *y)
        {
            if (map[*x][(int)ray_trc->yIntercept] == '1')
            {
                *y = ray_trc->yIntercept;
                ray_trc->yIntercept = 0;
                return (1); //Change to de adequate function
            }
            *x += ray_trc->tileStepX;
            ray_trc->yIntercept += ray_trc->yStep;
        }
    else
        while (ray_trc->yIntercept < *y + 1)
        {
            if (map[*x][(int)ray_trc->yIntercept] == '1')
            {
                *y = ray_trc->yIntercept;
                ray_trc->yIntercept = 0;
                return (1); //Change to de adequate function
            }
            *x += ray_trc->tileStepX;
            ray_trc->yIntercept += ray_trc->yStep;
        }
    return (0);
}


/*
 Checks whether the ray interception is within the boundaries of the current x tile
 (hence the + 1 on the ray going right)
*/

int calculate_collision_y(int * x, int * y, s_ray_tracing *ray_trc, char **map)
{
    if (ray_trc->angle > PI1_1_2 || ray_trc->angle < PI_2)
        while (ray_trc->xIntercept < *x + 1)
        {
            if (map[(int)ray_trc->xIntercept][*y] == '1')
            {
                *x = ray_trc->xIntercept;
                ray_trc->xIntercept = 0;
                return (1); //Change to de adequate function
            }
            *x += ray_trc->tileStepX;
            ray_trc->xIntercept += ray_trc->yStep;
        }
    else
        while (ray_trc->xIntercept > *x)
        {
            if (map[(int)ray_trc->xIntercept][*y] == '1')
            {
                *x = ray_trc->xIntercept;
                ray_trc->xIntercept = 0;
                return (1); //Change to de adequate function
            }
            *x += ray_trc->tileStepX;
           ray_trc->xIntercept += ray_trc->yStep;
        }
    return (0);
}

void set_ray_casting_data(float angle, s_ray_tracing *ray_trc, s_render_data *render_data)
{
    int x;
    int y;
    float offset_y;
    float offset_x;

    x = render_data->player_x;
    y = render_data->player_y;
    offset_y = render_data->offset_y / MAX_OFFSET;
    offset_x = render_data->offset_x / MAX_OFFSET;
    ray_trc->xIntercept = x + offset_x + offset_y * ray_trc->yStep;
    ray_trc->yIntercept = x + offset_x + offset_y * ray_trc->yStep;
    get_sector_info(angle, ray_trc);
}

int calculate_collision(float angle, s_render_data *render_data, s_ray_tracing *ray_trc)
{
    int x;
    int y;
    int i;

    x = render_data->player_x;
    y = render_data->player_y;
    set_ray_casting_data(angle, ray_trc, render_data);
    i = 0;
    while (i)
    {
        i = calculate_collision_x(&x, &y, ray_trc, render_data->map);
        i = calculate_collision_y(&x, &y, ray_trc, render_data->map);
    }
    printf("Found a wall!\n At %i, %i\n", x, y);
    
    return(0);
}

void    ray_trace(cub3d *data)
{
    calculate_collision(1, data->render_data, &data->ray_trc);

}