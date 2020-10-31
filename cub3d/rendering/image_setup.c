/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 20:28:46 by user42            #+#    #+#             */
/*   Updated: 2020/10/31 11:14:43 by aiglesia         ###   ########.fr       */
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

void load_floor_ceiling(s_render_data *render_data, s_mlx *mlx_data)
{
    int half_point;

    half_point = render_data->res_y / 2;
    mlx_data->background = initialize_image(mlx_data->mlx_ptr, render_data->res_x, render_data->res_y);
    draw_pixel_area(mlx_data->background, set_draw_coords(0, 0, render_data->res_x, half_point), render_data->c_rgb);
    draw_pixel_area(mlx_data->background, set_draw_coords(0, half_point, render_data->res_x, render_data->res_y), render_data->f_rgb);
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

t_data    *load_xpm_image(void *mlx_ptr, char *path)
{
    t_data *image;
    
    if (!(image = ft_calloc(1, sizeof(t_data))))
        return (0);
    if (!(image->img = mlx_xpm_file_to_image(mlx_ptr, path, &image->width,
    &image->height)))
            return (0);
    image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel, &image->line_length, &image->endian);
    return (image);
}

void    free_image( void *mlx_ptr, t_data *image)
{
    mlx_destroy_image(mlx_ptr, image->img);
    free(image);
}