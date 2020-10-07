/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 10:23:24 by user42            #+#    #+#             */
/*   Updated: 2020/09/24 13:26:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			free_textures(s_render_data *render_data)
{
	if(render_data->east_texture)
		free(render_data->east_texture);
	if(render_data->north_texture)
		free(render_data->north_texture);
	if(render_data->west_texture)
		free(render_data->west_texture);
	if(render_data->south_texture)
		free(render_data->south_texture);
}
s_render_data *free_render_data(s_render_data *render_data)
{
	int i;

	i = 0;
	if (render_data)
	{
		if (render_data->map)
		{
			while (render_data->map[i])
			{
				free(render_data->map[i]);
				i++;
			}
			free(render_data->map);
		}
		free_textures(render_data);
		free(render_data);
	}
	return (0);
}

void				end_get_next_line(char *line, int fd)
{
	while (get_next_line(fd, &line))
	{
		free(line);
	}
	if (line)
		free(line);
}

s_render_data   *read_file (char *data_file)
{
	int             fd;
	s_render_data   *render_data;
	char            *line;
	s_error			*error;
	int i;

	if (!(render_data = ft_calloc(1, sizeof(s_render_data))))
		return (0); //Should probably change these to something else?
	if (!(error = ft_calloc(1, sizeof(s_error))))
		return (free_render_data(render_data)); //Should probably change these to something else?
	if((fd = open(data_file, O_RDONLY)) && fd == -1)
		error->error_id = 2;
	while(!(error->error_id && print_error(error)))
	{
		i = get_next_line(fd, &line);
		fill_render_struct(render_data, line, error, fd, data_file);
		if (!error->error_id)
		{
			error->line++;
			error->row = 0;
		}
		if (!i)
			break ;
	}
	if (error->error_id)
	{
		end_get_next_line(line, fd);
		free(error);
		free_render_data(render_data);
		return (0);
	}
	free(error);
	return (render_data); // shouldn't be needed;
}

int		fill_resolution(char *line, s_render_data *render_data, s_error *error)
{
	if (!(render_data->res_x = ft_atoi(line)))
		return (4);
	while (ft_isspace(*line))
		advance_file_line(&line, error);
	while(*line)
	{
		if (ft_isdigit(*line))
			advance_file_line(&line, error);
		else if (ft_isspace(*line))
			break ;
		else
			return (4);
	}
	if (!(render_data->res_y = ft_atoi(line)))
		return (4);
	while (*line)
	{
		if (ft_isspace(*line) || ft_isdigit(*line))
			advance_file_line(&line, error);
		else
			return (4);
	}
	return (0);
}

int check_if_image(char *str)
{
	if (!ft_strncmp(str, "\x89PNG\r\n\x1a\n", 8) ||
			!ft_strncmp(str, "\xff\xd8\xff", 3))
		return (1);
	return (0);
}

int	get_texture_size(int fd, char *path)
{
	int size;
	int bytes_read;
	char str[9];

	size = 0;
	str[8] = 0;
	if((open(path, O_RDONLY) == -1))
		return (-1);
	while ((bytes_read = read(fd, str, 8)))
	{
		size += bytes_read;
		if(size == 8 && !check_if_image(str))
			return(-1);
	}
	return (size ? size : -1);
}

void add_texture(char **texture, char *line, s_error *s_error)
{
	int fd;
	int size;

	if (*texture)
	{
		s_error->error_id = 3;
		return ;
	}
	line = line + 2;
	while (ft_isspace(*line))
		line++;
	fd = open(line, O_RDONLY);
	if ((size = get_texture_size(fd, line)) == -1)
	{
		s_error->error_id = 10;
		return ;
	}
	close(fd);
	fd = open(line, O_RDONLY);
	if (!(*texture = ft_calloc(1, size + 1)))
		s_error->error_id = 1;
	read(fd, *texture, size);
	return ;
}

void	fill_render_struct(s_render_data *render_data, char *line, s_error *error, int fd, char * path)
{
	if (!line || *line == 0)
		error->error_id = 0;
	else if (*line == 'R')
		error->error_id = fill_resolution(line + 1, render_data, error);
	else if (!(ft_strncmp(line, "NO", 2)))
		add_texture(&render_data->north_texture, line, error);
	else if (!(ft_strncmp(line, "SO", 2)))
		add_texture(&render_data->south_texture, line, error);
	else if (!(ft_strncmp(line, "WE", 2)))
		add_texture(&render_data->west_texture, line, error);
	else if (!(ft_strncmp(line, "EA", 2)))
		add_texture(&render_data->east_texture, line, error);
	else if (*line == '1' || *line == ' ')
	{
		handle_map(render_data, error, line, fd, path);
		return ;
	}
	else
	{
		free(line);
		error->error_id = 5;
		return ;
	}
		free(line);
	return ;
}
int fill_map_bearings (s_map_bearings *map_info, s_error *error, char *line, int i)
{
	if(line[i] == '1')
	{
		if (map_info->top_one == 0)
			map_info->top_one = error->line;
		map_info->bot_one = error->line;
		if (map_info->left_one > i)
			map_info->left_one = i;
		if (map_info->right_one < i)
			map_info->right_one = i;
	}
	else if (ft_checkchar(line[i], "NWSE"))
	{
		if (map_info->player_pos_x || map_info->player_pos_y)
			return ((error->error_id = 8) && (error->row = i));
		line[i] = '0';
		map_info->player_pos_x = i;
		map_info->player_pos_y = error->line - map_info->top_one;
	}
	else if (!ft_checkchar(line[i], "02") && !(line[i] == ' '))
	{
		error->row = i;
		return (error->error_id = 6);
	}
	return 0;
}

s_map_bearings *free_map_bearings(s_map_bearings *map_info, char *line)
{
	if(line)
		free(line);
	if(map_info)
		free(map_info);
	return (0);
}

s_map_bearings		*check_map_basic_elements(char *line, s_error *error, int fd)
{
	s_map_bearings	*map_info;
	int i;

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
		line = 0;
		get_next_line(fd, &line);
	}
	free (line);
	if (!map_info->bot_one && !map_info->left_one && !map_info->right_one
		&& !map_info->top_one)
		return (free_map_bearings(map_info, 0) + !(error->error_id = 6));
	if (!map_info->player_pos_x || !map_info->player_pos_y)
		return (free_map_bearings(map_info, 0) + !(error->error_id = 7));
	return (map_info);
}

char	**copy_map(s_map_bearings *map_info, int fd, char *path)
{
	char **map;
	char *line;
	int i;
	int j;

	i = 0;
	j = 0;
	if (!(map = ft_calloc(map_info->bot_one - map_info->top_one + 2, sizeof(char*))))
		return (0);
	close(fd);
	fd = open(path, O_RDONLY);
	while (i < map_info->top_one)
	{
		get_next_line(fd, &line);
		free(line);
		i++;
	}
	while (i < map_info->bot_one + 1)
	{
		get_next_line(fd, &line);
		map[j] = line;
		i++;
		j++;
	}
	get_next_line(fd, &line);
	free(line);
	return (map);
}

int check_for_spaces(char **map, int i, int j)
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
	return (0);
}

int set_error_value(int id, int i, int j, s_error *error)
{
	error->error_id = id;
	error->line = i;
	error->row = j;
	return (1);
}

int check_map_coherence(char **map, s_error *error)
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

void	handle_map(s_render_data *render_data, s_error *error, char *str, int fd, char *path)
{
	s_map_bearings *map_info;
	if (!(map_info = check_map_basic_elements(str, error, fd)))
	{
		end_get_next_line(str, fd);	
		return ;
	}
	render_data->player_x = map_info->player_pos_x;
	render_data->player_y = map_info->player_pos_y;
	render_data->map = copy_map(map_info, fd, path);
	free(map_info);
	if (check_map_coherence(render_data->map, error))
		return ;
}

void	advance_file_line(char **line, s_error *error)
{
	*line = *line + 1;
	error->row++;
}

int		print_error(s_error * error)
{
	char *s;

	ft_putstr_fd("Error\n", 1);
	if (error->error_id == 1)
		ft_putstr_fd("Ran out of memory\n", 1);
	if (error->error_id == 2)
		ft_putstr_fd("Couldn't open file!\n", 1);
	else if (error->error_id == 3)
		ft_putstr_fd("Repeated textures!\n", 1);
	else if (error->error_id == 4)
		ft_putstr_fd("Wrong resolution input!\n", 1);
	else if (error->error_id == 5)
		ft_putstr_fd("Wrong input!\n", 1);
	else if (error->error_id == 6)
		ft_putstr_fd("Wrong map input!\n", 1);
	else if (error->error_id == 7)
		ft_putstr_fd("No player position!\n", 1);
	else if (error->error_id == 8)
		ft_putstr_fd("Multiple player positions!\n", 1);
	else if (error->error_id == 9)
		ft_putstr_fd("Map not enclosed!\n", 1);
	else if (error->error_id == 10)
		ft_putstr_fd("Invalid texture file!\n", 1);
	if (error->error_id > 1 && error->error_id != 7)
	{
		s = ft_itoa(error->line);
		ft_putstr_fd("At line: ", 1);
		ft_putstr_fd(s, 1);
		free(s);
		s = ft_itoa(error->row);
		ft_putstr_fd(", column ", 1);
		ft_putstr_fd(s, 1);
		free(s);
		ft_putstr_fd(";\n", 1);
	}
	return (1);
}
/*
R   = resolution
NO  = north texture
SO  = south texture
WE  = west texture
EA  = East texture
s   = sprite
F   = Floor
C   = Ceiling

*/   