/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 11:53:19 by user42            #+#    #+#             */
/*   Updated: 2020/11/25 10:42:51 by aiglesia         ###   ########.fr       */
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
 #include "../libft/libft.h"
 #include <math.h>
 #include <time.h> //Remove when done!

typedef enum	t_bool
{
    no_error,
    out_of_memory,
    wrong_file,
    repeated_texture,
    wrong_resolution,
    wrong_input,
    wrong_map_input,
    no_player,
    multiple_player,
    map_not_enclosed,
    invalid_texture,
    wrong_colour,
    file_not_cub
}	t_error_values;

typedef struct      s_data 
{
    void            *img;
    char            *addr;
    int             bits_per_pixel;
    int             line_length;
    int             endian;
    int             height;
    int             width;
}                   t_data;

typedef struct      s_sprite
{
    int             texture;
    float           distance;
    float           beggining;
    float           end;
    float           sprite_x;
    float           sprite_y;
    float           upper_limit;
    float           lower_limit;
}                   t_sprite;

typedef struct		s_render_data
{
    int             res_x;
    int             res_y;
    float           player_x;
    float           player_y;
    float           view_angle;
    t_data          north_texture;
    t_data          west_texture;
    t_data          east_texture;
    t_data          south_texture;
    t_data          sprite;
    void            *mlx_ptr;
    unsigned int    c_rgb;
    unsigned int    f_rgb;
    char            **map;
}                   s_render_data;

typedef struct      s_error
{
    t_error_values  error_id;
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
    t_gnl_buffer    *map_struct;
}                   s_map_bearings;

typedef struct      s_file_descriptor
{
    int             fd;
    char            *path;
}                   s_file_descriptor;

typedef struct      keys
{
    t_bool          forward;
    t_bool          backwards;
    t_bool          left;
    t_bool          right;
    t_bool          enter;
}                   t_keys;

typedef struct      mlx
{
    void            *mlx_ptr;
    void            *win_ptr;
    t_data          *background;
    t_data          *map;
    t_data          **cursor;
    int             current_cursor;
    int             tile_size;
    int             render;
    t_keys          keys_pressed;
}                   s_mlx;

typedef struct s_write_coords
{
    int         x;
    int         y;
    int         end_x;
    int         end_y;
}               s_coords;

typedef struct ray_tracing
{
    float       angle;
    float       x_collision;
    float       y_collision;
    int         sector;
    int         cardinal_collision;
    float       tan_x;
    float       tan_y;
    float       column_height;
    t_list      *sprite;
    float       sprite_plane_lenght;
}               s_ray_tracing;

typedef struct cub3d
{
    s_render_data   render_data;
    s_mlx           mlx_data;
    s_ray_tracing   ray_trc;
}                   cub3d;


#define CURSOR_NORTH "./textures/cursor/cursor_north.xpm"
#define CURSOR_NORTH_EAST "./textures/cursor/cursor_north_east.xpm"
#define CURSOR_EAST "./textures/cursor/cursor_east.xpm"
#define CURSOR_SOUTH_EAST "./textures/cursor/cursor_south_east.xpm"
#define CURSOR_SOUTH "./textures/cursor/cursor_south.xpm"
#define CURSOR_SOUTH_WEST "./textures/cursor/cursor_south_west.xpm"
#define CURSOR_WEST "./textures/cursor/cursor_west.xpm"
#define CURSOR_NORTH_WEST "./textures/cursor/cursor_north_west.xpm"

#define PI 3.141593F
#define PI2 6.283186F
#define PI_4 0.785398F
#define PI_2 1.570796F
#define PI3_4 2.3562F
#define PI1_1_4 3.926990F
#define PI1_1_2 4.7123887F
#define PI1_3_4 5.494793F

#define PI_8 0.392699F
#define PI3_8 1.178097F
#define PI5_8 1.963495F
#define PI7_8 2.748893F
#define PI1_1_8 3.534292F
#define PI1_3_8 4.319690F
#define PI1_5_8 5.105088F
#define PI1_7_8 5.890487F

#define ANGLE_0_5 0.01F
#define ANGLE_1 0.02F
#define TOP_MAX 1.590796F
#define TOP_MIN 1.550796F
#define BOT_MAX 4.7323887F
#define BOT_MIN 4.6923887F

#define TILE_MINIMUM 10
#define MAP_RATIO 2 
#define LINE_WIDTH 8
#define MAX_OFFSET 10
#define PLAYER_SPEED 0.1
#define ROTATION_SPEED 0.8
#define FOV 1
#define WALL_DISTANCE 0.1f
#define SHADE_DISTANCE 10

#define TRANSPARENT -1
#define BLACK 0
#define WHITE 0xffefdb
#define GREY  0x2b2b2b
#define RED   0x8B0000
#define CYAN  0x00ffff
#define YELLOW 0xffff00 
#define PURPLE 0x800080	

#define ESC 65307
#define ENTER 65293
#define FORWARD 65362
#define BACKWARDS 65364
#define LOOK_LEFT 65361
#define LOOK_RIGHT 65363

#define EAST 0
#define NORTH 1
#define WEST 2
#define SOUTH 3

s_render_data	*read_file(char *data_file, s_render_data *render_data, void *mlx_ptr);
int		        fill_resolution(char *line, s_render_data *render_data, s_error *error);
void            fill_render_struct(s_render_data *render_data, char *line, s_error *error, s_file_descriptor *file);
void	        handle_map(s_render_data *render_data, s_error *error, char *str, s_file_descriptor *file);
void	        advance_file_line(char **line, s_error *error);
void            add_texture(t_data *image, void *mlx_data, char *line, s_error *s_error);
int             print_error(s_error * error);
int             check_map_coherence(char **map, s_error *error);
int             free_render_data(s_render_data *render_data);
int             set_error_value(int id, int i, int j, s_error *error);
int         	check_map_basic_elements(s_map_bearings *map_info, s_error *error);
int             check_render_data(s_render_data *render_data, void *mlx_ptr);
void            cleanup(cub3d *data);

t_data          *initialize_image(void *mlx_ptr, int size_x, int size_y);
unsigned int    get_pixel(t_data *image, int x, int y);
void            draw_pixel_area(t_data *image, s_coords coords, int color);
void            draw_pixel(t_data *image, int x, int y, int color);
void            free_image(void *mlx_ptr, t_data *image);
void            load_floor_ceiling(s_render_data *render_data, s_mlx *mlx_data);
s_coords        set_draw_coords(int x, int y, int end_x, int end_y);
t_data          *load_xpm_image(void *mlx_ptr, char *path);
int             load_cursor(s_mlx *mlx_data, float angle);
int             initialize_render_data(s_mlx *mlx_data, cub3d *data, char *file_path);
int             redraw_screen(cub3d *data);
void            render_cursor(s_mlx *mlx_data, s_render_data *render_data);
int             set_cursor(float angle);

unsigned int		        get_trgb(int t, int r, int g, int b);
unsigned int		        get_t(int trgb);
unsigned int		        get_r(int trgb);
unsigned int		        get_g(int trgb);
unsigned int		        get_b(int trgb);

int		        on_key_pressed(int keycode, cub3d *data);
int		        on_key_released(int keycode, s_mlx *mlx_data);
int             check_keys (cub3d *data);
void            handle_movement(cub3d *data);
int             close_window(void *mlx_ptr, void *win_ptr);

void            update_angle_info(t_keys *key, float *data);
float           rad_to_degrees(float angle);
float           handle_tan(float angle);
int             get_sector(float angle);

void            ray_trace(cub3d *data);
float           calculate_collision(float angle, cub3d *data);
int             calculate_collision_0(float p_x, float p_y, s_ray_tracing *ray_trc, char **map);
int             calculate_collision_1(float p_x, float p_y, s_ray_tracing *ray_trc, char **map);
int             calculate_collision_2(float p_x, float p_y, s_ray_tracing *ray_trc, char **map);
int             calculate_collision_3(float p_x, float p_y, s_ray_tracing *ray_trc, char **map);
t_bool          check_wall_collision(int tile_value, int tile_coord, s_ray_tracing * ray_trc, t_bool horiz);
unsigned int	add_shade(unsigned int colour, double distance);
void            draw_column(int i, float distance, cub3d *data);
void            move_from_wall(cub3d *data, float x, float y);
t_bool          check_wall_distance(cub3d *data, float temp_x, float temp_y);
t_bool          check_sprite(cub3d *data);
float	        get_sprite_horizontal_lenght(s_ray_tracing *ray_trc, float view_angle);

 #endif