#include "main.h"
/**
 * f_exit - fun to exit
 * @args: array of pointers to char
 * Return: nothing
*/
void f_exit(char **args)
{
	int i;

	for (i = 0; args[i] != NULL; i++)
		free(args[i]);
	free(args);
	exit(EXIT_SUCCESS);
}

/**
 * f_env - sun to execute env
 * @args: array of pointers to char
 * Return: nothing;
*/
void f_env(char **args)
{
	int j, c = 0;

	while (environ[c])
	{
		print_str(environ[c]);
		print_str("\n");
		c++;
	}
	for (j = 0; args[j] != NULL; j++)
		free(args[j]);
	free(args);
}

/**
 * exec_command - function that execute the command received
 * @argv: array of pointers
 * Return: pointer to char
*/

int exec_command(char **argv)
{
	builtin built_h[] = {
		{"exit", &f_exit},
		{"env", &f_env},
		{NULL, NULL},
	};
		if (_strcmp(argv[0], built_h[0].name) == 0)
			f_exit(argv);
		else if (_strcmp(argv[0], built_h[1].name) == 0)
		{
			f_env(argv);
			return (1);
		}
		return (0);
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
				perror(command);
			}
			exit(EXIT_FAILURE);
		} else if (child_pid < 0)
			perror(command);
		else
			wait(NULL);
	}
	return (1);
}
