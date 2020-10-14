/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_basic_elements.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 16:17:13 by user42            #+#    #+#             */
/*   Updated: 2020/10/14 16:38:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int				handle_player_position(s_map_bearings *map_info, s_error *error,
char *line, int i)
 {
	if (map_info->player_pos_x || map_info->player_pos_y)
		return ((error->error_id = 8) &&
				(error->row = i));
	if (line[i] == 'E')
		map_info->view_angle = 0;
	if (line[i] == 'N')
		map_info->view_angle = PI_2;
	if (line[i] == 'W')
		map_info->view_angle = PI;
	if (line[i] == 'S')
		map_info->view_angle = PI1_1_2;
	line[i] = '0';
	map_info->player_pos_x = i;
	map_info->player_pos_y = error->line - map_info->top_one;
	return (0);
 }

int				fill_map_bearings(s_map_bearings *map_info, s_error *error,
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
	else if (!ft_checkchar(line[i], "02") && !(line[i] == ' '))
	{
		error->row = i;
		return (error->error_id = 6);
	}
	return (0);
}

s_map_bearings	*free_map_bearings(s_map_bearings *map_info, char *line)
{
	if (line)
		free(line);
	if (map_info)
		free(map_info);
	return (0);
}

s_map_bearings	*check_map_basic_elements(char *line, s_error *error, int fd)
{
	s_map_bearings	*map_info;
	int				i;

	if (!(map_info = ft_calloc(1, sizeof(s_map_bearings))))
		return (map_info + !(error->error_id = 1));
	while (*line)
	{
		i = 0;
		while (line[i])
		{
			if (fill_map_bearings(map_info, error, line, i))
				return (free_map_bearings(map_info, line));
			i++;
		}
		error->line++;
		free(line);
		get_next_line(fd, &line);
	}
	free(line);
	if (!map_info->bot_one && !map_info->left_one && !map_info->right_one
		&& !map_info->top_one)
		return (free_map_bearings(map_info, 0) + !(error->error_id = 6));
	if (!map_info->player_pos_x || !map_info->player_pos_y)
		return (free_map_bearings(map_info, 0) + !(error->error_id = 7));
	return (map_info);
}
