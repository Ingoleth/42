#include <wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void print_error(char *str)
{
	int i = 0;
	if (!str)
		return ;
	while (str[i])
		i++;
	write(2, str, i);
}

void cd(char **command)
{
	if (!command[0] || command[1])
	{
		print_error("error: cd: invalid arguments\n");
		return ;
	}
	if (chdir(*command) == -1)
	{
		print_error("error: cd: cannot change directory to ");
		print_error(*command);
		print_error("\n");
	}
}

void	execute_command(char **command, char **env, int *to_pipe)
{
	int pid;

	if ((pid = fork()) == -1)
	{
		print_error("error: fatal\n");
		exit(1);
	}
	if (pid == 0)
	{
		if (to_pipe)
			dup2(to_pipe[1], 1);
		if (execve(*command, command, env) == -1)
		{
			print_error("error: cannnot execute ");
			print_error(*command);
			print_error("\n");
		}
		if (to_pipe)
		{
			close(to_pipe[0]);
			close(to_pipe[1]);
		}
		exit (0);
	}
	else 
		waitpid(pid, NULL, 0);
}

void	execute_pipe_command(char **command, char **env)
{
	int pipe_fd[2];

	if (pipe(pipe_fd) == -1)
	{
		print_error("error: fatal\n");
		exit(1);
	}
	execute_command(command, env, pipe_fd);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
}

int main (int to_end, char **argv, char **env)
{
	char **commands;
	to_end = 0;
	int stdin_cp = dup(0);
	argv++;

	while(*argv)
	{
		commands = argv;
		print_error("-");
		print_error(commands[0]);
		print_error("\n");
		while(*argv && strcmp(*argv, ";") && strcmp(*argv, "|"))
			argv++;
		if (strcmp(*commands, ";"))
		{
			if (!strcmp(*commands, "cd"))
			{
				if (!*argv)
					to_end = 1;
				*argv = NULL;
				cd(commands + 1);
				if (to_end)
					break;
			}
			else if (*argv && !strcmp(*argv, "|"))
			{
				*argv = NULL;
				execute_pipe_command(commands, env);
			}
			else
			{
				if (!*argv)
					to_end = 1;
				*argv = NULL;
				execute_command(commands, env, 0);
				dup2(stdin_cp, 0);
				if (to_end)
					break;
			}
		}
		argv++;
	}
	return (0);
}