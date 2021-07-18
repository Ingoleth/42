#include "philosophers.h"

/*
**    Gets the current timestamp in milliseconds
*/
long    get_current_timestamp(void)
{
	struct timeval		tv;
	long				time_in_ms;

	gettimeofday(&tv, NULL);
	time_in_ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time_in_ms);
}

t_bool	manipulate_fork(int philo_id, t_bool *fork_in_table, pthread_mutex_t *mutex, t_bool take)
{
	t_bool ret;

	ret = false;
	pthread_mutex_lock(mutex); //TODO: check if forks start duplicating for some reason...
	if (take == true && *fork_in_table)
	{
			*fork_in_table = false;
			ret = true;
			display_message(philo_id, "has taken a fork!");
	}
	else if (take == false)
	{
			*fork_in_table = true;
			ret = false;
			display_message(philo_id, "has left a fork!");
	}
	//else
	//	display_message(philo_id, "has tried to take a fork but failed!");
	pthread_mutex_unlock(mutex);
	return (ret);
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
			g_philo_common.end_condition[philo_id + 1] = true;
			display_message(philo_id, "is done eating"); //TODO: Remove!
		}
		pthread_mutex_unlock(g_philo_common.end_condition_mutex);
}
