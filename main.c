#include "main.h"

/**
 * main - entry point of the program
 * @argc: number of arguments passed
 * @argv: vecotr of arguments passed
 * Return: integer
*/
int main(int argc __attribute__((unused)), char **argv)
{
	char *prompt = "fmash:~$ ";
	char *gpath;
	int i ;

	argv = NULL;

	if (isatty(STDIN_FILENO))
	while (1)
	{
		print_str(prompt);
		argv = read_tok_input();
		gpath = get_path_com(argv[0]);
		implement_exec(gpath, argv);
		for (i = 0; argv[i] != NULL; i++)
			free(argv[i]);
		free(gpath);
	}
	else
	{
	}
	return (1);
}
