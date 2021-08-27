#include "philosophers.h"

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
	pthread_mutex_lock(g_philo_common.communication);
	printf("%li %i %s\n", get_current_timestamp(), philo_id, message);
	pthread_mutex_unlock(g_philo_common.communication);
}

void	set_end_condition(t_philo *philo, t_bool he_dead)
{
	pthread_mutex_lock(g_philo_common.end_condition_mutex);
	if (he_dead)
		g_philo_common.end_condition[0] = true;
	else
		g_philo_common.end_condition[philo->philo_id] = true;
	pthread_mutex_unlock(g_philo_common.end_condition_mutex);
	if (he_dead)
	{
		display_message(philo->philo_id, "died");
		pthread_mutex_unlock(philo->left_fork_mutex);
		pthread_mutex_unlock(philo->right_fork_mutex);
		pthread_mutex_lock(g_philo_common.communication);
	}
}

int	free_memory(int return_value)
{
	int	i;

	if (g_philo_common.threads)
		free(g_philo_common.threads);
	if (g_philo_common.mutexes)
	{
		i = 0;
		while (g_philo_common.mutexes[i])
		{
			pthread_mutex_destroy(g_philo_common.mutexes[i]);
			free(g_philo_common.mutexes[i++]);
		}
		free(g_philo_common.mutexes);
	}
	if (g_philo_common.end_condition)
		free(g_philo_common.end_condition);
	if (g_philo_common.structs)
	{
		i = 0;
		while (g_philo_common.structs[i])
			free(g_philo_common.structs[i++]);
		free(g_philo_common.structs);
	}
	return (return_value);
}

void	kill_threads(void)
{
	int	i;

	i = 0;
	while (i < g_philo_common.philosophers)
	{
		pthread_detach(g_philo_common.threads[i]);
		i++;
	}
	exit(free_memory(0));
}
