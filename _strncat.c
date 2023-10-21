#include "shell.h"
#include <stdio.h>

/**
 *_strncat- puts 2 two strings together
 *@dest: character dest
 *@src: character source
 *@n: int n
 *Return: s
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}
