#include "philosophers.h"

t_bool	smart_sleep(int sleep_time, long int time_since_last_eaten)
{
	long int elapsed_time;

	elapsed_time = get_current_timestamp() - time_since_last_eaten;
	if (elapsed_time + sleep_time > g_philo_common.starvation_time)
	{
		usleep((g_philo_common.starvation_time - elapsed_time) * 1000);
		return (false);
	}
	usleep(sleep_time * 1000);
	return (true);
}

t_bool	should_die(t_philo *philo, int starvation_time)
{
	long	current_time;

	if (philo->left_fork_mutex == philo->right_fork_mutex)
	{
		display_message(philo->philo_id, "has taken a fork");
		usleep(g_philo_common.starvation_time * 1000);
		return (true);
	}
	current_time = get_current_timestamp();
	if (current_time - philo->time_since_last_eaten >= starvation_time)
		return (true);
	return (false);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork_mutex);
	display_message(philo->philo_id, "has taken a fork");
	pthread_mutex_lock(philo->right_fork_mutex);
	display_message(philo->philo_id, "has taken a fork");
	display_message(philo->philo_id, "is eating");
	if (philo->eat_amount)
	{
		philo->eat_amount--;
		if (philo->eat_amount == 0)
			set_end_condition(philo->philo_id, false);
	}
	philo->time_since_last_eaten = get_current_timestamp();
	smart_sleep(g_philo_common.eat_time, philo->time_since_last_eaten);
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
		if (should_die(philo, g_philo_common.starvation_time))
		{
			set_end_condition(philo->philo_id, true);
			return (NULL);
		}
		eat(philo);
		if (get_current_timestamp() - philo->time_since_last_eaten + g_philo_common.eat_time
			> g_philo_common.starvation_time)
			smart_sleep(g_philo_common.eat_time, philo->time_since_last_eaten);
		else if (smart_sleep(g_philo_common.sleep_time, philo->time_since_last_eaten))
			display_message(philo->philo_id, "is thinking");
	}
	return (NULL);
}
