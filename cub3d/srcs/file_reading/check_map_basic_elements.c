/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_basic_elements.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 16:17:13 by user42            #+#    #+#             */
/*   Updated: 2020/12/17 00:02:52 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_player_position(s_map_bearings *map_info, s_error *error,
char *line, int i)
{
	if (map_info->player_pos_x || map_info->player_pos_y)
	{
		error->row = i;
		return ((error->error_id = 8));
	}
	if (line[i] == 'E')
		map_info->view_angle = ANGLE_0_5;
	if (line[i] == 'N')
		map_info->view_angle = PI_2 + ANGLE_0_5;
	if (line[i] == 'W')
		map_info->view_angle = PI + ANGLE_0_5;
	if (line[i] == 'S')
		map_info->view_angle = PI1_1_2 + ANGLE_0_5;
	line[i] = '0';
	map_info->player_pos_x = i;
	map_info->player_pos_y = error->line - map_info->top_one;
	return (0);
}

int	fill_map_bearings(s_map_bearings *map_info, s_error *error,
char *line, int i)
{
	if (line[i] == '1')
	{
		if (map_info->top_one == 0)
			map_info->top_one = error->line;
		map_info->bot_one = error->line;
		if (map_info->left_one > i)
			map_info->left_one = i;
		if (map_info->right_one < i)
			map_info->right_one = i;
	}
	else if (ft_checkchar(line[i], "NWSE") &&
		handle_player_position(map_info, error, line, i))
		return (1);
	else if (!ft_checkchar(line[i], "02 "))
	{
		error->row = i;
		return (error->error_id = 6);
	}
	return (0);
}

int	check_map_basic_elements(s_map_bearings *map_info, s_error *error)
{
	t_gnl_buffer	*aux;
	int				i;

	aux = map_info->map_struct;
	while (aux->next)
	{
		i = 0;
		while (aux->line[i])
		{
			if (fill_map_bearings(map_info, error, aux->line, i))
				return (0);
			i++;
		}
		error->line++;
		aux = aux->next;
	}
	if (!map_info->bot_one && !map_info->left_one && !map_info->right_one
		&& !map_info->top_one)
		return (!(error->error_id = 6));
	if (!map_info->player_pos_x || !map_info->player_pos_y)
		return (!(error->error_id = 7));
	return (1);
}
