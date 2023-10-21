#include "shell.h"

/**
 * bfree - function frees pointer
 * @ptr: void ptr
 * Return: 1
 */
int bfree(void **ptr)
{
	if (ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
