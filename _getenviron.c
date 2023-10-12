#include "main.h"

/**
 * env_com - compare name with environ
 * @name: name passed
 * @nenv: name of environment variable
 * Return: an integer
**/
int env_com(char *name, char *nenv)
{
	int i;

	for (i = 0; nenv[i] != '='; i++)
	{
		if (name[i] != nenv[i])
			return (0);
	}
	return (i + 1);
}

/**
 * _getenviron - gets the environment variable
 * @name: name of enviroment variable to search
 * Return: the value of the environment variable
*/
char *_getenviron(char *name)
{
	char *ptr_env;
	int i = 0, j = 0;

	while (environ != NULL)
	{
		j = env_com(name, environ[i]);
		if (j)
		{
			ptr_env = environ[i];
			break;
		}
	i++;
	}
	return (ptr_env);

}
