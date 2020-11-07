/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 13:00:56 by user42            #+#    #+#             */
/*   Updated: 2020/11/07 19:21:50 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float rad_to_degrees(float angle)
{
    return (angle * 180 / PI);
}

int get_sector(float angle)
{
    if (angle < PI_2)
        return (0);
    else if (angle < PI)
        return (1);
    else if (angle < PI1_1_2)
        return (2);
    else 
        return (3);
}

float handle_tan(float angle)
{
    float tang;

    if (angle > TOP_MIN && angle < TOP_MAX)
        return(60);
    else if (angle > BOT_MIN && angle < BOT_MAX)
        return (-60);
    tang = (float) tan(angle);
    if (tang > 0)
        tang = tang < 0.01 ? 0.01 : tang;
    else
        tang = tang > -0.01 ? -0.01 : tang;
    if (angle == 0)
        tang = 0;
    return (tang);
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