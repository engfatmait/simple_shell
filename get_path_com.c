#include "main.h"
/**
 * get_path_com - returns the path of given command
 * @command: input command
 * Return: the path of command
*/

char *get_path_com(char *command)
{
	char *ppath, *path, *path_tok, *tot_path;
	int com_len, dir_len;
	struct stat buf;

	path = _getenviron("PATH");

	if (path)
	{
		ppath = _strdup(path);
		com_len = _strlen(command);
		path_tok = strtok(ppath, ":");
		while (path_tok != NULL)
		{
			dir_len = _strlen(path_tok);
			tot_path = malloc(com_len + dir_len + 2);
			_strcpy(tot_path, path_tok);
			_strcat(tot_path, "/");
			_strcat(tot_path, command);
			_strcat(tot_path, "\0");

			if (stat(tot_path, &buf) == 0)
			{
				free(ppath);
				return (tot_path);
			}
			else
			{
				free(tot_path);
				path_tok = strtok(NULL, ":");
			}
		}
		free(ppath);
	if (stat(command, &buf) == 0)
		return (command);
	}
	return (NULL);
}
