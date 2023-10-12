#include "main.h"
/**
 * _strcpy - copies the string pointed to by src
 * including the null byte to the string pointed
 * to by dest
 * @dest: dstination
 * @src: source
 * Return: pointer to dest
*/
char *_strcpy(char *dest, char *src)
{
	int count = 0;

	while (count >= 0)
	{
		*(dest + count) = *(src + count);
		if (*(src + count) == '\0')
			break;
		count++;
	}
	return (dest);
}
