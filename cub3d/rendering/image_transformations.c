/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_transformations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 10:43:36 by user42            #+#    #+#             */
/*   Updated: 2020/10/03 10:55:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int get_pixel_value(t_data *image, int x, int y)
{
     char    *dst;

    dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
    return(*dst);
}

void *scale_image()
{
    //CHECK that the scale is bigger than the size...
    return (0);
}

void *scale_image_section()
{
    return(0);
}