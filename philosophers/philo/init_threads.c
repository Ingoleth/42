/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 10:18:19 by aiglesia          #+#    #+#             */
/*   Updated: 2021/09/21 10:18:21 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	*load_philosopher_data(int i, int size)
{
	t_philo	*aux;

	aux = malloc(sizeof(t_philo));
	if (aux == NULL)
		return (NULL);
	memset(aux, 0, sizeof(t_philo));
	aux->eat_amount = g_philo_common.eat_amount;
	aux->philo_id = i + 1;
	if (i == 0)
		aux->right_fork_mutex = g_philo_common.mutexes[size - 1];
	else
		aux->right_fork_mutex = g_philo_common.mutexes[i - 1];
	aux->left_fork_mutex = g_philo_common.mutexes[i];
	return (aux);
}

t_bool	init_philosopher_threads(int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (!(i % 2))
		{
			if (pthread_create(&g_philo_common.threads[i], NULL, &live,
					g_philo_common.structs[i]))
				return (false);
			usleep(1000);
		}
	}
	i = -1;
	while (++i < size)
	{
		if (i % 2)
		{
			if (pthread_create(&g_philo_common.threads[i], NULL, &live,
					g_philo_common.structs[i]))
				return (false);
		}
	}
	return (true);
}

t_bool	init_threads(int size)
{
	int	i;

	i = -1;
	g_philo_common.threads = malloc((size + 1) * sizeof (pthread_t *));
	if (g_philo_common.threads == NULL)
		return (false);
	g_philo_common.threads[size] = 0;
	g_philo_common.structs = malloc((size + 1) * sizeof (t_philo *));
	if (g_philo_common.threads == NULL)
		return (false);
	g_philo_common.structs[size] = 0;
	while (++i < size)
	{
		g_philo_common.structs[i] = load_philosopher_data(i, size);
		if (g_philo_common.structs[i] == NULL)
			return (false);
	}
	g_philo_common.start_time = get_current_timestamp();
	return (init_philosopher_threads(size));
}
