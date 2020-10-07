/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 20:28:46 by user42            #+#    #+#             */
/*   Updated: 2020/10/03 10:31:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

s_coords    set_draw_coords(int x, int y, int end_x, int end_y)
{
    s_coords coords;

    coords.x = x;
    coords.y = y;
    coords.end_x = end_x;
    coords.end_y = end_y;
    return (coords);
}

void render_floor_ceiling(s_render_data *render_data, s_mlx *mlx_data)
{
    t_data *image;
    int half_point;

    half_point = render_data->res_y / 2;
    image = initialize_image(mlx_data->mlx_ptr, render_data->res_x, render_data->res_y);
    draw_pixel_area(image, set_draw_coords(0, 0, render_data->res_x, half_point), render_data->c_rgb);
    draw_pixel_area(image, set_draw_coords(0, half_point, render_data->res_x, render_data->res_y), render_data->f_rgb);
    mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->win_ptr, image->img, 0, 0);
    //free(image);
}

t_data *initialize_image(void *mlx_ptr, int size_x, int size_y)
{
    t_data *image;

    if (!(image = ft_calloc(1, sizeof(t_data))))
        return (0);
    image->img = mlx_new_image(mlx_ptr, size_x, size_y);
    image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
    &image->line_length, &image->endian);
    return(image);
}

void    draw_pixel(t_data *image, int x, int y, int color)
{
    char    *dst;

    dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void    draw_pixel_area(t_data *image, s_coords coords, int color)
{
    int aux;

    aux = coords.x;
    //printf("Coords: %i->%i, %i->%i;\n", coords.x, coords.end_x, coords.y, coords.end_y);
    while (coords.y < coords.end_y)
    {
        while (coords.x < coords.end_x)
        {
            draw_pixel(image, coords.x, coords.y, color);
            coords.x++;
        }
        coords.y++;
        coords.x = aux;
    }
}

t_data    *initialize_xpm_image(void *mlx_ptr, char *path)
{
    t_data *image;
    int width;
    int height;
    
    if (!(image = ft_calloc(1, sizeof(t_data))))
        return (0);
    image->img = mlx_xpm_file_to_image(mlx_ptr, path, &width, &height);
    if(image->img == 0)
            return (0);
    image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel, &image->line_length, &image->endian);
    return (image);
}