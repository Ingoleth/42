/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 11:53:19 by user42            #+#    #+#             */
/*   Updated: 2020/09/24 12:53:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <stdio.h>
 #include <errno.h>
 #include "Libft/libft.h"

typedef struct		s_render_data
{
    int             res_x;
    int             res_y;
    int             player_x;
    int             player_y;
    char            *north_texture;
    char            *west_texture;
    char            *east_texture;
    char            *south_texture;
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
}                   s_map_bearings;


s_render_data   *read_file (char *data_file);
int		        fill_resolution(char *line, s_render_data *render_data, s_error *error);
void            fill_render_struct(s_render_data *render_data, char *line, s_error *error, int fd, char *path);
void	        handle_map(s_render_data *render_data, s_error *error, char *str, int fd, char *path);
void	        advance_file_line(char **line, s_error *error);
void            add_texture(char **fd, char *line, s_error *s_error);
int             print_error(s_error * error);
int             check_map_coherence(char **map, s_error *error);
s_render_data   *free_render_data(s_render_data *render_data);


 #endif