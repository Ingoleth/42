/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 11:53:19 by user42            #+#    #+#             */
/*   Updated: 2020/12/19 12:16:56 by aiglesia         ###   ########.fr       */
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
 #include <time.h>

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
    file_not_cub,
    repeated_colour
}	t_error_values;

typedef enum t_colour
{
    tile_1,
    tile_2,
    tile_3,
    tile_4,
    brown_1 = -12447728,
    brown_2 = -13563639,
    grey_1 = -4144960,
    grey_2 = -8618884,
    grey_3 = -11053739,
    red_1 = 10551306,
    red_2 = 6225926
}   t_map_colour;

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
    float           angle;
    float           distance;
    float           sprite_x;
    float           sprite_y;
    int             sprite_center_x;
    int             sprite_center_y;
    int             size_half;
}                   t_sprite;

typedef struct		s_render_data
{
    int             res_x;
    int             res_y;
    float           player_x;
    float           player_y;
    float           y_angle;
    float           current_health;
    float           view_angle;
    t_data          north_texture;
    t_data          west_texture;
    t_data          east_texture;
    t_data          south_texture;
    t_data          sprite1;
    t_data          sprite2;
    t_data          sprite3;
    t_bool          is_sp1;
    t_bool          is_sp2;
    t_bool          is_sp3;
    void            *mlx_ptr;
    unsigned int    c_rgb;
    unsigned int    f_rgb;
    char            **map;
    float           column_height;
    float           shade_distance;
    char            *extra_level;
    int         y_offset; 
}                   s_render_data;

typedef struct      s_error
{
    t_error_values  error_id;
    int             line;
    int             row;;
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
    t_bool          is_sp1;
    t_bool          is_sp2;
    t_bool          is_sp3;
}                   s_map_bearings;

typedef struct      s_file_descriptor
{
    int             fd;
    char            *path;
}                   s_file_descriptor;

typedef struct      s_map_render
{
    int             line_size;
    int             tile_size;
    char            **map;
    int             size_x;
    int             size_y;
    int             current_tile;
}                   s_map_render;

typedef struct      keys
{
    t_bool          forward;
    t_bool          backwards;
    t_bool          mv_left;
    t_bool          mv_right;
    t_bool          left;
    t_bool          right;
    t_bool          up;
    t_bool          down;
    t_bool          enter;
    t_bool          jump;
    t_bool          transition;
}                   t_keys;

typedef struct      health_bar
{
    int             bar_start_x;
    int             bar_start_y;
    int             bar_lenght_x;
    int             bar_lenght_y;
    int             pixel_size;
    int             face_pos;
    t_data          *image;
    t_data          *face;
}                   t_health_bar;

typedef struct      mlx
{
    void            *mlx_ptr;
    void            *win_ptr;
    t_data          *background;
    t_data          *map;
    t_health_bar    health_bar;
    int             map_initial_x;
    int             map_initial_y;
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
    float       jump_time;
    t_list      *sprite;
    float       img_x;
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
#define HEALTH_BAR_PATH "/home/user42/Documents/42/cub3d/textures/health_bar.xpm"

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

#define TILE_MAXIMUM 15
#define MAP_RATIO 4
#define LINE_WIDTH 8
#define BORDER_RATIO 10
#define MAX_OFFSET 10
#define PLAYER_SPEED 0.05
#define ROTATION_SPEED 0.8
#define VER_ROTATION_SPEED 1.5
#define FOV 0.785398F
#define SHADE_DISTANCE 8
#define FADE_TIME 1.5

#define HB_START_x 21
#define HB_START_Y 6
#define HB_LENGHT_X 38
#define HB_LENGHT_Y 4
#define MAX_HEALTH 50

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
#define LOOK_UP 65362
#define LOOK_DOWN 65364
#define LOOK_LEFT 65361
#define LOOK_RIGHT 65363
#define MOVE_LEFT 'a'
#define MOVE_RIGHT 'd'
#define FORWARD 'w'
#define BACKWARDS 's'
#define SPACE ' '

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
int             free_render_data(s_render_data *render_data, void *mlx_ptr);
int             set_error_value(int id, int i, int j, s_error *error);
int         	check_map_basic_elements(s_map_bearings *map_info, s_error *error);
int             check_render_data(s_render_data *render_data, void *mlx_ptr);
int             cleanup(cub3d *data);

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
void            update_ver_angle_info(t_keys *keys, float *angle);
float           rad_to_degrees(float angle);
float           handle_tan(float angle);
int             get_sector(float angle);

void            ray_trace(cub3d *data);
float	        calculate_collision(float angle, cub3d *data, float x, float y);
int             calculate_collision_0(float p_x, float p_y, s_ray_tracing *ray_trc, char **map);
int             calculate_collision_1(float p_x, float p_y, s_ray_tracing *ray_trc, char **map);
int             calculate_collision_2(float p_x, float p_y, s_ray_tracing *ray_trc, char **map);
int             calculate_collision_3(float p_x, float p_y, s_ray_tracing *ray_trc, char **map);
t_bool          check_wall_collision(int tile_value, int tile_coord, s_ray_tracing * ray_trc, t_bool horiz);
unsigned int	add_shade(unsigned int colour, double distance, float shade_distance);
void            draw_column(int i, float distance, cub3d *data, int y_offset);
void            move_from_wall(cub3d *data, float x, float y);
t_bool          check_wall_distance(cub3d *data, float temp_x, float temp_y);
t_bool          check_sprite(cub3d *data);
float	        get_sprite_horizontal_lenght(s_ray_tracing *ray_trc, float view_angle);
void            change_level(cub3d *data, char *map_path);
void            load_map(char **map, s_mlx *mlx_data, int res_x, int res_y);
void            transition_to_level(cub3d *data);
char            *skip_spaces(char *str);
void            render_health_bar(s_mlx *mlx_data, float health_ratio, int pixel_size, t_keys *keys);
int             handle_transition(cub3d *data);
void	        order_sprites(t_list *sprite);
void            draw_sprites(cub3d *data, float *distance_array, float time);
void	        draw_floor_and_ceiling(cub3d *data, int y_offset, float *distance_array);
void            draw_walls(cub3d *data, float *distance_array, float *offset_array, int *dir_array);
void	        draw_edges(t_data *map_image, int border_start, int border_side, void *mlx_ptr);
void            load_map(char **map, s_mlx *mlx_data, int res_x, int res_y);
void            take_screenshot(t_data *render);
 #endif