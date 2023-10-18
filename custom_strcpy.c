#include <stdio.h>
#include "main.h"

/**
 * custom_strcpy- This function coies one string into another
 * @destination: Character destination
 * @source: Character source
 * Return: destination
 */

char *custom_strcpy(char *destination, char *source)
{
	int index;

	index = 0;
	while (source[index] != '\0')
		{
		destination[index] = source[index];
			 index++;
		}
	destination[index] = '\0';
	return (destination);
}
