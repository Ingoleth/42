/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 11:44:33 by user42            #+#    #+#             */
/*   Updated: 2020/11/12 14:22:18 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		set_error_value(int id, int i, int j, s_error *error)
{
	error->error_id = id;
	error->line = i;
	error->row = j;
	return (1);
}

void	print_error_description(s_error *error)
{
	if (error->error_id == 1)
		ft_putstr_fd("Ran out of memory\n", 1);
	if (error->error_id == 2)
		ft_putstr_fd("Couldn't open file!\n", 1);
	else if (error->error_id == 3)
		ft_putstr_fd("Repeated texture definition!\n", 1);
	else if (error->error_id == 4)
		ft_putstr_fd("Wrong resolution input!\n", 1);
	else if (error->error_id == 5)
		ft_putstr_fd("Wrong input!\n", 1);
	else if (error->error_id == 6)
		ft_putstr_fd("Wrong map input!\n", 1); //You, mister seg fault...
	else if (error->error_id == 7)
		ft_putstr_fd("No player position!\n", 1);
	else if (error->error_id == 8)
		ft_putstr_fd("Multiple player positions!\n", 1);
	else if (error->error_id == 9)
		ft_putstr_fd("Map not enclosed!\n", 1);
	else if (error->error_id == 10)
		ft_putstr_fd("Invalid texture file!\n", 1);
	else if (error->error_id == 11)
		ft_putstr_fd("Wrong colour input!\n", 1);
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
