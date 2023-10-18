#include "main.h"

/**
 * main - entry point of the program
 * @argc: number of arguments passed
 * @argv: vecotr of arguments passed
 * Return: integer
*/
int main(int argc, char **argv)
{
	char *prompt = "fmash:~$ ";
	char *gpath;
	int i, k, j;

	if (argc == 2)
	{
		k = open(argv[1], O_RDONLY);
		if (k == -1)
		{
			perror(argv[1]);
			exit(1);
		}
	}
	while (1)
	{
		if (isatty(STDIN_FILENO))
			print_str(prompt);
		argv = read_tok_input();
		j = exec_command(argv);
		if (j == 1)
			continue;
		gpath = get_path_com(argv[0]);
		implement_exec(gpath, argv);
		for (i = 0; argv[i] != NULL; i++)
			free(argv[i]);
		free(argv);
	}
	return (1);
}
