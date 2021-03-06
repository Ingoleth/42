/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 20:26:45 by aiglesia          #+#    #+#             */
/*   Updated: 2021/06/10 12:17:52 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	send_char(unsigned char chr, int server_pid)
{
	int current_byte;

	current_byte = 7;
	while (0 <= current_byte)
	{
		usleep(15);
		if (chr & (1 << current_byte))
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		pause();
		current_byte--;
	}
}

void	transmission(char *str, int server_pid)
{
	int str_length;
	int i;

	str_length = ft_strlen(str);
	i = 0;
	while (i <= str_length)
	{
		send_char(str[i], server_pid);
		i++;
	}
}

void placeholder()
{
	//write(STDOUT_FILENO, "Hello\n", 6);
}

int	main (int argc, char **argv)
{
	int	server_pid;

	if (argc != 3)
	{
		printf("Not enough arguments!\n");
		return (-1);
	}
	server_pid = ft_atoi(argv[1]);
	if (kill(server_pid, -0) == -1)
	{
		printf("Erroneous server pid!\n");
		return (-1);
	}
	signal(SIGUSR1, placeholder);
	kill(server_pid, SIGUSR1);
	pause();
	transmission(argv[2], server_pid);
}
