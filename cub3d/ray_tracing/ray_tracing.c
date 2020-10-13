/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 12:13:52 by user42            #+#    #+#             */
/*   Updated: 2020/10/13 16:36:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int calculate_collision_x(int x, int y, s_render_data *render_data, s_ray_tracing *raytrc)
{
    int yIntercept;

    yIntercept = y + render_data->offset_x + render_data->offset_y / tan(render_data->view_angle);
    if (raytrc->yStep == 1)
    {
        while (yIntercept > y)
        {
            if (render_data->map[x][(int)yIntercept] == '1')
                return(0); //Change;
            x += raytrc->tileStepX;
            yIntercept = raytrc->yStep;
        }
    }
    else
    {
        while (yIntercept > y)
        {
            if (render_data->map[x][(int)yIntercept] == '1')
                return(0); //Change;
            x += raytrc->tileStepX;
            yIntercept = raytrc->yStep;
        }
    }
    return (0);
}

int calculate_collision_y(int x, int y)
{

}

calculate_colision(float angle, s_render_data *render_data, s_ray_tracing *raytrc)
{
    int x;
    int y;

    x = render_data->player_x;
    y = render_data->player_y;
    if (calculate_collision_y)
        return ;
    if (calculate_collision_x)
        return ;
}

void    ray_trace(cub3d *data)
{
    calculate_colision(1, data->render_data);
}