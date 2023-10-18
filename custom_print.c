#include <stdio.h>
#include "main.h"

/**
 * custom_print- prints a string to the standard output
 * @string: string to be printed
 * Return - Nothing
 */

void custom_print(char *string)
{
	int i;

	i = 0;
	while (string[i] != '\0')
	{
		write(STDOUT_FILENO, &string[i], 1);
		i++;
	}
}
