/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:52:12 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/31 18:38:12 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	fill_array(t_array_info *arrays, t_list *array_list)
{
	int	i;

	i = 0;
	arrays->array_a = ft_alloc(ft_lstsize(array_list), sizeof(int));
	if (!arrays->array_a)
	{
		ft_lstclear(&array_list, free);
		ft_printf(STDERR_FILENO, "Error\n");
		exit (1);
	}
	while (array_list)
	{
		arrays->array_a[i] = ((int *)array_list->content)[0];
		array_list = array_list->next;
		i++;
	}
	arrays->array_a_length = i;
}

static	void	print_error_and_exit(t_list **array_list, char *line,
	int error, t_bool verbose)
{
	if (!verbose)
		ft_printf(STDERR_FILENO, "Error\n");
	else
	{
		if (error == not_nb)
			ft_printf(STDERR_FILENO, "Error: Not numeric input!\n");
		else if (error == max_int)
			ft_printf(STDERR_FILENO, "Error: Input bigger than int!\n");
		else if (error == repeated)
			ft_printf(STDERR_FILENO, "Error: Duplicate number!\n");
	}
	ft_lstclear(array_list, free);
	free(line);
	exit(-1);
}

static	void	add_nb_to_array(char *line, t_list **array_list, t_bool verbose)
{
	int			error;
	int			*nb;
	int			aux;

	error = 0;
	if (!is_number(line))
		error = not_nb;
	aux = ft_atoi(line);
	if (is_long_int(line))
		error = max_int;
	if (is_repeated(aux, array_list[0]))
		error = repeated;
	if (!error)
	{
		free(line);
		nb = ft_alloc(1, sizeof(int));
		if (nb)
		{
			nb[0] = aux;
			ft_lstadd_back(array_list, ft_lstnew(nb));
		}
	}
	else
		print_error_and_exit(array_list, line, error, verbose);
}

char	*read_input(int fd)
{
	char	*line;
	char	*aux;
	int		bytes_read;
	char	buffer[2];

	line = ft_strdup("");
	buffer[1] = 0;
	while (true)
	{
		bytes_read = read(fd, buffer, 1);
		if (!bytes_read || buffer[0] == '\n')
			break ;
		aux = ft_strjoin(line, buffer);
		free(line);
		line = aux;
	}
	return (line);
}

void	get_input_array(int fd, t_array_info *arrays, t_bool verbose)
{
	t_list	*array_list;
	char	*line;

	array_list = NULL;
	if (fd == STDIN_FILENO && verbose)
		printf("Please input the values for the array:\n");
	while (true)
	{
		line = read_input(fd);
		if (!ft_strncmp(line, "", 1))
		{
			free(line);
			break ;
		}
		add_nb_to_array(line, &array_list, verbose);
	}
	fill_array(arrays, array_list);
	ft_lstclear(&array_list, free);
}
