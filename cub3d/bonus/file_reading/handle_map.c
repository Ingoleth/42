/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 11:24:55 by user42            #+#    #+#             */
/*   Updated: 2020/12/17 00:02:52 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**copy_map(s_map_bearings *map_info)
{
	char			**map;
	int				i;
	t_gnl_buffer	*buffer;

	i = 0;
	if (!(map = ft_calloc(map_info->bot_one - map_info->top_one + 3,
	sizeof(char*))))
		return (0);
	buffer = map_info->map_struct;
	while (buffer)
	{
		if (i == map_info->player_pos_y)
			buffer->line[map_info->player_pos_x] = '0';
		map[i] = buffer->line;
		i++;
		buffer = buffer->next;
	}
	i = 0;
	free_gnl_buffer(map_info->map_struct, false);
	return (map);
}

int		check_for_spaces(char **map, int i, int j, int k)
{
	if (i == 0 || j == 0 || !map[i + 1])
		return (1);
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
			if (ft_checkchar(map[i][j], "02345") &&
			check_for_spaces(map, i, j, 0))
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
	s_map_bearings map_info;

	ft_memset(&map_info, 0, sizeof(s_map_bearings));
	fill_gnl_buffer(&map_info.map_struct, str);
	gnl_buffer(file->fd, 0, &map_info.map_struct);
	if (!check_map_basic_elements(&map_info, error))
	{
		free_gnl_buffer(map_info.map_struct, 1);
		return ;
	}
	render_data->player_x = map_info.player_pos_x + 0.5;
	render_data->player_y = map_info.player_pos_y + 0.5;
	render_data->view_angle = map_info.view_angle;
	render_data->map = copy_map(&map_info);
	check_map_coherence(render_data->map, error);
}
