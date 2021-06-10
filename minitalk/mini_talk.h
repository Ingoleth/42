#ifndef MINI_TALK_H
# define MINI_TALK_H

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/time.h>

typedef	struct s_mini_talk
{
	int			chr;
	int			current_byte;
	long int	connected_client;
	long int	signaling_client;
	t_list		*clients_on_hold;
	int			signal;
	char		str[1000];
	int			index;
}				t_mini_talk;

void	connect_to_client(int sig, siginfo_t *siginfo, void *context);

t_mini_talk	g_mini_talk;

#endif