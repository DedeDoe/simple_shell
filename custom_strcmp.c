#include <stdio.h>
#include "main.h"

/**
 * custom_strcmp- This function compares 2 strings
 * @stra : Character stra
 * @strb : Character strb
 * Return: stra - strb
 */

int custom_strcmp(char *stra, char *strb)
{
	while (*stra != '\0' && *strb != '\0')
	{
	if (*stra != *strb)
		{
	return (*stra - *strb);
	}
	stra++;
	strb++;
	}

	return (*stra - *strb);
}
