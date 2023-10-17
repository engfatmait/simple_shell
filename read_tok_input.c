#include "main.h"
/**
 * read_tok_input - function to read input from user
 * Return: number of characters read
*/
char **read_tok_input(void)
{
	char *ptr = NULL;
	size_t size = 0;
	ssize_t num_char;
	char *cptr, *token;
	unsigned int num_tok = 0, j = 0;
	char delim[2] = " \t\n";
	char **ptr_tok;

	num_char = getline(&ptr, &size, stdin);
	if (num_char == -1)
	{
		free(ptr);
		exit(EXIT_SUCCESS);
	}
	cptr = malloc(sizeof(char) * (num_char + 1));
	_strcpy(cptr, ptr);
	token = strtok(ptr, delim);
	while (token != NULL)
	{
		num_tok++;
		token = strtok(NULL, delim);
	}
	ptr_tok = malloc(sizeof(char *) * (num_tok + 1));
	if (ptr_tok == NULL)
	{
		print_str("allocation failure");
		exit(EXIT_FAILURE);
	}
	token = strtok(cptr, delim);
	for (j = 0; j < num_tok; j++)
	{
		ptr_tok[j] = malloc(sizeof(char) * (_strlen(token) + 1));
		_strcpy(ptr_tok[j], token);
		token = strtok(NULL, delim);
	}
	ptr_tok[j] = NULL;
	free(ptr);
	free(cptr);
	return (ptr_tok);
}
