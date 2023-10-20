#include <stdio.h>
#include "shell.h"

/**
 * custom_strlen- This function counts the length of a string
 * @str : Character str
 * Return: length
 */

size_t custom_strlen(char *str)
{
	int length;

	length = 0;
	while (str[length] != '\0')
	{
	length++;
	}
	return (length);
}
