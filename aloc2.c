#include "shell.h"

/**
 * ffree - frees a string of strings
 * @pp: string of strings
 */
void ffree(char **pp)
{
	char **aba;
       
	aba = pp;
	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(aba);
}
