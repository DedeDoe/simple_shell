#include "shell.h"

/**
 * ffree- This function frees a string of strings
 * @pp: character pp
 * Return: aba
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
