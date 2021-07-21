#include "philosophers.h"

void	print_philosopher_info(t_philo *philo)
{
	pthread_mutex_lock(g_philo_common.communication);
	printf("----------\n");
	printf("Philosopher id: %i\nHas left fork:  %i\nHas right fork: %i\n", philo->philo_id, philo->left_fork, philo->right_fork);
	printf("\nLeft table fork status: %i;\nRight table fork status %i;\n", *philo->right_table_fork, *philo->left_table_fork);
	printf("----------\n");
	pthread_mutex_unlock(g_philo_common.communication);
}