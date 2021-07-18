#include "philosophers.h"

t_bool	should_die(int time_since_last_eaten, int starvation_time)
{
	int current_time;

	current_time = get_current_timestamp();
	if (current_time - time_since_last_eaten >= starvation_time)
		return (true);
	return(false);

}

t_bool eat(t_philo *philo)
{
		while (!philo->left_fork && !philo->right_fork)
		{
			if (should_die(philo->time_since_last_eaten, g_philo_common.starvation_time))
			{
				if (philo->left_fork)
					philo->left_fork = manipulate_fork(philo->philo_id, philo->left_table_fork, philo->left_fork_mutex, false);
				if (philo->right_fork)
					philo->right_fork = manipulate_fork(philo->philo_id, philo->right_table_fork, philo->right_fork_mutex, false);
				set_end_condition(philo->philo_id, true);
				return(true);
			}
			if (!philo->right_fork)
				philo->right_fork = manipulate_fork(philo->philo_id, philo->right_table_fork, philo->right_fork_mutex, true);
			if (!philo->left_fork)
				philo->left_fork = manipulate_fork(philo->philo_id, philo->left_table_fork, philo->left_fork_mutex, true);
		}
		display_message(philo->philo_id, "is eating");
		if (philo->eat_amount)
		{
			philo->eat_amount--;
			if (philo->eat_amount == 0)
				set_end_condition(philo->philo_id + 1, false);
		}
		usleep(g_philo_common.eat_time * 1000);
		philo->time_since_last_eaten = get_current_timestamp();
		philo->left_fork = manipulate_fork(philo->philo_id, philo->left_table_fork, philo->left_fork_mutex, false);
		philo->right_fork = manipulate_fork(philo->philo_id, philo->right_table_fork, philo->right_fork_mutex, false);
		return (false);
}

void	philo_sleep(int philo_id) //TODO: What if he dies during the process?
{
		display_message(philo_id, "is sleeping");
		usleep(g_philo_common.sleep_time * 1000);
		display_message(philo_id, "is thinking");
}

void	*live(void *arg)
{
	t_philo *philo;
	t_bool	starved;

	philo = (t_philo *)arg;
	philo->time_since_last_eaten = get_current_timestamp();
	display_message(philo->philo_id, "is thinking");
	while (true)
	{
		starved = eat(philo);
		if (starved)
			return (NULL);
		philo_sleep(philo->philo_id);
	}
	return (NULL);
}
