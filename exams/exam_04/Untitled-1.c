#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>


void print_error(char *str)
{
	int size = 0;
	if (!str)
		return ;
	while (str[size])
		size++;
	write(2, str, size);
}

void execute_command(char **command, char **env, int *to_pipe)
{
	int pid;

	if ((pid = fork()) == -1)
	{
		print_error("Error: fatal\n");
		exit(1);
	}
	if (!pid) // Child process
	{
		if (to_pipe)
			dup2(to_pipe[1], 1);
		if(execve(*command, command, env) == -1)
		{
			print_error("Error: cannot execute command ");
			print_error(*command);
			print_error("\n");
		}
		if (to_pipe)
		{
			close(to_pipe[0]);
			close(to_pipe[1]);
		}
		exit(0);
	}
	else
		waitpid(pid, 0, 0);
}

void execute_pipe_command(char **command, char **env)
{
	int pipe_fd[2];

	if (pipe(pipe_fd) == -1)
	{
		print_error("Error: fatal\n");
		exit(1);
	}
	execute_command(command, env, pipe_fd);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
}

void cd(char **command)
{
	if (!command[0] || command[1])
		print_error("error: cd: bad arguments\n");
	if (chdir(*command) == -1)
	{
		print_error("error: cd: cannot change directory to ");
		print_error(*command);
		print_error("\n");
	}
}

int main (int to_end, char **argv, char ** env)
{
	int std_in_cp;
	char **command;

	std_in_cp = dup(0);

	to_end = 0;
	argv++;
	while (*argv)
	{
		command = argv;
		while (*argv && strcmp(*argv, "|") && strcmp(*argv, ";"))
			argv++;
		if (strcmp(*command, ";"))
		{

			if (*argv && !strcmp(*command, "cd"))
			{
				*argv = 0;
				cd(command);
			}
			else if (*argv && !strcmp(*argv, "|"))
			{
				*argv = 0;
				execute_pipe_command(command, env);
			}
			else
			{
				if (!*argv)
					to_end = 1;
				*argv = 0;
				execute_command(command, env,  0);
				dup2(std_in_cp, 0);
				if (to_end)
					break;
			}
		}
		argv++;
	}
	return (0);
}