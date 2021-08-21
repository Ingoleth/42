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
