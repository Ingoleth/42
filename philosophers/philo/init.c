/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 10:18:30 by aiglesia          #+#    #+#             */
/*   Updated: 2021/09/21 10:18:31 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_bool	init_mutexes(int size)
{
	int	i;
	int	error;

	i = 0;
	size += 2;
	g_philo_common.mutexes = malloc((size + 1) * sizeof(pthread_mutex_t *));
	if (!g_philo_common.mutexes)
		return (false);
	memset(g_philo_common.mutexes, 0, sizeof(pthread_mutex_t *) * (size + 1));
	while (i < size)
	{
		g_philo_common.mutexes[i] = malloc(sizeof(pthread_mutex_t));
		if (!g_philo_common.mutexes[i])
			return (false);
		error = pthread_mutex_init(g_philo_common.mutexes[i], NULL);
		if (error)
			return (false);
		i++;
	}
	g_philo_common.communication = g_philo_common.mutexes[size - 1];
	g_philo_common.end_condition_mutex = g_philo_common.mutexes[size - 2];
	return (true);
}

t_bool	*init_bool(int size, t_bool initial_value)
{
	t_bool	*bool;
	int		i;

	bool = malloc((size + 1) * sizeof (t_bool));
	if (bool == NULL)
		return (NULL);
	i = 0;
	if (initial_value != false)
		initial_value = true;
	while (i < size)
		bool[i++] = initial_value;
	bool[size] = 0;
	return (bool);
}

/*
** //TODO: Should probably call kill threads
** 
*/

int	init_data(int size)
{
	g_philo_common.end_condition = init_bool(size + 1, false);
	if (g_philo_common.end_condition == NULL)
		return (free_memory(-1));
	if (!init_mutexes(size))
		return (free_memory(-1));
	if (!init_threads(size))
		return (free_memory(-1));
	return (0);
}
