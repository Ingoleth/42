#include <string.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>

void print_error(char *str)
{
	if (!str)
		return ;
	int i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

void cd(char **command)
{
	if (!*command || command[1])
	{
		print_error("error: cd: invalid arguments\n");
	}
	else if (chdir(*command) == -1)
	{
		print_error("error: can not change dir to ");
		print_error(*command);
		print_error("\n");
	}
}

void execute_command(char **command, char **env, int *to_pipe)
{
	int pid;

	if ((pid = fork()) == -1)
	{
		print_error("error: fatal\n");
		exit(1);
	}
	else if (pid == 0)
	{
		if (to_pipe)
			dup2(to_pipe[1], 1);
		if (execve(*command, command, env) == -1)
		{
			print_error("error: can not execute ");
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
		waitpid(pid, 0, 0);
}

void execute_pipe_command(char **command, char **env)
{
	int pipe_fd[2];

	if (pipe(pipe_fd) == -1)
	{
		print_error("error: fatal\n");
		exit (1);
	}
	execute_command(command, env, pipe_fd);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
}

int main(int to_end, char **argv, char **env)
{
	char **command;
	int stdin_cp = dup(0);
	to_end = 0;
	argv++;

	while (*argv)
	{
		command = argv;
		while(*argv && strcmp(*argv, "|") && strcmp(*argv, ";"))
			argv++;
		if (strcmp(*command, ";"))
		{
			if (!strcmp(*command, "cd"))
			{
				if (!*argv)
					to_end = 1;
				else 
					*argv = NULL;
				cd(command + 1);
				if (to_end)
					break;
			}
			else if (*argv && !strcmp(*argv, "|"))
			{
				*argv = NULL;
				execute_pipe_command(command, env);
			}
			else
			{
				if (!*argv)
					to_end = 1;
				*argv = NULL;
				execute_command(command, argv, 0);
				dup2(stdin_cp, 0);
				if (to_end)
					break;
			}
		}
		argv++;
	}
	close(stdin_cp);
}