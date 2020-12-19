/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 11:44:33 by user42            #+#    #+#             */
/*   Updated: 2020/12/19 12:19:59 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		set_error_value(int id, int i, int j, s_error *error)
{
	error->error_id = id;
	error->line = i;
	error->row = j;
	return (1);
}

void	print_error_description(s_error *error)
{
	if (error->error_id == out_of_memory)
		ft_putstr_fd("Ran out of memory\n", 1);
	if (error->error_id == wrong_file)
		ft_putstr_fd("Couldn't open file!\n", 1);
	else if (error->error_id == repeated_texture)
		ft_putstr_fd("Repeated texture definition!\n", 1);
	else if (error->error_id == wrong_resolution)
		ft_putstr_fd("Wrong resolution input!\n", 1);
	else if (error->error_id == wrong_input)
		ft_putstr_fd("Wrong input!\n", 1);
	else if (error->error_id == wrong_map_input)
		ft_putstr_fd("Wrong map input!\n", 1);
	else if (error->error_id == no_player)
		ft_putstr_fd("No player position!\n", 1);
	else if (error->error_id == multiple_player)
		ft_putstr_fd("Multiple player positions!\n", 1);
	else if (error->error_id == map_not_enclosed)
		ft_putstr_fd("Map not enclosed!\n", 1);
	else if (error->error_id == invalid_texture)
		ft_putstr_fd("Invalid texture file!\n", 1);
	else if (error->error_id == wrong_colour)
		ft_putstr_fd("Wrong colour input!\n", 1);
	else if (error->error_id == file_not_cub)
		ft_putstr_fd("File doesn't end in .cub!\n", 1);
	else if (error->error_id == repeated_colour)
		ft_putstr_fd("Repeated colour definition!\n", 1);
}

int		print_error(s_error *error)
{
	char *s;

	ft_putstr_fd("Error\n", 1);
	print_error_description(error);
	if (error->error_id > 2 && error->error_id != 7)
	{
		s = ft_itoa(error->line + 1);
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

void	advance_file_line(char **line, s_error *error)
{
	*line = *line + 1;
	error->row++;
}
