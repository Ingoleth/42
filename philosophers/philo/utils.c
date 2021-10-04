/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 10:19:06 by aiglesia          #+#    #+#             */
/*   Updated: 2021/09/22 15:36:54 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	get_raw_timestamp(void)
{
	struct timeval		tv;
	long				time_in_ms;

	gettimeofday(&tv, NULL);
	time_in_ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time_in_ms - g_philo_common.start_time);
}

/*
**	Gets the current timestamp in milliseconds
*/
long	get_current_timestamp(void)
{
	struct timeval		tv;
	long				time_in_ms;

	gettimeofday(&tv, NULL);
	time_in_ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time_in_ms - g_philo_common.start_time);
}

void	display_message(int philo_id, char *message)
{
	if (g_philo_common.end_condition[0])
		return ;
	pthread_mutex_lock(g_philo_common.communication);
	printf("%li %i %s\n", get_current_timestamp(), philo_id, message);
	pthread_mutex_unlock(g_philo_common.communication);
}

void	set_end_condition(t_philo *philo)
{
	pthread_mutex_lock(g_philo_common.end_condition_mutex);
	g_philo_common.end_condition[philo->philo_id] = true;
	pthread_mutex_unlock(g_philo_common.end_condition_mutex);
}

int	free_memory(int return_value)
{
	int	i;

	free(g_philo_common.threads);
	free(g_philo_common.structs);
	i = 0;
	while (g_philo_common.mutexes[i])
	{
		pthread_mutex_destroy(g_philo_common.mutexes[i]);
		free(g_philo_common.mutexes[i++]);
	}
	free(g_philo_common.mutexes);
	free(g_philo_common.end_condition);
	return (return_value);
}
