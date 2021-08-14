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

t_bool	should_die(int time_since_last_eaten, int starvation_time)
{
	long	current_time;

	current_time = get_current_timestamp();
	if (current_time - time_since_last_eaten >= starvation_time)
		return (true);
	return (false);
}

t_bool	get_forks_or_die(t_philo *philo)
{
	while (!(philo->left_fork && philo->right_fork))
	{
		if (should_die(philo->time_since_last_eaten, g_philo_common.starvation_time))
		{
			if (philo->left_fork && philo->right_fork)
				leave_forks(philo);
			set_end_condition(philo->philo_id, true);
			return (true);
		}
		get_forks(philo);
	}
	return (false);
}

t_bool	eat(t_philo *philo)
{
	if (get_forks_or_die(philo))
		return (false);
	display_message(philo->philo_id, "is eating");
	if (philo->eat_amount)
	{
		philo->eat_amount--;
		if (philo->eat_amount == 0)
			set_end_condition(philo->philo_id, false);
	}
	philo->time_since_last_eaten = get_current_timestamp();
	smart_sleep(g_philo_common.eat_time, philo->time_since_last_eaten);
	leave_forks(philo);
	return (true);
}

void	*live(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->time_since_last_eaten = get_current_timestamp();
	display_message(philo->philo_id, "is thinking");
	while (true)
	{
		if (!eat(philo))
			return (NULL);
		display_message(philo->philo_id, "is sleeping");
		if (smart_sleep(g_philo_common.sleep_time, philo->time_since_last_eaten))
			display_message(philo->philo_id, "is thinking");
	}
	return (NULL);
}
