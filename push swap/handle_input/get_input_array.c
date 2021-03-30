/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:52:12 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/30 19:20:03 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	fill_array(int **array, t_list *array_list)
{
	int	i;

	i = 0;
	array[0] = ft_alloc(ft_lstsize(array_list), sizeof(int));
	if (!array[0])
		return ;
	while (array_list)
	{
		array[0][i] = ((int *)array_list->content)[0];
		array_list = array_list->next;
		i++;
	}
}

static	void	print_error_and_exit(t_list **array_list, char *line)
{
	ft_printf(STDERR_FILENO, "Error\n");
	ft_lstclear(array_list, free);
	free(line);
	exit(-1);
}

static	void	add_nb_to_array(char *line, t_list **array_list)
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
		print_error_and_exit(array_list, line);
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

int	*get_input_array(int fd)
{
	t_list	*array_list;
	char	*line;
	int		*array;

	array_list = NULL;
	if (fd == STDIN_FILENO)
		printf("Please input the values for the array:\n");
	while (true)
	{
		line = read_input(fd);
		if (!ft_strncmp(line, "", 1))
		{
			free(line);
			break ;
		}
		add_nb_to_array(line, &array_list);
	}
	fill_array(&array, array_list);
	ft_lstclear(&array_list, free);
	return (array);
}
