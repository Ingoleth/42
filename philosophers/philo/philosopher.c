#include "philosophers.h"

t_bool	should_die(int time_since_last_eaten, int starvation_time)
{
	int	current_time;

	current_time = get_current_timestamp();
	if (current_time - time_since_last_eaten >= starvation_time)
		return (true);
	return (false);
}

t_bool	get_forks_or_die(t_philo *philo)
{
	while (!(philo->left_fork && philo->right_fork))
	{
		if (should_die(philo->time_since_last_eaten,
				g_philo_common.starvation_time))
		{
			if (philo->left_fork)
				leave_fork(philo, false);
			if (philo->right_fork)
				leave_fork(philo, true);
			set_end_condition(philo->philo_id, true);
			return (true);
		}
		if (!philo->right_fork)
			take_fork(philo, true);
		if (!philo->left_fork)
			take_fork(philo, false);
	}
	return (false);
}

t_bool	eat(t_philo *philo)
{
	if (get_forks_or_die(philo))
		return (true);
	display_message(philo->philo_id, "is eating");
	if (philo->eat_amount)
	{
		philo->eat_amount--;
		if (philo->eat_amount == 0)
			set_end_condition(philo->philo_id, false);
	}
	usleep(g_philo_common.eat_time * 1000);
	philo->time_since_last_eaten = get_current_timestamp();
	leave_fork(philo, true);
	leave_fork(philo, false);
	return (false);
}

/*
**  //TODO: What if he dies during the process?
*/

void	philo_sleep(t_philo *philo)
{
	int	time;

	time = get_current_timestamp() - philo->time_since_last_eaten;
	if (time + g_philo_common.sleep_time >= g_philo_common.starvation_time)
	{
		display_message(philo->philo_id, "is sleeping");
		usleep((g_philo_common.starvation_time - time) * 1000);
	}
	else
	{
		display_message(philo->philo_id, "is sleeping");
		usleep(g_philo_common.sleep_time * 1000);
		display_message(philo->philo_id, "is thinking");
	}
}

void	*live(void *arg)
{
	t_philo	*philo;
	t_bool	starved;

	philo = (t_philo *)arg;
	philo->time_since_last_eaten = get_current_timestamp();
	display_message(philo->philo_id, "is thinking");
	while (true)
	{
		starved = eat(philo);
		if (starved)
			return (NULL);
		philo_sleep(philo);
	}
	return (NULL);
}
