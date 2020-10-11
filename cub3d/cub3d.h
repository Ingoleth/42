/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 11:53:19 by user42            #+#    #+#             */
/*   Updated: 2020/10/11 12:04:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <stdio.h>
 #include <errno.h>
 #include <mlx.h>
 #include "../Libft/libft.h"
 #include <math.h>

typedef struct		s_render_data
{
    int             res_x;
    int             res_y;
    int             player_x;
    int             player_y;
    int             offset_x;
    int             offset_y;
    float           view_angle;
    char            *north_texture;
    char            *west_texture;
    char            *east_texture;
    char            *south_texture;
    char            *sprite;
    unsigned int    c_rgb;
    unsigned int    f_rgb;
    char            **map;
}                   s_render_data;

typedef struct      s_error
{
    int             error_id;
    int             line;
    int             row;
}                   s_error;

typedef struct      s_map_bearings
{
    int             top_one;
    int             bot_one;
    int             left_one;
    int             right_one;
    int             player_pos_x;
    int             player_pos_y;
    float           view_angle;
}                   s_map_bearings;

typedef struct      s_file_descriptor
{
    int             fd;
    char            *path;
}                   s_file_descriptor;

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

typedef struct      mlx
{
    void            *mlx_ptr;
    void            *win_ptr;
    t_data          *background;
    t_data          *map;
    t_data          **cursor;
    int             current_cursor;
    int             tile_size;
    int             is_key_held;
}                   s_mlx;

typedef struct s_write_coords
{
    int         x;
    int         y;
    int         end_x;
    int         end_y;
}               s_coords;

typedef struct cub3d
{
    s_render_data *render_data;
    s_mlx         mlx_data;
}               cub3d;


#define CURSOR_NORTH "./textures/cursor/cursor_north.xpm"
#define CURSOR_NORTH_EAST "./textures/cursor/cursor_north_east.xpm"
#define CURSOR_EAST "./textures/cursor/cursor_east.xpm"
#define CURSOR_SOUTH_EAST "./textures/cursor/cursor_south_east.xpm"
#define CURSOR_SOUTH "./textures/cursor/cursor_south.xpm"
#define CURSOR_SOUTH_WEST "./textures/cursor/cursor_south_west.xpm"
#define CURSOR_WEST "./textures/cursor/cursor_west.xpm"
#define CURSOR_NORTH_WEST "./textures/cursor/cursor_north_west.xpm"

#define PI 3.141593
#define PI2 6.283186
#define PI_4 0.785398
#define PI_2 1.570796
#define PI3_4 2.3562
#define PI1_1_4 3.926990
#define PI1_1_2 4.71238865359
#define PI1_3_4 5.494793

#define PI_8 0.392699
#define PI3_8 1.178097
#define PI5_8 1.963495
#define PI7_8 2.748893
#define PI1_1_8 3.534292
#define PI1_3_8 4.319690
#define PI1_5_8 5.105088
#define PI1_7_8 5.890487

#define TILE_MINIMUM 10
#define MAP_RATIO 2 
#define LINE_WIDTH 8
#define MAX_OFFSET 10
#define PLAYER_SPEED 1

#define TRANSPARENT 0xf000
#define BLACK 0
#define WHITE 0xffefdb
#define GREY  0x2b2b2b

#define ESC 65307
#define FORWARD 119
#define BACKWARDS 115
#define STRAFE_LEFT 97
#define STRAFE_RIGHT 100
#define LOOK_LEFT 65361
#define LOOK_RIGHT 65363

s_render_data   *read_file (char *data_file);
int		        fill_resolution(char *line, s_render_data *render_data, s_error *error);
void            fill_render_struct(s_render_data *render_data, char *line, s_error *error, s_file_descriptor *file);
void	        handle_map(s_render_data *render_data, s_error *error, char *str, s_file_descriptor *file);
void	        advance_file_line(char **line, s_error *error);
void            add_texture(char **fd, char *line, s_error *s_error);
int             print_error(s_error * error);
int             check_map_coherence(char **map, s_error *error);
s_render_data   *free_render_data(s_render_data *render_data);
int             set_error_value(int id, int i, int j, s_error *error);
void			end_get_next_line(char *line, int fd);
s_map_bearings	*check_map_basic_elements(char *line, s_error *error, int fd);
int             check_render_data(s_render_data *render_data, void *mlx_ptr);

t_data          *initialize_image(void *mlx_ptr, int size_x, int size_y);
void            draw_pixel_area(t_data *image, s_coords coords, int color);
void            draw_pixel(t_data *image, int x, int y, int color);
void            load_floor_ceiling(s_render_data *render_data, s_mlx *mlx_data);
s_coords        set_draw_coords(int x, int y, int end_x, int end_y);
t_data          *load_xpm_image(void *mlx_ptr, char *path);
int             get_pixel_value(t_data *image, int x, int y);
int             load_cursor(s_mlx *mlx_data, float angle);
s_render_data   *initialize_render_data(s_mlx *mlx_data, cub3d *data);
int             redraw_screen(cub3d *data);
void            render_cursor(s_mlx *mlx_data, s_render_data *render_data);
int             set_cursor(float angle);

int		        get_rgb(int t, int r, int g, int b);
int		        get_t(int trgb);
int		        get_r(int trgb);
int		        get_g(int trgb);
int		        get_b(int trgb);

int             handle_keys (int keycode, cub3d *data);
int             handle_mouse(cub3d *data);
int             close_window(void *mlx_ptr, void *win_ptr);

 #endif