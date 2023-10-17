#include "main.h"
/**
 * _strcat - concatenates two strings
 * @dest: input string
 * @src: input string
 * Return: nothing
*/
void _strcat(char *dest, char *src)
{
	int count = 0, count1 = 0;

	while (dest[count] != '\0')
	{
		count++;
	}
	while (src[count1] != '\0')
	{
		dest[count] = src[count1];
		count1++;
		count++;
	}
	dest[count] = '\0';
}
