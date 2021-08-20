#include "philosophers.h"

t_bool	init_mutexes(int size)
{
	int	i;
	int	error;

	i = 0;
	size += 2;
	g_philo_common.mutexes = malloc((size + 1) * sizeof(pthread_mutex_t *));
	if (!g_philo_common.mutexes)
		return (false);
	memset(g_philo_common.mutexes, 0, sizeof(pthread_mutex_t *) * (size + 1));
	while (i < size)
	{
		g_philo_common.mutexes[i] = malloc(sizeof(pthread_mutex_t));
		if (!g_philo_common.mutexes[i])
			return (false);
		error = pthread_mutex_init(g_philo_common.mutexes[i], NULL);
		if (error)
			return (false);
		i++;
	}
	g_philo_common.communication = g_philo_common.mutexes[size - 1];
	g_philo_common.end_condition_mutex = g_philo_common.mutexes[size - 2];
	return (true);
}

t_philo	*load_philosopher_data(int i, int size)
{
	t_philo	*aux;

	aux = malloc(sizeof(t_philo));
	if (aux == NULL)
		return (NULL);
	memset(aux, 0, sizeof(t_philo));
	aux->eat_amount = g_philo_common.eat_amount;
	aux->philo_id = i + 1;
	if (i == 0)
		aux->right_fork_mutex = g_philo_common.mutexes[size - 1];
	else
		aux->right_fork_mutex = g_philo_common.mutexes[i - 1];
	aux->left_fork_mutex = g_philo_common.mutexes[i];
	return (aux);
}

t_bool init_philosopher_threads(int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (!(i % 2))
		{
			if (pthread_create(&g_philo_common.threads[i], NULL, &live,
					g_philo_common.structs[i]))
				return (false);
			usleep(1000);
		}
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (i % 2)
		{
			if (pthread_create(&g_philo_common.threads[i], NULL, &live,
					g_philo_common.structs[i]))
				return (false);
		}
		i++;
	}
	return (true);
}

t_bool	init_threads(int size)
{
	int	i;

	i = -1;
	g_philo_common.threads = malloc((size + 1) * sizeof (pthread_t *));
	if (g_philo_common.threads == NULL)
		return (false);
	g_philo_common.threads[size] = 0;
	g_philo_common.structs = malloc((size + 1) * sizeof (t_philo *));
	if (g_philo_common.threads == NULL)
		return (false);
	g_philo_common.structs[size] = 0;
	while (++i < size)
	{
		g_philo_common.structs[i] = load_philosopher_data(i, size);
		if (g_philo_common.structs[i] == NULL)
			return (false);
	}
	g_philo_common.start_time = get_current_timestamp();
	return (init_philosopher_threads(size));
}

t_bool	*init_bool(int size, t_bool initial_value)
{
	t_bool	*bool;
	int		i;

	bool = malloc((size + 1) * sizeof (t_bool));
	if (bool == NULL)
		return (NULL);
	i = 0;
	if (initial_value != false)
		initial_value = true;
	while (i < size)
		bool[i++] = initial_value;
	bool[size] = 0;
	return (bool);
}

/*
** //TODO: Should probably call kill threads
** 
*/

int	init_data(int size)
{
	g_philo_common.end_condition = init_bool(size + 1, false);
	if (g_philo_common.end_condition == NULL)
		return (free_memory(-1));
	if (!init_mutexes(size))
		return (free_memory(-1));
	if (!init_threads(size))
		return (free_memory(-1));
	return (0);
}
