#include "main.h"
/**
 * _strlen - return length of string
 * @s: input string
 * Return: an integer
*/
unsigned int _strlen(char *s)
{
	unsigned int i = 0;

	while (*(s + i) != '\0')
		i++;
	return (i);
}
