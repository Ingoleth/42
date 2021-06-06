/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 20:26:45 by aiglesia          #+#    #+#             */
/*   Updated: 2021/06/06 12:30:09 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	set_sig_handler_function(int signal,
	void (*handler)(int, siginfo_t *, void *))
{
	struct sigaction sa_1;

	ft_memset(&sa_1, 0, sizeof(sa_1));
	sa_1.sa_flags = SA_SIGINFO;
	sa_1.sa_sigaction = handler;
	sigaction(signal, &sa_1, NULL);
}

void	reset_transmission()
{
	set_sig_handler_function(SIGUSR1, &connect_to_client);
	g_mini_talk.connected_client = 0;
	g_mini_talk.current_byte = 7;
	g_mini_talk.index = 0;
	printf("%s\n", g_mini_talk.str);
}

void	receive_transmission(int sig, siginfo_t *siginfo, void *context)
{
	context++;
	if (siginfo->si_pid != g_mini_talk.connected_client)
		ft_lstadd_back(&g_mini_talk.clients_on_hold,
			ft_lstnew((void *)((long int)siginfo->si_pid)));
	else
	{
		//printf("Transmission started!\n");
		if (sig == SIGUSR1)
			g_mini_talk.chr |= 1UL << g_mini_talk.current_byte;
		else if (sig == SIGUSR2)
			g_mini_talk.chr &= ~(1UL << g_mini_talk.current_byte);
		if ((g_mini_talk.current_byte == 0))
		{
			if (g_mini_talk.chr == '\0')
				reset_transmission();
			else
			{
				g_mini_talk.str[g_mini_talk.index] = g_mini_talk.chr;
				g_mini_talk.index++;
				g_mini_talk.current_byte = 7;
			}
		}
		else
			g_mini_talk.current_byte--;
		usleep(125);
		kill(siginfo->si_pid, SIGUSR1);
	}
}

void	connect_to_client(int sig, siginfo_t *siginfo, void *context)
{
	sig++;
	context++;

	if (g_mini_talk.connected_client)
		return ;
	set_sig_handler_function(SIGUSR1, receive_transmission);
	g_mini_talk.connected_client = siginfo->si_pid;
	g_mini_talk.current_byte = 7;
	write(STDOUT_FILENO, "Pong!\n", 6);
	usleep(125);
	kill(g_mini_talk.connected_client, SIGUSR1);
}

int	main (void)
{
	int	pid;
	t_list *aux;

	ft_memset(&g_mini_talk, 0, sizeof(t_mini_talk));
	set_sig_handler_function(SIGUSR1, connect_to_client);
	set_sig_handler_function(SIGUSR2, receive_transmission);

	pid = getpid();
	printf("%i\n", pid);
	while (true)
	{
		//printf("I am in a loop!\n");
		if (g_mini_talk.clients_on_hold) //Technically, it should block signals till its done;
		{
			g_mini_talk.connected_client = (long int)g_mini_talk.clients_on_hold->content;
			set_sig_handler_function(SIGUSR1, receive_transmission);
			aux = g_mini_talk.clients_on_hold;
			g_mini_talk.clients_on_hold = g_mini_talk.clients_on_hold->next;
			free(aux);
			kill(g_mini_talk.connected_client, SIGUSR1);
		}
		pause();
	}
}
