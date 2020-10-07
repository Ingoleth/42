/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 11:24:55 by user42            #+#    #+#             */
/*   Updated: 2020/10/07 17:03:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		set_starting_copy_position(s_file_descriptor *file,
s_map_bearings *map_info, char **line)
{
	int i;

	i = 0;
	close(file->fd);
	file->fd = open(file->path, O_RDONLY);
	while (i < map_info->top_one)
	{
		get_next_line(file->fd, line);
		free(*line);
		i++;
	}
	return (i);
}

char	**copy_map(s_map_bearings *map_info, s_file_descriptor *file)
{
	char	**map;
	char	*line;
	int		i;
	int		j;
	int		player_pos_absolute;

	j = 0;
	player_pos_absolute = map_info->top_one + map_info->player_pos_y;
	if (!(map = ft_calloc(map_info->bot_one - map_info->top_one + 2,
	sizeof(char*))))
		return (0);
	i = set_starting_copy_position(file, map_info, &line);
	while (i < map_info->bot_one + 1)
	{
		get_next_line(file->fd, &line);
		if (i == player_pos_absolute)
			line[map_info->player_pos_x] = '0';
		map[j] = line;
		i++;
		j++;
	}
	get_next_line(file->fd, &line);
	free(line);
	return (map);
}

int		check_for_spaces(char **map, int i, int j)
{
	int k;

	if (i == 0 || j == 0 || !map[i + 1])
		return (1);
	k = 0;
	if (i > 0)
	{
		while (map[i - 1][k] && k < j)
			k++;
		if (k < j || (map[i - 1][j] == ' '))
			return (1);
	}
	else
		return (1);
	if ((map[i][j - 1] == ' ') || map[i][j + 1] == ' ' || !map[i][j + 1])
		return (1);
	if (map[i + 1])
	{
		k = 0;
		while (map[i + 1][k] && k < j)
			k++;
		if (k < j || (map[i + 1][j] == ' '))
			return (1);
	}
	else
		return (1);
	return (0);
}

int		check_map_coherence(char **map, s_error *error)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (ft_checkchar(map[i][j], "02") && check_for_spaces(map, i, j))
				return (set_error_value(9, i, j, error));
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	handle_map(s_render_data *render_data, s_error *error,
char *str, s_file_descriptor *file)
{
	s_map_bearings *map_info;

	if (!(map_info = check_map_basic_elements(str, error, file->fd)))
	{
		end_get_next_line(str, file->fd);
		return ;
	}
	render_data->player_x = map_info->player_pos_x;
	render_data->player_y = map_info->player_pos_y;
	render_data->offset_x = MAX_OFFSET / 2;
	render_data->offset_y = MAX_OFFSET / 2;
	render_data->view_angle = map_info->view_angle;
	render_data->map = copy_map(map_info, file);
	free(map_info);
	if (check_map_coherence(render_data->map, error))
		return ;
}
