#include "philosophers.h"

t_bool	get_input(char **argv)
{
	memset(&g_philo_common, 0, sizeof(t_philo_common));
	if (!check_number(&g_philo_common.philosophers, argv[1], true))
		return (true);
	if (!check_number(&g_philo_common.starvation_time, argv[2], true))
		return (true);
	if (!check_number(&g_philo_common.eat_time, argv[3], true))
		return (true);
	if (!check_number(&g_philo_common.sleep_time, argv[4], true))
		return (true);
	if (argv[5] && !check_number(&g_philo_common.eat_amount, argv[5], false))
		return (true);
	return (false);
}

t_bool	check_end_condition(void)
{
	int		i;
	t_bool	ret;
	t_bool	done;

	done = false;
	ret = true;
	pthread_mutex_lock(g_philo_common.end_condition_mutex);
	if (g_philo_common.end_condition[0])
		done = true;
	i = 1;
	if (g_philo_common.eat_amount)
	{
		while (!done && i <= g_philo_common.philosophers)
		{
			if (!g_philo_common.end_condition[i])
			{
				ret = false;
				done = true;
			}
			i++;
		}
	}
	pthread_mutex_unlock(g_philo_common.end_condition_mutex);
	return (ret);
}

int	free_memory(int return_value)
{
	int	i;

	if (g_philo_common.forks)
		free(g_philo_common.forks);
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
		g_philo_common.mutexes = NULL;
	}
	if (g_philo_common.end_condition)
		free(g_philo_common.end_condition);
	return (return_value);
}

/*
**	//Might need to set the threads to 0? //TODO: Check seg fault
**	//free_memory(0);
*/
void	kill_threads(void)
{
	int	i;

	i = 0;
	while (i < g_philo_common.philosophers)
	{
		pthread_detach(g_philo_common.threads[i]);
		i++;
	}
	exit(0);
}

/*
** Cada programa debe aceptar el mismo número de opciones:
** 
** - número_de_filósofos: es el número de filósfos y también el
**	número de tenedores.
** 
** - tiempo_para_morir:  en milisegundos, si un filósofo no empieza
**	a comer tiempo_para_morir milisegundos después de su última
**	comida o de la simulación, muere.
** 
** - tiempo_para_comer: en milisegundos, el tiempo que usa cada
**	filósofo para comer. Durante ese tiempo usará dos tenedores.
** 
** - tiempo_para _dormir: en milisegundos, el tiempo que un filósofo
**	pasa durmiendo.
** 
** -número_de_veces_que_cada_filósofo_debe_comer: este argumento es
**	opcional, si todos los filósofos comen al menos
** “número_de_veces_que_cada_filósofo_debe_comer” la simulación 
**	terminará. Si no se especifica, la simulación terminará solo
**	tras la muerte de un filósofo.
** 
*/

int	main(int argc, char const *argv[])
{
	if (argc < 5 || argc > 6)
		return (-1);
	if (get_input((char **)argv))
		return (-1);
	if (init_data(g_philo_common.philosophers))
		return (-1);
	while (true)
	{
		if (check_end_condition())
			kill_threads();
	}
	return (0);
}
