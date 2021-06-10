/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 20:26:45 by aiglesia          #+#    #+#             */
/*   Updated: 2021/06/10 12:26:26 by aiglesia         ###   ########.fr       */
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
	t_list *aux;

	kill(g_mini_talk.connected_client, SIGUSR1);
	g_mini_talk.connected_client = 0;
	g_mini_talk.index = 0;
	g_mini_talk.signal = 0;
	printf("%s\n", g_mini_talk.str);
	if (g_mini_talk.clients_on_hold)
	{
		aux = g_mini_talk.clients_on_hold;
		g_mini_talk.clients_on_hold = g_mini_talk.clients_on_hold->next;
		ft_lstdelone(aux, 0);
		g_mini_talk.connected_client = (long int)aux->content;
	}
}

void	receive_transmission()
{
	if (g_mini_talk.signal == SIGUSR1)
		g_mini_talk.chr |= 1UL << g_mini_talk.current_byte;
	else if (g_mini_talk.signal == SIGUSR2)
		g_mini_talk.chr &= ~(1UL << g_mini_talk.current_byte);
	if ((g_mini_talk.current_byte == 0))
	{
		if (g_mini_talk.chr == '\0')
			reset_transmission();
		else
		{
			g_mini_talk.str[g_mini_talk.index] = g_mini_talk.chr;
			g_mini_talk.index++;
		}
		g_mini_talk.current_byte = 7;
	}
	else
		g_mini_talk.current_byte--;
}

void	sig_handler_1(int sig, siginfo_t *siginfo, void *context)
{
	g_mini_talk.signal = sig;
	g_mini_talk.signaling_client = siginfo->si_pid;
	context++;
}

void	sig_handler_2(int sig, siginfo_t *siginfo, void *context)
{
	g_mini_talk.signal = sig;
	g_mini_talk.signaling_client = siginfo->si_pid;
	context++;
}

int	main (void)
{
	ft_memset(&g_mini_talk, 0, sizeof(t_mini_talk));
	set_sig_handler_function(SIGUSR1, sig_handler_1);
	set_sig_handler_function(SIGUSR2, sig_handler_2);
	g_mini_talk.current_byte = 7;
	printf("%i\n", getpid());
	while (true)
	{
		pause();
		if (g_mini_talk.connected_client == 0)
			g_mini_talk.connected_client = g_mini_talk.signaling_client;
		else
		{
			if (g_mini_talk.connected_client != g_mini_talk.signaling_client)
				ft_lstadd_back(&g_mini_talk.clients_on_hold, ft_lstnew((void *)(g_mini_talk.signaling_client)));
			else
				receive_transmission();
		}
		usleep(10);
		kill(g_mini_talk.connected_client, SIGUSR1);
	}
}
