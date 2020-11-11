/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_from_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:30:35 by aiglesia          #+#    #+#             */
/*   Updated: 2020/11/11 17:39:36 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	handle_south_wall(cub3d *data, float *x, float *y)
{
	*y = (*y - (int)*y < WALL_DISTANCE) ? (int)*y + WALL_DISTANCE : *y;
	if (data->ray_trc.sector == 0 && data->render_data->map[(int)*y][(int)*x + 1] == '1')
		*x = (*x - (int)*x > 1 - WALL_DISTANCE) ? (int) *x + 1 - WALL_DISTANCE : *x;
	else if (data->ray_trc.sector == 1 && data->render_data->map[(int)*y][(int)*x - 1] == '1')
		*x = (*x - (int)*x < WALL_DISTANCE) ? (int) *x + WALL_DISTANCE : *x;
}

void	handle_east_wall(cub3d *data, float *x, float *y)
{
	*x = (*x - (int)*x < WALL_DISTANCE) ? (int) *x + WALL_DISTANCE : *x;
	if (data->ray_trc.sector == 1 && data->render_data->map[(int)*y - 1][(int)*x] == '1')
		*y = (*y - (int)*y < WALL_DISTANCE) ? (int) *y + WALL_DISTANCE : *y;
	else if (data->ray_trc.sector == 2 && data->render_data->map[(int)*y + 1][(int)*x] == '1')
			*y = (*y - (int)*y > 1 - WALL_DISTANCE) ? (int) *y + 1 - WALL_DISTANCE : *y;
}
void	handle_north_wall(cub3d *data, float *x, float *y)
{
		*y = (*y - (int)*y > 1 - WALL_DISTANCE) ? (int)*y + 1 - WALL_DISTANCE : *y;
	if (data->ray_trc.sector == 2 && data->render_data->map[(int)*y][(int)*x - 1] == '1')
		*x = (*x - (int)*x < WALL_DISTANCE) ? (int) *x + WALL_DISTANCE : *x;
	else if (data->ray_trc.sector == 3 && data->render_data->map[(int)*y][(int)*x + 1] == '1')
		*x = (*x - (int)*x > 1 - WALL_DISTANCE) ? (int) *x + 1 - WALL_DISTANCE : *x;
}
void	handle_west_wall(cub3d *data, float *x, float *y)
{
	*x = (*x - (int)*x > 1 - WALL_DISTANCE) ? (int)*x + 1 - WALL_DISTANCE : *x;
	if (data->ray_trc.sector == 0 && data->render_data->map[(int)*y - 1][(int)*x] == '1')
		*y = (*y - (int)*y < WALL_DISTANCE) ? (int) *y + WALL_DISTANCE : *y;
	else if (data->ray_trc.sector == 3 && data->render_data->map[(int)*y + 1][(int)*x] == '1')
			*y = (*y - (int)*y > 1 - WALL_DISTANCE) ? (int) *y + 1 - WALL_DISTANCE : *y;
}

void move_from_wall(cub3d *data, float x, float y)
{
    if (check_wall_distance(data, x, y))
    {
        if (data->ray_trc.cardinal_collision == SOUTH)
			handle_south_wall(data, &x, &y);
        else if (data->ray_trc.cardinal_collision == EAST)
			handle_east_wall(data, &x, &y);
        else if (data->ray_trc.cardinal_collision == NORTH)
			handle_north_wall(data, &x, &y);
        else
			handle_west_wall(data, &x, &y);
    }
    data->render_data->player_x = x; 
    data->render_data->player_y = y; 
}