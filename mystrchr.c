#include "shell.h"
#include <stdio.h>

/**
 * _strchr - locates character
 * @s: character pointer s
 *@c: character c
 *Return: s
 */

char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
