#include "main.h"
/**
 * print_str - function to print string
 * @str: pointer to input string
 * Return: number of bytes
*/
int print_str(char *str)
{
	return (write(1, str, _strlen(str)));
}
