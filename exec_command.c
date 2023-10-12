#include "main.h"
/**
 * f_exit - fun to exit
 * @args: pointer to char
 * Return: nothing
*/
void f_exit(char *args __attribute__((unused)))
{
	exit(0);
}

/**
 * exec_command - function that execute the command received
 * @argv: array of pointers
 * Return: pointer to char
*/

void exec_command(char **argv)
{
	alias alias_h[] = {
		{"ls", "ls - color=auto"},
		{"ll", "ls -alf"},
		{"la", "ls -A"},
		{NULL, NULL},
	};
	int i = 0;
	builtin built_h[] = {
		{"exit", &f_exit},
		{NULL, NULL},
	};

	while (alias_h[i].alias_name != NULL)
	{
		if (_strcmp(argv[0], alias_h[i].alias_name) == 0)
			implement_exec(alias_h[i].real_name, argv);
		i++;
	}
	while (built_h[i].name != NULL)
	{
		if (_strcmp(argv[0], built_h[i].name) == 0)
			f_exit(EXIT_SUCCESS);
		i++;
	}
}
/**
 * implement_exec - function to execute command
 * @command: input command after exchange
 * @argv: input vector of arguments
 * Return: an integer
*/

int implement_exec(char *command, char **argv)
{
	pid_t child_pid;

	if (argv[0] == NULL)
		perror("no command");
	else
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			if (execve(command, argv, environ) == -1)
			{
				perror("fmash");
			}
			exit(EXIT_FAILURE);
		} else if (child_pid < 0)
			perror("fmash");
		else
			wait(NULL);
	}
	return (1);
}
