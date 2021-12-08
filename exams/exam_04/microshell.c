#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

//Good old ft_strlen
int	ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

void	print_error(char *s)
{
	write(STDERR_FILENO, s, ft_strlen(s));
}

void	fatal_error()
{
	print_error("error: fatal\n");
	exit(EXIT_FAILURE);
}

void execute_command(char **command, char **env, int *pipe_fd) //pipe
{
	int pid;

	if ((pid = fork()) == -1)
		fatal_error();
	if (pid == 0)
	{
		if (pipe_fd)
			dup2(pipe_fd[1], 1);
		if (execve(command[0], command, env) == -1)
		{
			print_error("error: cannot execute ");
			print_error(command[0]);
			print_error("\n");
		}
		if (pipe_fd) //He doesn't seem to check if pipe?
		{
			close(pipe_fd[0]);
			close(pipe_fd[1]);
		}
		//Close
		exit(0);
	}
	else
		waitpid(pid, NULL, 0);
}

void execute_pipe_command(char **argv, char **command, char **env) //Check pipe error?
{
	int pipe_fd[2];

	*argv = 0;
	if (pipe(pipe_fd) == -1) //Hmmm intensifies
		fatal_error();
	execute_command(command, env, pipe_fd);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
}

void cd(char **command, char **argv)
{
	*argv = NULL;
	if (!command[0] || command[1])
		print_error("error: cd: bad arguments\n");
	if (chdir(command[0]) == -1)
	{
		print_error("error: cd: cannot change directory to ");
		print_error(command[0]);
		print_error("\n");
	}
}

int main (int argc, char **argv, char **env)
{
	char **command;
	int io_copy;
	int final_command;

	final_command = 0;
	argc++;
	io_copy = dup(0);
	argv++;
	while (*argv)
	{
		command = argv;
		while (*argv && strcmp(*argv, "|") && strcmp(*argv, ";"))
			argv++;
		if (strcmp(*command, ";"))
		{
			if (!strcmp(*command, "cd"))
				cd(command + 1, argv);
			else if (*argv && !strcmp(*argv, "|"))
				execute_pipe_command(argv, command, env);
			else
			{
				if (!*argv)
					final_command = 1;
				*argv = 0;
				execute_command(command, env, 0);
				dup2(io_copy, 0);
				if (final_command)
					break;
			}
		}
		argv++;
	}
	close(io_copy);
	return (0);
}
