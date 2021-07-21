#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_philo
{
	int				eat_amount;
	int				philo_id;
	long			time_since_last_eaten;
	t_bool			right_fork;
	t_bool			left_fork;
	t_bool			*right_table_fork;
	t_bool			*left_table_fork;
	pthread_mutex_t	*left_fork_mutex;
	pthread_mutex_t	*right_fork_mutex;
}	t_philo;

typedef struct s_philo_common
{
	t_philo			**structs;
	pthread_mutex_t	**mutexes;
	pthread_t		*threads;
	t_bool			*forks;
	long			start_time;
	int				philosophers;
	int				eat_time;
	int				eat_amount;
	int				sleep_time;
	int				starvation_time;
	t_bool			*end_condition;
	pthread_mutex_t	*communication;
	pthread_mutex_t	*end_condition_mutex;
}	t_philo_common;

t_philo_common	g_philo_common;

long	get_current_timestamp(void);
t_bool	check_number(int *nbr, char *str, t_bool check_zero);
void	leave_fork(t_philo *philo, t_bool right_fork);
void	take_fork(t_philo *philo, t_bool right_fork);
void	set_end_condition(int philo_id, t_bool he_dead);
int		init_data(int size);
int		free_memory(int return_value);
void	*live(void *arg);
void	display_message(int philo_id, char *message);
void	print_philosopher_info(t_philo *philo);

#endif // PHILOSOPHERS_H
