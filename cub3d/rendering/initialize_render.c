/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_render.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 11:33:22 by user42            #+#    #+#             */
/*   Updated: 2020/12/06 18:07:48 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int    get_tile_size(char **map, int side_size, s_map_render * map_render)
{
    int i;
    int j;
    float tile_size;
    int x;

    i = 0;
    j = 0;
    x = 0;
    while (map[i])
    {
        while (map[i][j])
            j++;
        if (x < j)
            x = j;
        i++;
        j = 0;
    }
    tile_size = side_size / (i > x ? i : x);
    tile_size = tile_size > TILE_MAXIMUM ? TILE_MAXIMUM : tile_size;
    map_render->size_x = x * tile_size;
    map_render->size_y = i * tile_size;
    return(tile_size);
}

void draw_tiles(t_data *map_img, s_map_render *map_render, int initial_x, int initial_y)
{
    int x;
    int y;
    int i;
    int j;
    char **map;

    map = map_render->map;
    i = 0;
    j = 0;
    while (map[i])
    {
        while (map[i][j])
        {
            if (map[i][j] == ' ')
                j++;
            else
            {
                x = j * map_render->tile_size + map_render->line_size + initial_x;
                y = i * map_render->tile_size + map_render->line_size + initial_y;
                draw_pixel_area(map_img, set_draw_coords(x, y, x + map_render->tile_size - map_render->line_size, y + map_render->tile_size - map_render->line_size), ((char **)map_render->map)[i][j] == '1' ? WHITE : (((char **)map_render->map)[i][j] == '0' ? GREY : RED));
                j++;
            }
        }
        i++;
        j = 0;
    }
}

void draw_map_sides(t_data *map_image, int border_start, float border_side, t_map_colour *border)
{
    int i;
    int j;
    int border_end;

    border_end = border_start + border_side;
    i = 0;
    j = border_start;
    while (i < border_start)
    {
        while (j < border_end)
        {
            draw_pixel(map_image, i, j, border[(int)((float)((j - border_start) / border_side) * 6)]);
            j++;
        }
        j = border_start;
        i++;
    }
    i = border_start;
    j = 0;
    while (j < border_start)
    {
        while (i < border_end)
        {
            draw_pixel(map_image, i, j, border[(int)((float)((i - border_start) / border_side) * 6)]);
            i++;
        }
        i = border_start;
        j++;
    }
}

t_map_colour **get_map_corner(void)
{
    t_map_colour map_corner[7][7] = {
    {brown_1, brown_2, grey_1, grey_2, grey_2, grey_2, grey_3},
    {brown_2, grey_1, grey_2, grey_2, grey_2, grey_2, grey_3},
    {grey_1, grey_2, grey_2, brown_2, grey_2, grey_2, grey_3},
    {grey_2, grey_2, brown_2, brown_1, brown_2, grey_2, grey_3},
    {grey_2, grey_2, grey_2, brown_2, grey_2, grey_2, grey_3},
    {grey_2, grey_2, grey_2, grey_2, grey_2, grey_3, grey_3},
    {grey_3, grey_3, grey_3, grey_3, grey_3, grey_3, grey_3},    
    };
    int i;
    int j;
    t_map_colour **aux;
    
    aux = ft_calloc(8, sizeof(t_map_colour*));
    i = 0;
    j = 0;
    while (i < 7)
    {
        aux[i] = ft_calloc(1, sizeof(t_map_colour) * 8);
        while (j < 7)
        {
            aux[i][j] = map_corner[i][j];
            j++;
        }
        j = 0;
        i++;
    }
    return (aux);
}

void draw_map_corner(t_data *map_image, int border_start, float border_side)
{
    int i;
    int j;
    int border_end;
    t_map_colour **border;

    border = get_map_corner();
    border_end = border_start + border_side;
    i = border_start;
    j = border_start;
     while (i < border_end)
    {
        while (j < border_end)
        {
            draw_pixel(map_image, i, j, border
            [(int)((float)((j - border_start) / border_side) * 6)]
            [(int)((float)((i - border_start) / border_side) * 6)]);
            j++;
        }
        i++;
        j = border_start;
    }
    i = -1;
    while (i++ < 7)
        free(border[i]);
    free(border);
}

void draw_edges(t_data *map_image, int border_start, int border_side)
{
    t_map_colour map_side[7] = {brown_1, brown_1, brown_2, grey_1, grey_2, grey_2, grey_3};
    
    draw_map_sides(map_image, border_start, border_side, map_side);
    draw_map_corner(map_image, border_start, border_side);
}

void    load_map(char **map, s_mlx *mlx_data, int res_x, int res_y)
{
    int map_size;
    int border_size;
    s_map_render map_render;
    
    map_size = res_x < res_y ? res_x / MAP_RATIO : res_y / MAP_RATIO;
    map_size = map_size == 0 ? 1 : map_size;
    border_size = map_size / BORDER_RATIO;
    map_render.map = map;
    map_render.tile_size = get_tile_size(map, map_size - border_size, &map_render);
    map_render.line_size = map_render.tile_size / LINE_WIDTH;
    map_render.line_size = map_render.line_size == 0 ? 1 : map_render.line_size;
	mlx_data->tile_size = map_render.tile_size;
    mlx_data->map_initial_x = (map_size - border_size - map_render.size_x) / 2;
    mlx_data->map_initial_y = (map_size - border_size - map_render.size_y) / 2;
    mlx_data->map = initialize_image(mlx_data->mlx_ptr, map_size, map_size);
    draw_tiles(mlx_data->map, &map_render, mlx_data->map_initial_x, mlx_data->map_initial_y);
    draw_edges(mlx_data->map, map_size - border_size, border_size);
}

void load_health_bar(s_mlx *mlx_data, int res)
{
    t_data * health_bar_temp;
    float bar_width;
    float bar_height;
    int j;

    bar_width = res / MAP_RATIO > 0 ? res / MAP_RATIO : 1;
    bar_height = (int)(bar_width / 4) > 0 ? bar_width / 4 : 1;
    health_bar_temp = load_xpm_image(mlx_data->mlx_ptr, HEALTH_BAR_PATH);
    mlx_data->health_bar.image = initialize_image(mlx_data->mlx_ptr, bar_width, bar_height);
    mlx_data->health_bar.pixel_size = (int)bar_width / (float)health_bar_temp->width;
    mlx_data->health_bar.bar_start_x = HB_START_x * (mlx_data->health_bar.image->width / (float) health_bar_temp->width);
    mlx_data->health_bar.bar_start_y = HB_START_Y * (mlx_data->health_bar.image->height / (float)health_bar_temp->height);
    mlx_data->health_bar.bar_lenght_x = (HB_LENGHT_X) * (mlx_data->health_bar.image->width / (float) health_bar_temp->width);
    mlx_data->health_bar.bar_lenght_y = (HB_LENGHT_Y) * (mlx_data->health_bar.image->height / (float)health_bar_temp->height);
    res = 0;
    j = 0;
    while (res < bar_width)
    {
        while (j < bar_height)
        {
            draw_pixel(mlx_data->health_bar.image, res, j, get_pixel(health_bar_temp, (int)(res / bar_width * health_bar_temp->width), (int)(j / bar_height * health_bar_temp->height)));
            j++;
        }
        res++;
        j = 0;
    }
    free_image(mlx_data->mlx_ptr, health_bar_temp);
}

int initialize_render_data(s_mlx *mlx_data, cub3d *data, char *file_path)
{

    if (!read_file(file_path, &data->render_data, mlx_data->mlx_ptr) ||
	check_render_data(&data->render_data, mlx_data->mlx_ptr))
		return(0); //TODO Might crashy crash, make it check the images have value
    mlx_data->win_ptr = mlx_new_window(mlx_data->mlx_ptr, data->render_data.res_x, data->render_data.res_y, "Cub3d");
    mlx_data->background = initialize_image(mlx_data->mlx_ptr, data->render_data.res_x, data->render_data.res_y);
	load_map(data->render_data.map, mlx_data, data->render_data.res_x, data->render_data.res_y);
    load_health_bar(mlx_data, data->render_data.res_x > data->render_data.res_y ? data->render_data.res_y : data->render_data.res_x);
    load_cursor(mlx_data, data->render_data.view_angle);
    data->ray_trc.focal_length = data->render_data.res_y / 2 / tanf(FOV / 2);
    data->render_data.column_height = data->render_data.res_y / 2;
    data->render_data.current_health = MAX_HEALTH;
    data->render_data.y_angle = 1;
    data->mlx_data.keys_pressed.enter = true;
    data->render_data.shade_distance = SHADE_DISTANCE;
    redraw_screen(data);
    return (1);
}
