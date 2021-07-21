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

void	leave_fork(t_philo *philo, t_bool right_fork)
{
	t_bool			*fork_in_table;
	t_bool			*philo_fork;
	pthread_mutex_t	*mutex;

	if (right_fork == true)
	{
		philo_fork = &philo->right_fork;
		fork_in_table = philo->right_table_fork;
		mutex = philo->right_fork_mutex;
	}
	else
	{
		philo_fork = &philo->left_fork;
		fork_in_table = philo->left_table_fork;
		mutex = philo->left_fork_mutex;
	}
	pthread_mutex_lock(mutex);
	if (*fork_in_table)
		display_message(philo->philo_id, "Has duplicated a fork!\n"); //TODO:REMOVE
	*fork_in_table = true;
	*philo_fork = false;
	display_message(philo->philo_id, "has left a fork!");
	pthread_mutex_unlock(mutex);
}

void	take_fork(t_philo *philo, t_bool right_fork)
{
	t_bool			*fork_in_table;
	t_bool			*philo_fork;
	pthread_mutex_t	*mutex;

	if (right_fork == true)
	{
		philo_fork = &philo->right_fork;
		fork_in_table = philo->right_table_fork;
		mutex = philo->right_fork_mutex;
	}
	else
	{
		philo_fork = &philo->left_fork;
		fork_in_table = philo->left_table_fork;
		mutex = philo->left_fork_mutex;
	}
	if (*philo_fork)
		return ;
	pthread_mutex_lock(mutex);
	if (*fork_in_table)
	{
		*fork_in_table = false;
		*philo_fork = true;
		display_message(philo->philo_id, "has taken a fork!");
	}
	pthread_mutex_unlock(mutex);
}

void	display_message(int philo_id, char *message)
{
	pthread_mutex_lock(g_philo_common.communication);
	printf("%li %i %s\n", get_current_timestamp(), philo_id, message);
	pthread_mutex_unlock(g_philo_common.communication);
}

void	set_end_condition(int philo_id, t_bool he_dead)
{
	pthread_mutex_lock(g_philo_common.end_condition_mutex);
	if (he_dead)
	{
		g_philo_common.end_condition[0] = true;
		display_message(philo_id, "is dead");
	}
	else
	{
		g_philo_common.end_condition[philo_id] = true;
		display_message(philo_id, "is done eating"); //TODO: Remove!
	}
	pthread_mutex_unlock(g_philo_common.end_condition_mutex);
}
