/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 10:18:42 by aiglesia          #+#    #+#             */
/*   Updated: 2021/09/22 15:39:06 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	safe_sleep(int miliseconds)
{
	const long	start = get_current_timestamp();
	const long	end = start + miliseconds;
	long		current;

	current = start;
	while (!g_philo_common.end_condition[0] && current < end)
	{
		if (end - current > 10)
			usleep(10000);
		else
			usleep((end - current) * 1000);
		current = get_current_timestamp();
	}
}

void	eat(t_philo *philo)
{
	if (!g_philo_common.end_condition[0])
		pthread_mutex_lock(philo->left_fork_mutex);
	display_message(philo->philo_id, "has taken a fork");
	if (!g_philo_common.end_condition[0])
		pthread_mutex_lock(philo->right_fork_mutex);
	display_message(philo->philo_id, "has taken a fork");
	display_message(philo->philo_id, "is eating");
	if (philo->eat_amount)
	{
		philo->eat_amount--;
		if (philo->eat_amount == 0)
			set_end_condition(philo);
	}
	philo->time_since_last_eaten = get_current_timestamp();
	safe_sleep(g_philo_common.eat_time);
	display_message(philo->philo_id, "is sleeping");
	pthread_mutex_unlock(philo->left_fork_mutex);
	pthread_mutex_unlock(philo->right_fork_mutex);
}

void	*live(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->time_since_last_eaten = get_current_timestamp();
	while (true)
	{		
		if (g_philo_common.end_condition[0])
		{
			free(philo);
			return (NULL);
		}
		if (!g_philo_common.end_condition[0])
		{
			eat(philo);
			safe_sleep(g_philo_common.sleep_time);
			display_message(philo->philo_id, "is thinking");
		}
	}
	return (NULL);
}
